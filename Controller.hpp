#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "Model.hpp"
#include "View.hpp"
#include <vector>
#include "framework.hpp"

class Controller {

    public :

        Controller(int FPS, int shipsize, int missileSize);

        void LauchGame();

    private :
        Model* model;
        View* vue;
        Framework* framework;

    };

#endif
