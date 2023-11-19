#include <iostream>
#include <string>
#include "framework.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Spaceship.hpp"
#include <cmath>
#include <random>
#include <ctime>
#include <SDL.h>


#include "Controller.hpp"

const double MISSILE_SPEED = 5.0;
const int NUM_ASTEROIDS = 6;

int main(int argc, char* argv[]) {
    
    int FPS = 60;
    int shipsize = 32;
    int missileSize = 20;


    Controller* controller = new Controller(FPS, shipsize, missileSize);
    controller->LauchGame();


    delete controller;  // Supprimer le contrôleur permet d'éviter des fuites de mémoire
    return 0;

    
}


 
std::string askPlayerName() {
    std::string playerName;
    std::cout << "Entrez votre nom: ";
    std::getline(std::cin, playerName);
    return playerName;
}

