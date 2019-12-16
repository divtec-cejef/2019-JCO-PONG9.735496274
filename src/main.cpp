#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>
#include "bat.h"
#include "Ball.h"
#include <iostream>
#include <windows.h>

#include <vector>

using namespace sf;

int main()
{
    // const definition
    const float WINDOW_WIDTH = 768;
    const float WINDOW_HEIGHT = 432;
    const sf::Time TIME_TO_PLAY = sf::seconds(3);

    // variable définition
    int leftTickCounter = 599;
    int rightTickCounter = 599;

    // Make a window that is 768 by 432 pixels
    // And has the title "pong"
    RenderWindow window(VideoMode(static_cast<int>(WINDOW_WIDTH), static_cast<int>(WINDOW_HEIGHT)), "Pong");
    window.setFramerateLimit(60);

    int leftScore = 0;
    int rightScore = 0;

    // create a bat
    Bat* pLeftBat = new Bat(3, WINDOW_HEIGHT / 2);
    Bat* pRightBat = new Bat(WINDOW_WIDTH - 8, WINDOW_HEIGHT / 2);
    // create a pBall
    Ball* pBall = new Ball(WINDOW_WIDTH / 2 -5, WINDOW_HEIGHT / 2);
    // create the superpower
    RectangleShape leftPowerOut(sf::Vector2f(100, 20));
    leftPowerOut.setOutlineThickness(5);
    leftPowerOut.setOutlineColor(Color::Green);
    leftPowerOut.setFillColor(Color::Black);
    leftPowerOut.setPosition(30, 10);
    RectangleShape leftPowerIn(sf::Vector2f(0, 20));
    leftPowerIn.setPosition(30, 10);
    RectangleShape rightPowerOut(sf::Vector2f(100, 20));
    rightPowerOut.setOutlineThickness(5);
    rightPowerOut.setOutlineColor(Color::Green);
    rightPowerOut.setFillColor(Color::Black);
    rightPowerOut.setPosition(635, 10);
    RectangleShape rightPowerIn(sf::Vector2f(0, 20));
    rightPowerIn.setPosition(635, 10);
    // Create a "Text" object called "message". Weird but we will learn about objects soon
    Text leftHud;
    Text rightHud;
    // We need to choose a font
    Font font;
    // http://www.dafont.com/theme.php?cat=302
    font.loadFromFile("DS-DIGIT.TTF");
    // Set the font to our message
    leftHud.setFont(font);
    rightHud.setFont(font);
    leftHud.setCharacterSize(30);
    rightHud.setCharacterSize(30);
    // Choose a color
    leftHud.setFillColor(sf::Color::White);
    rightHud.setFillColor(sf::Color::White);

    rightHud.setPosition(WINDOW_WIDTH - 20, 0);

    std::vector <RectangleShape*> recs;

    for (int i = 0; i < 11; i++) {
        recs.push_back(new RectangleShape(sf::Vector2f(5, 20)));
        recs.at(i)->setPosition(WINDOW_WIDTH / 2 - 2.5, i * 40 + 5);
    }

    RectangleShape bigRec(sf::Vector2f(50, 50));
    bigRec.setPosition(WINDOW_WIDTH / 2, 100);

    //! draw the shape on the window
    auto draw = [&]() {
    };

    //! update the position of the shape in the window
    auto update = [&] {
    };

    //! check the keyboard event
    auto keyboardEventCheck = [&]() {
    };

    //! check the collision
    auto collisionCheck = [&] () {
    };

    // game loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        keyboardEventCheck();
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            if (pLeftBat->getPosition().top > 0) {
                pLeftBat->moveUp();
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if (pLeftBat->getPosition().top + pLeftBat->getPosition().height < WINDOW_HEIGHT) {
                pLeftBat->moveDown();
            }
        } else if (Keyboard::isKeyPressed(Keyboard::A)) {
            if (leftTickCounter >= 600) {
                leftPowerIn.setFillColor(Color::White);
                leftTickCounter = 0;
                pLeftBat->superPower(pLeftBat, pBall, WINDOW_WIDTH);
            }
        } else if (Keyboard::isKeyPressed(Keyboard::L)) {
            if (rightTickCounter >= 600) {
                rightPowerIn.setFillColor(Color::White);
                rightTickCounter = 0;
                pRightBat->superPower(pRightBat, pBall, WINDOW_WIDTH);
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::I))
        {
            if (pRightBat->getPosition().top > 0) {
                pRightBat->moveUp();
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::K))
        {
            if (pRightBat->getPosition().top + pRightBat->getPosition().height < WINDOW_HEIGHT) {
                pRightBat->moveDown();
            }
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            pBall->start();
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            window.close();
        }

        collisionCheck();
        if (
                pBall->getPosition().top < 0 ||
                pBall->getPosition().top > WINDOW_HEIGHT - 10
                ) {
            pBall->reboundWall();
        }

        // pBall hitting side right
        if (pBall->getPosition().left < 0)
        {
            leftScore += 1;
            pBall->stop();
        }
        // pBalle hitting side right
        if (pBall->getPosition().left + 10 > WINDOW_WIDTH) {
            rightScore += 1;
            pBall->stop();
        }

        // pBall hit something ?
        FloatRect pB;
        bool isBat = false;

        if (

                pBall->getPosition().intersects((pB = pLeftBat->getPosition())) ||

                pBall->getPosition().intersects((pB = pRightBat->getPosition())) ||

                pBall->getPosition().intersects((pB = bigRec.getGlobalBounds()))

                )

        {

            isBat = pB.left == 3 || pB.left == 760;

            if (pBall->getPosition().top == pB.top - 8 || pBall->getPosition().top == pB.top + pB.height - 2) {
                pBall->rebound(pBall->UP_AND_DOWN, isBat);
            } else  {
                pBall->rebound(pBall->RIGHT_AND_LEFT, isBat);
            }

        }

        update();
        pBall->update();
        pLeftBat->update();
        pRightBat->update();

        std::stringstream lss;
        std::stringstream rss;
        lss << leftScore;
        rss << rightScore;
        leftHud.setString(rss.str());
        rightHud.setString(lss.str());

        if (leftTickCounter == 600) {
            leftPowerIn.setSize(sf::Vector2f(100, 20));
            leftPowerIn.setFillColor(Color::Green);
        } else {
            leftPowerIn.setSize(sf::Vector2f(static_cast<int>(leftTickCounter / 6), 20));
            if (pBall->getXVelocity() != 0) {
                leftTickCounter++;
            }
        }

        if (rightTickCounter == 600) {
            rightPowerIn.setSize(sf::Vector2f(100, 20));
            rightPowerIn.setFillColor(Color::Green);
        } else {
            rightPowerIn.setSize(sf::Vector2f(static_cast<int>(rightTickCounter / 6), 20));
            if (pBall->getXVelocity() != 0) {
                rightTickCounter++;
            }
        }

        window.clear(Color(0, 0, 0,0));

        draw();
        window.draw(leftPowerOut);
        window.draw(leftPowerIn);
        window.draw(rightPowerOut);
        window.draw(rightPowerIn);

        window.draw(pLeftBat->getShape());
        window.draw(pRightBat->getShape());
        window.draw(pBall->getShape());

        // Draw our score
        window.draw(leftHud);
        window.draw(rightHud);

        for (RectangleShape* rec : recs) {
            window.draw(*rec);
        }

        window.draw(bigRec);

        window.display();
    }

    return 0;
}