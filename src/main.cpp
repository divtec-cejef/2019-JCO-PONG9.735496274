#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>
#include "bat.h"
#include "Ball.h"
#include <iostream>

using namespace sf;

int main()
{


    float windowWidth = 768;
    float windowHeight = 432;
    int leftTickCounter = 599;
    int rightTickCounter = 599;

    const sf::Time TIME_TO_PLAY = sf::seconds(3);
    // Make a window that is 768 by 432 pixels
    // And has the title "pong"
    RenderWindow window(VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "pong");
    window.setFramerateLimit(60);

    int leftScore = 0;
    int rightScore = 0;

    // create a bat
    Bat* pLeftBat = new Bat(3, windowHeight / 2);
    Bat* pRightBat = new Bat(windowWidth - 8, windowHeight / 2);
    // create a pBall
    Ball* pBall = new Ball(windowWidth / 2, windowHeight / 2);
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

    rightHud.setPosition(windowWidth - 20, 0);

    RectangleShape rec(sf::Vector2f(5, 20));
    rec.setPosition(windowWidth / 2, 5);

    RectangleShape rec1(sf::Vector2f(5, 20));
    rec1.setPosition(windowWidth / 2, 45);

    RectangleShape rec2(sf::Vector2f(5, 20));
    rec2.setPosition(windowWidth / 2, 85);

    RectangleShape rec3(sf::Vector2f(5, 20));
    rec3.setPosition(windowWidth / 2, 125);

    RectangleShape rec4(sf::Vector2f(5, 20));
    rec4.setPosition(windowWidth / 2, 165);

    RectangleShape rec5(sf::Vector2f(5, 20));
    rec5.setPosition(windowWidth / 2, 205);

    RectangleShape rec6(sf::Vector2f(5, 20));
    rec6.setPosition(windowWidth / 2, 245);

    RectangleShape rec7(sf::Vector2f(5, 20));
    rec7.setPosition(windowWidth / 2, 285);

    RectangleShape rec8(sf::Vector2f(5, 20));
    rec8.setPosition(windowWidth / 2, 325);

    RectangleShape rec9(sf::Vector2f(5, 20));
    rec9.setPosition(windowWidth / 2, 365);

    RectangleShape rec10(sf::Vector2f(5, 20));
    rec10.setPosition(windowWidth / 2, 405);


    RectangleShape bigRec(sf::Vector2f(50, 50));
    bigRec.setPosition(windowWidth / 2, 100);

    //! draw the shape on the window
    auto draw = [&]() {
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

        window.draw(rec);
        window.draw(rec1);
        window.draw(rec2);
        window.draw(rec3);
        window.draw(rec4);
        window.draw(rec5);
        window.draw(rec6);
        window.draw(rec7);
        window.draw(rec8);
        window.draw(rec9);
        window.draw(rec10);

        window.draw(bigRec);
    };

    //! update the position of the shape in the window
    auto update = [&] {
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
    };

    //! check the keyboard event
    auto keyboardEventCheck = [&]() {
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            if (pLeftBat->getPosition().top > 0) {
                pLeftBat->moveUp();
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if (pLeftBat->getPosition().top + pLeftBat->getPosition().height < windowHeight) {
                pLeftBat->moveDown();
            }
        } else if (Keyboard::isKeyPressed(Keyboard::A)) {
            if (leftTickCounter >= 600) {
                leftPowerIn.setFillColor(Color::White);
                leftTickCounter = 0;
                pLeftBat->superPower(pLeftBat, pBall, windowWidth);
            }
        } else if (Keyboard::isKeyPressed(Keyboard::L)) {
            if (rightTickCounter >= 600) {
                rightPowerIn.setFillColor(Color::White);
                rightTickCounter = 0;
                pRightBat->superPower(pRightBat, pBall, windowWidth);
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
            if (pRightBat->getPosition().top + pRightBat->getPosition().height < windowHeight) {
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
    };

    //! check the collision
    auto collisionCheck = [&] () {
        if (
                pBall->getPosition().top < 0 ||
                pBall->getPosition().top > windowHeight - 10
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
        if (pBall->getPosition().left + 10 > windowWidth) {
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
            if (pBall->getPosition().top == pB.top - 8 || pBall->getPosition().top == pB.top + pB.height - 2) {
                pBall->rebound(pBall->UP_AND_DOWN, isBat);
            } else  {
                pBall->rebound(pBall->RIGHT_AND_LEFT, isBat);
            }
        }
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

        collisionCheck();

        update();

        window.clear(Color(0, 0, 0,0));

        draw();

        window.display();
    }

    return 0;
}