//
// Created by Conce on 12/1/2020.
//
#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef SFML_TEMPLATE_PLAYER_H
#define SFML_TEMPLATE_PLAYER_H

#endif //SFML_TEMPLATE_PLAYER_H

class Player{

    private:
    int xPos, yPos;

    public:


    bool alive;

    Player();

    int returnXpos();
    int returnYpos();


    void playerRight();
    void playerLeft();

    RectangleShape cannon();
    RectangleShape playerRect1();
    RectangleShape playerRect2();

};