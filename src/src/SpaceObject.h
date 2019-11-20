//
// Created by marttom on 28.10.2019.
//

#ifndef SRC_SPACEOBJECT_H
#define SRC_SPACEOBJECT_H

#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Owner.h"
#include <iostream>

class SpaceObject : public GameObject {
private:

    int m_lifePoint = 0;
    int m_maxLifePoint = 0;
    Owner* m_owner = nullptr;

public:
    // make the class abstract
    virtual void AbstractMemberFunction() = 0;

    SpaceObject(int lifePoint, float x, float y, float scale, int width);


    void setOwner (Owner* pOwner);

    Owner* getOwner() const;

    int getLifePoint ();

    void addLifePoint (int number);

    void removeLifePoint (int number);

    void setSprite (sf::Texture* &texture) {
        GameObject::setSprite(texture);
    }
};


#endif //SRC_SPACEOBJECT_H
