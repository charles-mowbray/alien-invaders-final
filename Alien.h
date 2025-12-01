//
// Created by Conce on 12/1/2020.
//
#include <SFML/Graphics.hpp>
#ifndef SFML_TEMPLATE_ALIEN_H
#define SFML_TEMPLATE_ALIEN_H

#endif //SFML_TEMPLATE_ALIEN_H
using namespace std;
using namespace sf;

class Alien:public Sprite{

public:
    float moveAlienBy;
    bool alive;
    float xPos, yPos;


    Alien(Texture &texture, IntRect rect,int xPos, int yPos);

    // Alien();

    void isDead();
    void moveAlien();

};