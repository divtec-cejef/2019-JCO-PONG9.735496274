//
// Created by marttom on 06.11.2019.
//

#include "Owner.h"

#include <utility>

std::string Owner::getName() {
    return m_name;
}

std::string Owner::getTexturePath() {
    return m_texturePath;
}

Owner::Owner(std::string name, std::string texturePath) {
    m_name = std::move(name);
    m_texturePath = std::move(texturePath);
}
