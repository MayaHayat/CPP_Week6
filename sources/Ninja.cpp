#include <iostream>
#include "Ninja.hpp"


Ninja :: Ninja (string name, Point location,int alivePoints, int speed): Character(name, location, alivePoints){
    this ->speed  = speed;
}

void Ninja :: move(Character* other){
    double distance = this->getLocation().distance(other->getLocation());
    double d_x = double(other->getLocation().getX() - this->getLocation().getX())/distance;
    double d_y = double(other->getLocation().getY() - this->getLocation().getY())/distance;
    double new_x = this->getLocation().getX() + d_x*this->speed;
    double new_y = this->getLocation().getY() + d_y*this->speed;
    Point new_location(new_x, new_y);
    this ->setLocation(new_location);
    //cout << " moved "<< endl;
}

void Ninja :: slash(Character* other){
    if (this->getLocation().distance(other->getLocation()) < 100){
        other->setAlivePoints(-31);
    }
}

int Ninja :: getSpeed()const{
    return this ->speed;
}