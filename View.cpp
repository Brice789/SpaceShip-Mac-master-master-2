#include "View.hpp"
#include <string>
#include <iostream>
#include "framework.hpp"
#include <iostream>
#include "framework.hpp"
#include "Missile.hpp"
#include "FlyingObject.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include <cmath>

View::View(Framework* framework) : framework(framework) {}


void View::rafraichir(const std::vector<FlyingObject*>& flyingObjects) {
    for (FlyingObject* obj : flyingObjects) {
        std::string type = obj->GetTypeName();

        if (type == "Spaceship") {
            Spaceship* ship = dynamic_cast<Spaceship*>(obj);
            if (ship) {
                framework->DrawShip(ship->GetX(), ship->GetY(), ship->GetAngle(), ship->getShieldLevel(), ship->IsWarning());
            }
        } else if (type == "Missile") {
            Missile* missile = dynamic_cast<Missile*>(obj);
            if (missile && missile->IsActive()) {
                framework->DrawMissile(missile->GetX(), missile->GetY());
            }
        } else if (type == "Asteroid") {
            Asteroid* asteroid = dynamic_cast<Asteroid*>(obj);
            if (asteroid) {
                framework->DrawAsteroid(asteroid->GetX(), asteroid->GetY(), asteroid->GetSize());
            }
        }
    }
    framework->Update();
}

