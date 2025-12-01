//
// Created by Conce on 12/2/2020.
//
#include <SFML/Graphics.hpp>

using namespace sf;
#ifndef SFML_TEMPLATE_BULLETS_H
#define SFML_TEMPLATE_BULLETS_H

#endif //SFML_TEMPLATE_BULLETS_H


class Bullet{

    //If true then hurts player but not the invaders
    //If false then vice versa
public:
    bool hurtPlayer;

    double xPos, yPos;

    Bullet(int, int);

    RectangleShape bulletDraw();
    void bulletUpdate();
};