#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <fstream>

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
using namespace chrono;

#include "./Player.h"
#include "./Alien.h"
#include "./Bullet.h"



int main() {

    //starts timer for the game
    auto start = high_resolution_clock::now();

    //loads the invaders image
    Texture texture;
    texture.loadFromFile("Invaders.png");

    //rand for choosing which aliens to shoot
    srand(time(0));
    rand();


    int inputSeconds;
    int inputMiliseconds;

    //Opens and reads in previous game time from file
    ifstream timeFile("time.txt");
    if (timeFile.fail()){
        cerr << "Input file could not open\n" << endl;
        return -1;
    }
    timeFile >> inputSeconds >> inputMiliseconds;
    timeFile.close();


    //Creates a vector of 4 x 8 aliens
    const int NUM_ALIENS_DOWN(4), NUM_ALIENS_ACROSS(8);
    vector <vector<Alien>> AlienVector;

    for (int i = 0; i < NUM_ALIENS_DOWN; ++i) {
        vector<Alien> row;
        for (int j = 0; j < NUM_ALIENS_ACROSS; ++j) {
            Alien tempAlien(texture, IntRect(Vector2(32, 25), Vector2(100, 75)),50 + 50 * j, 100 + 50 * i );
            row.push_back(tempAlien);
        }
        AlienVector.push_back(row);
    }

    //Creates the player's character and the bullet vector which holds both enemy and player bullets
    Player playerCharacter;
    vector<Bullet> bulletVector(0, Bullet(playerCharacter.returnXpos(),playerCharacter.returnYpos()));


    //Opens and displays space invaders window
    RenderWindow window(VideoMode(Vector2u(640, 640)), "Space Invaders");

    while ( window.isOpen()) {


        //Timer start and stop for enemy bullets
        auto stop2 = high_resolution_clock::now();
        auto timer = duration_cast<std::chrono::microseconds>(stop2 - start);

        //The enemy Shoots bullets about every three seconds
        if (timer.count() % 1000 == 0){
           // cout << " butt " << endl;
            for (int i = 0; i < 2; ++i)  {

                int x = rand() % 4;
                int y = rand() % 8;
                AlienVector.at(x).at(y).xPos;
                AlienVector.at(x).at(y).yPos;
                Bullet tempBullet(AlienVector.at(x).at(y).xPos, AlienVector.at(x).at(y).yPos);
                tempBullet.hurtPlayer = true;
                bulletVector.push_back(tempBullet);
            }
        }


        //For loop which checks if an enemy bullets have hit the player then kills player and ends window
        //Please don't take off points for this code right here for being repetitive for some reason when
        //I used the players alive bool along with an || for the timer on line 174 the code wasn't working properly. This seemed to fix it though.
        for (int i = 0; i < bulletVector.size(); ++i) {
            if (bulletVector.at(i).hurtPlayer) {
                //Checks player's hitbox
                if (bulletVector.at(i).xPos >= playerCharacter.returnXpos() - 30 && bulletVector.at(i).xPos <= playerCharacter.returnXpos() + 50 &&
                    bulletVector.at(i).yPos >= playerCharacter.returnYpos() && bulletVector.at(i).yPos <= playerCharacter.returnYpos() + 30){
                    playerCharacter.alive = false;
                    cout << "You have died.\n";
                    window.close();
                    //Stops the games timer then Displays it
                    auto stop = high_resolution_clock::now();
                    auto seconds = duration_cast<std::chrono::seconds>(stop - start);
                    auto milliseconds = duration_cast<std::chrono::milliseconds>(stop - start);
                    cout << "Here's your previous time from when you last played. " << "Seconds: " << inputSeconds << " Milliseconds: " << inputMiliseconds << endl;
                    cout << "Here's your time in seconds: " << seconds.count() << " seconds." << endl;
                    cout << "Here's your time in milliseconds: " << milliseconds.count() << " milliseconds." << endl;

                    //Takes the players current run time and puts it into the file
                    ofstream outputFile("time.txt");
                    if (outputFile.fail()){
                        cerr << "Output file failed to open\n";
                        return -2;
                    }
                    outputFile << seconds.count() << " " << milliseconds.count() << endl;
                    outputFile.close();
                }
            }
        }



        //Draws and updates my bullet velocity
        for (int i = 0; i < bulletVector.size(); ++i) {
            window.draw(bulletVector.at(i).bulletDraw());
            bulletVector.at(i).bulletUpdate();
        }

        //Compares each aliens position to all the players bullets
        //Then only draws the "alive" aliens
        for (int i = 0; i < NUM_ALIENS_DOWN; ++i) {
            for (int j = 0; j < NUM_ALIENS_ACROSS; ++j) {
                for (int k = 0; k < bulletVector.size(); ++k) {
                    if (AlienVector.at(i).at(j).alive) {
                        if (!bulletVector.at(k).hurtPlayer) {
                            if (bulletVector.at(k).xPos >= AlienVector.at(i).at(j).xPos - 20 &&
                                bulletVector.at(k).xPos <= AlienVector.at(i).at(j).xPos + 30 &&
                                bulletVector.at(k).yPos >= AlienVector.at(i).at(j).yPos &&
                                bulletVector.at(k).yPos <= AlienVector.at(i).at(j).yPos + 35) {

                                AlienVector.at(i).at(j).isDead();
                                bulletVector.erase(bulletVector.cbegin() + k);
                            }
                        }
                    }
                }
                if (AlienVector.at(i).at(j).alive) {
                    window.draw(AlienVector.at(i).at(j));
                }
            }
        }


        //Bounces each alien off the walls and moves them
        for (int i = 0; i < NUM_ALIENS_DOWN; ++i) {
            for (int j = 0; j < NUM_ALIENS_ACROSS; ++j) {
                if ( AlienVector.at(i).at(j).xPos + 30 >= 640 || AlienVector.at(i).at(j).xPos - 20 <= 0){
                    AlienVector.at(i).at(j).moveAlienBy *= -1;
                }
                AlienVector.at(i).at(j).moveAlien();
            }
        }

        //Counts the number of aliens dead
        int numAliensDead(0);
        for (int i = 0; i < NUM_ALIENS_DOWN; ++i) {
            for (int j = 0; j < NUM_ALIENS_ACROSS; ++j) {
                if (!AlienVector.at(i).at(j).alive){
                    numAliensDead++;
                }
            }
        }


        //If all the aliens are dead then it closes the window, gives the time, and congratulates the player
        if (numAliensDead >= 32) {
            //Just like the clock up top, takes the time and displays it then puts it into file
            auto stop = high_resolution_clock::now();
            auto seconds = duration_cast<std::chrono::seconds>(stop - start);
            auto milliseconds = duration_cast<std::chrono::milliseconds>(stop - start);

            cout << "Here's your previous time from when you last played. " << "Seconds: " << inputSeconds << " Milliseconds: " << inputMiliseconds << endl;
            cout << "Here's your time in seconds: " << seconds.count() << " seconds." << endl;
            cout << "Here's your time in milliseconds: " << milliseconds.count() << " milliseconds." << endl;

            ofstream outputFile("time.txt");
            if (outputFile.fail()){
                cerr << "Output file failed to open\n";
                return -2;
            }
            outputFile << seconds.count() << " " << milliseconds.count() << endl;
            outputFile.close();

            cout << "Hurray! You have defeated the aliens! \n";
            window.close();
        }
        numAliensDead = 0;


        //Displays and updates the window
        window.display();
        window.clear(Color::Black);


        //Draws the players character
        if (playerCharacter.alive) {
            window.draw(playerCharacter.playerRect1());
            window.draw(playerCharacter.playerRect2());
            window.draw(playerCharacter.cannon());
        }

        //Checks for any events like player controls and turns of controls when player is dead
        // Event event;
        while (const std::optional event = window.pollEvent()) {      // ask the window if any events occurred
            if (event->is<Event::Closed>()) { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            } else if (const auto* keyPressed = event->getIf<Event::KeyPressed>()) {
                if (playerCharacter.alive) {
                    switch (keyPressed->code) {

                        case Keyboard::Key::Right:
                            playerCharacter.playerRight();
                            break;

                        case Keyboard::Key::Left:
                            playerCharacter.playerLeft();
                            break;

                        case Keyboard::Key::Space:
                            Bullet tempBullet = Bullet(playerCharacter.returnXpos(), playerCharacter.returnYpos( ));
                            bulletVector.push_back(tempBullet);
                            break;
                    }
                }
            }
        }
    }

    return 0;
}

