

//Le controlleur est celui qui voit tout et coordinateur

#include "Controller.hpp"
#include <vector>
using namespace std;


// const double MISSILE_SPEED = 5.0;
const int NUM_ASTEROIDS = 6;


Controller::Controller(int FPS, int shipsize, int missileSize) {

    framework = new Framework(FPS, shipsize, missileSize);
    model = new Model( framework->GetScreenWidth(), framework->GetScreenHeight(), framework);
    vue = new View(framework);
    framework->Update();
}

void Controller::LauchGame()
{
    time_t lastAsteroidTime = time(nullptr);  // Temps de la dernière création d'astéroïde


    while(1) {


        int input = framework->GetInput();
        model->appliqueAction(input);

        time_t currentTime = time(nullptr);
        if (currentTime - lastAsteroidTime >= 7) {  // Créer de nouveaux astéroïdes toutes les 7 secondes
            model->CreateAsteroids(NUM_ASTEROIDS);
            lastAsteroidTime = currentTime;
        }

        vector<FlyingObject*> flyingObjects = model->GetFlyingObjects();
        model->majData();  // Mettre à jour les positions et les états des objets volants
        
        vue->rafraichir(flyingObjects);  // Dessiner les objets volants à l'écran

    }
}



