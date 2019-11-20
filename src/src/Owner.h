//
// Created by marttom on 06.11.2019.
//

#ifndef SRC_OWNER_H
#define SRC_OWNER_H


#include <string>

class Owner {
private:
    std::string m_name = "";
    std::string m_texturePath;
public:
    Owner(std::string name, std::string texturePath);

    std::string getTexturePath();

    std::string getName();
};


#endif //SRC_OWNER_H
