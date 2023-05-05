#include <iostream>
#include <cmath>
#include "Character.hpp"

using namespace std;

Character :: Character(string name, Point location, int alivePoints): location(location){
    this -> name = name;
    // this -> location = location;
    this ->alivePoints = alivePoints;
}

Character :: Character(string name, Point location): location(location){
    this -> name = name;
}

bool Character :: isAlive(){
    if (this ->alivePoints > 0){
        return true;
    }
    return false;
}

double Character :: distance(Character& other){
    return this->location.distance(other.getLocation());
}

void Character :: hit(int numPoints){
    cout << " hit " << endl;
}

string Character :: getName(){
    return this ->name;
}

Point Character :: getLocation(){
    return this ->location;
}

void Character :: setLocation(Point &other){
    this ->location = other;
}

string Character :: print(){
    //cout << this ->name << " is standing at " << this ->location.print() << " and has " << this ->alivePoints << " lives left."<< endl;
    string alive = to_string(this ->alivePoints) + " ";
    string s = this -> name +  " is standing at " + (this ->location.print()) + " and has " + alive + " lives left.";
    return s;

}

int Character :: getAlivePoints()const{
    return this ->alivePoints;
}

void Character :: setAlivePoints(int toAdd){
    this ->alivePoints += toAdd;
    cout << this ->alivePoints << endl;
}