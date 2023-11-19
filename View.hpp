///////////////////////////////////////////////////
//                   Classe View
///////////////////////////////////////////////////


#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "FlyingObject.hpp"
#include "framework.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include "Missile.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <random>



class View {
public:
    View(Framework* framework);
    void rafraichir(const std::vector<FlyingObject*>& flyingObjects);

private:
    Framework* framework;
};


#endif
