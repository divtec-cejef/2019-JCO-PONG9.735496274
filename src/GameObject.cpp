//
// Created by marttom on 10.12.2019.
//

#include "GameObject.h"

GameObject::GameObject(float startX, float startY) {
    position.x = startX;
    position.y = startY;
}

FloatRect GameObject::getPosition() {
    return shape->getGlobalBounds();
}

RectangleShape GameObject::getShape() {
        return *shape;
};

void GameObject::setShape(float width, float height) {
    shape = new RectangleShape;
    shape->setPosition(position.x, position.y);
    shape->setSize(Vector2f{width, height});
}


