#include "Model.hpp"
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <ctime>


const double MISSILE_SPEED = 5.0;
const int NUM_ASTEROIDS = 6;

Model::Model(int screenWidth, int screenHeight, Framework* framework) 
    : m_screenWidth(screenWidth), m_screenHeight(screenHeight), startTime(time(nullptr)), score(0.0f), lastMissileTime(0), hasShieldBeenMaintained(true)  {

    spaceship = new Spaceship(screenWidth/2, screenHeight/2, 30.0, 0.0, 1.0);
    flyingObjects.push_back(spaceship);

    missile = new Missile(340, spaceship->GetY() + spaceship->GetSize() / 2 + 10, 10, 0, 0, 0);
    flyingObjects.push_back(missile);

    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> disPos(0.0, 1.0);
    std::uniform_real_distribution<> disSize(20.0, 75.0);

    for (int i = 0; i < NUM_ASTEROIDS; i++) {
        double x = rand() % screenWidth;
        double y = rand() % screenHeight;
        double angle = rand() % 360;
        double speed = rand() % 5 + 1;
        flyingObjects.push_back(new Asteroid(x, y, angle, disPos(gen), disPos(gen)));
    }
}
void Model::majData() {
    time_t currentTime = time(nullptr);
    score = difftime(currentTime, startTime);
    
    if (difftime(currentTime, lastMissileTime) >= 180.0 && hasShieldBeenMaintained) { // 3 minutes
        score += 3.0;
        hasShieldBeenMaintained = false; // Pour ne pas attribuer les points plusieurs fois
    }
        if (spaceship->getShieldLevel() == 0) {
            std::cout << "Plus de Bouclier, Perdu!" << std::endl;
    }

    spaceship->SetWarning(false);

    for (FlyingObject* flyingObject : flyingObjects) {
        flyingObject->Move(m_screenWidth, m_screenHeight);

        if (flyingObject->GetTypeName() == "Asteroid" && FlyingObject::Collide(spaceship, flyingObject)) {
            spaceship->SetWarning(true);
            spaceship->reduceShieldLevel(0.1f, currentTime);
        }
    }
}
bool Model::isGameWon() const {
    return score >= 10.0f;
}

bool Model::isGameOver() const {
    return spaceship->getShieldLevel() == 0;
}

float Model::getScore() const {
    return score;
}

void Model::appliqueAction(int input) {
    switch (input)
    {
        case SDLK_ESCAPE: 
            exit(0);        
        case SDLK_UP:
            // spaceship->SpeedUp(1);
            avancerVaisseau();
            break;
        case SDLK_DOWN:
            // spaceship->SpeedDown(1);
            decelerervaiseau();
            break;
        case SDLK_RIGHT:
            // spaceship->Rotate(-15.0);
            tournerVaisseau();
            break;
        case SDLK_LEFT:
            // spaceship->Rotate(15.0);
            tournerVaisseau();
            break;
        case SDLK_SPACE:
            missile->IsActive();
            tirerMissile();
            //model->launchMissile();
            break;
        default:
            break;
    }
}

void Model::avancerVaisseau() {
    spaceship->SpeedUp(1);
}

void Model::decelerervaiseau() {
    spaceship->SpeedDown(1);
}

void Model::tournerVaisseau() {
    spaceship->Rotate(-15.0);
}

void Model::tirerMissile() 
{
    std::cout << "Touche Espace activé mais un missile déja présent à l'écran" << std::endl;
if (!missile->IsActive()) { // Only fire if there isn't an active missile
        // Calculate the front position of the spaceship
        double frontX = spaceship->GetX() + std::cos(spaceship->GetAngle() * M_PI / 180.0) * spaceship->GetSize();
        double frontY = spaceship->GetY() + std::sin(spaceship->GetAngle() * M_PI / 180.0) * spaceship->GetSize();
        missile->SetX(frontX);
        missile->SetY(frontY);
        // Set the missile's speed
        missile->SetXSpeed(std::cos(spaceship->GetAngle() * M_PI / 180.0) * MISSILE_SPEED);
        missile->SetYSpeed(-std::sin(spaceship->GetAngle() * M_PI / 180.0) * MISSILE_SPEED);

        missile->Activate(); // Activate the missile
    }
}

std::vector<FlyingObject*> Model::GetFlyingObjects() {
    return flyingObjects; // ou tout autre code pour retourner vos objets volants
}

void Model::CreateAsteroids(int numberOfAsteroids) {
    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> disPos(0.0, 1.0);
    std::uniform_real_distribution<> disSize(50.0, 150.0);

    for (int i = 0; i < numberOfAsteroids; i++) {
        double x = rand() % (int)m_screenWidth;
        double y = rand() % (int)m_screenHeight;
        double angle = rand() % 360;
        double speed = rand() % 5 + 1;
        flyingObjects.push_back(new Asteroid(x, y, angle, disPos(gen), disPos(gen)));
    }
}

void Model::UpdateObjects() {
    for (FlyingObject* flyingObject : flyingObjects) {
        flyingObject->Move(m_screenWidth, m_screenHeight);
    }
}

// bool Model::isGameWon() const {
//     return (score <= 180.0f && spaceship->getShieldLevel() >= 0.5f); // 180 secondes = 3 minutes
// }

// float Model::getScore() const {
//     return score;
// }