//
// Created by Conce on 12/1/2020.
//
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "Alien.h"


// Alien::Alien() {

//     xPos = 50.0;
//     yPos = 100.0;
//     // Note: Default constructor creates sprite without texture
//     // You'll need to call setTexture() later if using this constructor
//     alive = true;
//     scale(Vector2f(1, 1));
//     setPosition(Vector2f(xPos, yPos));
// }

//Creates a polymorph class of an alien along with its sprite
Alien::Alien(Texture &texture, IntRect rect, int x, int y):Sprite(texture, rect){

    xPos = 50.0;
    yPos = 100.0;
    // Note: Default constructor creates sprite without texture
    // You'll need to call setTexture() later if using this constructor
    alive = true;
    scale(Vector2f(1, 1));
    setPosition(Vector2f(xPos, yPos));
    
    scale(Vector2f(.5, .5));
    xPos = x;
    yPos = y;
    setPosition(Vector2f(xPos, yPos));
    alive = true;
    moveAlienBy = 0.02;
}

//Rather than deleting the alien I turn it off using a bool
void Alien::isDead() {
    alive = false;
}

//Moves the alien
void Alien::moveAlien(){
    xPos += moveAlienBy;
    setPosition(Vector2f(xPos,yPos));
}




