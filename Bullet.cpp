//
// Created by Conce on 12/2/2020.
//
#include "Bullet.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Bullet::Bullet(int x, int y){

    xPos = x;
    yPos = y;
    hurtPlayer = false;
}

//Function to create then return the bullet shape
RectangleShape  Bullet::bulletDraw() {

    RectangleShape bullet;
    bullet.setFillColor(Color::Red);
    bullet.setPosition(Vector2f(xPos + 20, yPos));
    bullet.setSize(Vector2f (10,10));

    return bullet;
}

//Updates bullet speeds and checks if player or enemy bullet
void Bullet::bulletUpdate(){

    if (!hurtPlayer){
        yPos -= 0.05;
    }
    else{
        yPos += 0.04;
    }
}