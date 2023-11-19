///////////////////////////////////////////////////
//                   Classe Spaceship
///////////////////////////////////////////////////
#include <iostream>
#include "framework.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include <cmath>
#include <string>
#include <random>
#include <ctime>

Spaceship::Spaceship(double x, double y, double size, double initialAngle, float initialShieldLevel)
    : FlyingObject(x, y, size, 0.0, 0.0), angle(initialAngle), shieldLevel(initialShieldLevel), lastHitTime(0) {
    // Autres initialisations si nécessaire
}


double Spaceship::GetAngle() {
    return angle;
}

void Spaceship::SpeedUp(double accelerationFactor) {
    // Calcul de la nouvelle vitesse en fonction de l'angle
    double radians = (M_PI * (180 - angle)) / 180;
    double accelerationX = accelerationFactor * cos(radians);
    double accelerationY = accelerationFactor * sin(radians);

    // Ajout de l'accélération à la vitesse
    velocityX += accelerationX;
    velocityY += accelerationY;
}

void Spaceship::SpeedDown(double decelerationFactor) {
    // Implémentez la décélération en soustrayant plutôt qu'en ajoutant à la vitesse.
    // Calcul de la nouvelle vitesse en fonction de l'angle
    double radians = (M_PI * (180 - angle)) / 180;
    double decelerationX = decelerationFactor * cos(radians);
    double decelerationY = decelerationFactor * sin(radians);

    // Soustraction de la décélération à la vitesse
    velocityX -= decelerationX;
    velocityY -= decelerationY;
}

void Spaceship::Rotate(double rotationAngle) {
    // Implémentez la rotation du vaisseau en ajustant l'angle.
    angle += rotationAngle;
}


bool Spaceship::UpdatePosition(double screenWidth, double screenHeight) {
    // Mettez à jour la position en fonction de la vitesse
    x += velocityX;
    y += velocityY;

    // Ajoutez ici des conditions pour garder le vaisseau dans les limites de l'écran si nécessaire
    if (x > screenWidth) 
        x = 0;
    else if (x < 0) 
        x = screenWidth;

    if (y > screenHeight) 
        y = 0;
    else if (y < 0) 
        y = screenHeight;

    // Vérifiez si l'objet est sorti des limites de l'écran
    if (x > screenWidth || x < 0 || y > screenHeight || y < 0) {
        xSpeed =0;
        ySpeed =0;
        return true; // L'objet est sorti de l'écran
    } else {
        return false; // L'objet est toujours à l'intérieur de l'écran
    }
}

void Spaceship::Position(double screenWidth, double screenHeight) {
    // Mettez à jour la position en fonction de la vitesse
    x += velocityX;
    y += velocityY;

    // Ajoutez ici des conditions pour garder le vaisseau dans les limites de l'écran si nécessaire
    if (x > screenWidth) 
        x = 0;
    else if (x < 0) 
        x = screenWidth;

    if (y > screenHeight) 
        y = 0;
    else if (y < 0) 
        y = screenHeight;
}




void Spaceship::Move(double screenHeight, double screenWidth)
{
    x += velocityX;
    y += velocityY;

    if (x > screenWidth) 
        x = 0;
    else if (x < 0) 
        x = screenWidth;

    if (y > screenHeight) 
        y = 0;
    else if (y < 0) 
        y = screenHeight;
}

std::string Spaceship::GetTypeName() {
    return "Spaceship";
}

void Spaceship::reduceShieldLevel(float amount, time_t currentTime) {
    if (currentTime - lastHitTime >= 1) { // 1 seconde écoulée
        shieldLevel -= amount;
        if (shieldLevel < 0.0f) shieldLevel = 0.0f; // Éviter un niveau de bouclier négatif
        lastHitTime = currentTime;
        std::cout << "Le vaisseau a été touché. Niveau de bouclier: " << shieldLevel << std::endl;
    }
}
