///////////////////////////////////////////////////
//                   Classe Missile
///////////////////////////////////////////////////
#include <iostream>
#include "framework.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include <iostream>
#include "framework.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include <cmath>


///////////////
// Constructeur
///////////////
// * x, y : position dans l'écran
// * size : diamètre du missile
// * speed : vitesse de déplacement
// * angle : orientation
Missile::Missile(double x, double y, double size, double xSpeed, double ySpeed, double angle)
: FlyingObject(x, y, size, xSpeed, ySpeed), m_angle(angle) {
    this->active = false; // Initially the missile should not be active
}


std::string Missile::GetTypeName() {
    return "Missile";
}


void Missile::Move(double screenWidth, double screenHeight) {
    if (IsActive()) {
        x += xSpeed;
        y += ySpeed;

        //std::cout << "Missile position X: " << x << " Y: " << y << std::endl;
        if (x > screenWidth || x < 0 || y > screenHeight || y < 0) {
            Deactivate(); // Deactivate the missile if it goes off-screen
            std::cout << "Le Missile est surprimé car il sort de l'écran. Appuyer sur la touche espace pour créer un nouveau Missile" << std::endl;
        }
    }
}


double Missile::GetX() const {
    return x;
}

double Missile::GetY() const {
    return y;
}

void Missile::SetX(double newX) {
    x = newX;
}

void Missile::SetY(double newY) {
    y = newY;
}

void Missile::SetXSpeed(double newXSpeed) {
    xSpeed = newXSpeed;
}

void Missile::SetYSpeed(double newYSpeed) {
    ySpeed = newYSpeed;
}

void Missile::Activate() {
    active = true;
}

void Missile::Deactivate() {
    active = false;
}

bool Missile::IsActive() const {
    return active;
}



