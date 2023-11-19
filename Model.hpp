#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "FlyingObject.hpp"
#include "Spaceship.hpp"
#include "Missile.hpp"
#include "Asteroid.hpp"
#include "framework.hpp"
#include <vector>

class Model {

    public :

        Model(int screenWidth, int screenHeight, Framework*);
        void appliqueAction(int input);
        void majData();

        void tournerVaisseau();
        void avancerVaisseau();
        void tirerMissile();
        void decelerervaiseau();

        std::vector<FlyingObject*> GetFlyingObjects();
        //liste en forme de vecteur de pointeur sur des objets volants


        void CreateAsteroids(int numberOfAsteroids);

        void UpdateObjects();

        bool isGameWon() const;
        float getScore() const;
        void updateScore();  


            void launchMissile(); // Appelée lors du lancement d'un missile
        bool isGameOver() const;




    private :
        std::vector<FlyingObject*> flyingObjects;
        Spaceship* spaceship;
        Missile* missile;
        Asteroid* asteroid;
        int m_screenWidth;
        int m_screenHeight;

        time_t startTime;  // Temps de début du jeu
        float score;
        time_t lastMissileTime; // Pour suivre le temps depuis le dernier lancement de missile
        bool hasShieldBeenMaintained; // Pour suivre si le bouclier a été maintenu
};

#endif