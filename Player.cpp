//
// Created by Conce on 12/1/2020.
//
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "Player.h"


//Puts the player in the middle of the screen
Player::Player(){
    xPos = 320;
    yPos = 600;
    bool alive = true;
}



int Player::returnXpos(){
    return xPos;
}
int Player::returnYpos(){
    return yPos;
}



void Player::playerRight() {
    if(xPos + 50 < 640){
        xPos += 20;
    }
};

void Player::playerLeft() {
    if(xPos > -20 ){
        xPos -= 20;
    }
};

//all of these functions draw each individual part of the player
//Draws one of the players pieces
RectangleShape Player::cannon() {
    RectangleShape rectGun;
    rectGun.setPosition(Vector2f(xPos + 20, yPos - 20));
    rectGun.setSize(Vector2f (20,40));
    return rectGun;
}

RectangleShape Player::playerRect1(){
    RectangleShape rectBody;
    rectBody.setPosition(Vector2f(xPos, yPos));
    rectBody.setSize(Vector2f (60,30));
    return rectBody;
}

RectangleShape Player::playerRect2(){
    RectangleShape rectBody2;
    rectBody2.setPosition(Vector2f(xPos - 10,yPos + 10));
    rectBody2.setSize(Vector2f (80,20));
    return rectBody2;
}