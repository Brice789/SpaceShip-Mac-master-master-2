///////////////////////////////////////////////////
//                   Classe FlyingObject
///////////////////////////////////////////////////


#ifndef FlyingObject_HPP_
#define FlyingObject_HPP_
#include <string>
#include "include/SDL2/SDL.h"
#include <cmath>
#include <vector>


class FlyingObject
{

    public:
        // Getters
        virtual double GetX();
        virtual double GetY();
        virtual double GetXSpeed();
        virtual double GetYSpeed();
        virtual double GetSize();
        double getX() const { return x; }
        double getY() const { return y; }
        double getSize() const { return size; }
        // Setters
        virtual void SetX(double x);
        virtual void SetY(double y);
        virtual void SetXSpeed(double xSpeed);
        virtual void SetYSpeed(double ySpeed);
        virtual void SetSize(double size);

        FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);

        virtual void Move(double screenWidth, double screenHeight) = 0;
        static bool Collide(FlyingObject* o1, FlyingObject* o2);
        static void CheckCollisions(std::vector<FlyingObject*>& allFlyingObjects);
        virtual std::string GetTypeName() = 0;
        virtual double GetAngle();

        bool active; 
        void Deactivate();
        bool IsActive() const;


    protected:
        double x; 
        double y; 
        double size; 
        double xSpeed; 
        double ySpeed;
};

#endif