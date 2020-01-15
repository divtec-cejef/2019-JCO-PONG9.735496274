//
// Created by marttom on 10.12.2019.
//

#include "GameObject.h"

GameObject::GameObject(float startX, float startY) {
    position.x = startX;
    position.y = startY;
}

FloatRect GameObject::getPosition() {
    return pShape->getGlobalBounds();
}

RectangleShape GameObject::getShape() {
        return *pShape;
};

void GameObject::setShape(float width, float height) {
    pShape = new RectangleShape;
    pShape->setPosition(position.x, position.y);
    pShape->setSize(Vector2f{width, height});
}


