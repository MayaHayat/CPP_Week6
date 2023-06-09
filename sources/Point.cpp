#include <iostream>
#include <cmath>
#include "Point.hpp"

using namespace std;



double Point :: getX() const{
    return this -> x_c;
}

double Point :: getY() const{
    return this -> y_c;
}

double Point :: distance(Point other)const{
    return (sqrt(pow(this ->x_c - other.getX(), 2) + pow(this ->y_c - other.getY(),2)));
}

// move towards closest point within range
Point Point :: moveTowards(Point origin, Point destination, double distance){
    if (distance < 0){
        throw std::invalid_argument("Distance must be > 0");
    }
    if (origin.distance(destination) <= distance){
        return destination;
    }
    // calc how much it would have to compromise
    double ratio = distance / origin.distance(destination);
    // Look out for ratio
    double newX = origin.x_c + (destination.x_c - origin.x_c) * ratio;
    double newY = origin.y_c + (destination.y_c - origin.y_c) * ratio;

    return Point(newX, newY);
}

string Point :: print(){
    string s = "(" + to_string(this ->x_c) + " , " + to_string(this ->y_c) + " )";
    return s;    
}
