//
// Created by marttom on 25.10.2019.
//

#ifndef SRC_GAMEOBJECT_H
#define SRC_GAMEOBJECT_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>

//! Super classe de l'application
//! permet de positionner la forme et d'afficher le sprite
class GameObject {
private:
    float m_x = 0;
    float m_y = 0;
    float m_scale = 0;
    int m_width = 0;
    sf::Sprite* m_pSprite;
public:
    // make the class abstract
    virtual void AbstractMemberFunction() = 0;

    //! Constructor of GameObject
    //! \param x contains the abscissa coordinate
    //! \param y contains the ordinate coordinate
    //! \param scale contains the percentage of width of the sprite
    //! \param width contains the width of the sprite
    GameObject (float x, float y, float scale, int width);

    //! x position getter
    //! \return  the absissa coordinate of the center of the shape
    float getX ();

    //! x position getter
    //! \return  the ordinate coordinate of the center of the shape
    float getY();


    //! sprite getter
    //! \return  the sprite of the object
    sf::Sprite* getSprite ();

    //! sprite setter
    //! \param texture contains a pointer to the texture
    virtual void setSprite (sf::Texture* &texture);
};


#endif //SRC_GAMEOBJECT_H
