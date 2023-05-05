#include <iostream>
#include "Ninja.hpp"


Ninja :: Ninja (string name, Point location,int alivePoints, int speed): Character(name, location, alivePoints){
    this ->speed  = speed;
}

void Ninja :: move(Character* other){
    Point p(0,0);
    this ->setLocation(p);
}

void Ninja :: slash(Character* other){
    if (this->getLocation().distance(other->getLocation()) < 100){
        other->setAlivePoints(-31);
    }
}