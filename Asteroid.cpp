// ///////////////////////////////////////////////////
// //                   Asteroid
// // Bibliothèque encapsulant l'utilisation de SDL 2

#include "Asteroid.hpp"
#include "framework.hpp"
#include <iostream>
#include "Missile.hpp"
#include <cmath>
#include "FlyingObject.hpp"

// /////////////// 
// // Constructeur 
// // ------- 
// // * x, y : position dans l'écran 
// // * size : diamètre de l'objet 
// // * xSpeed, ySpeed : vecteur de vitesse de l'objet 
// Constructeur
Asteroid::Asteroid(double x, double y, double s, double xSpeed, double ySpeed)
    : FlyingObject(x, y, s, xSpeed, ySpeed), size(s) 
{}

double Asteroid::GetSize() const {
    return size;
}

void Asteroid::Move1(double elapsedTime) {
    // Mettre ici la logique de mouvement pour les astéroïdes
    // Par exemple, pour un mouvement linéaire :
    x += xSpeed * elapsedTime;
    y += ySpeed * elapsedTime;
}


void Asteroid::Move(double screenHeight, double screenWidth)
{
    // Mettez ici la logique pour déplacer l'astéroïde
    // Par exemple :
    x += xSpeed;
    y += ySpeed;
}

string Asteroid::GetTypeName() {
    return "Asteroid";
}

