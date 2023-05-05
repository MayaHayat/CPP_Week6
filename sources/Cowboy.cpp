#include <iostream>
#include "Cowboy.hpp"

Cowboy :: Cowboy(string name, Point location) : Character(name, location){

}

void Cowboy :: shoot(Character* other){
    if (other->getAlivePoints() > 0){
        other->setAlivePoints(-10);
    }
}

bool Cowboy :: hasboolets(){
    if (bulletsInGun > 0){
        return true;
    }
    return false;
}

void Cowboy :: reload(){
    this ->bulletsInGun += 6;
} 
