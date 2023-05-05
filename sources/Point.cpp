#include <iostream>
#include <cmath>
#include "Point.hpp"

using namespace std;

Point :: Point(double x_c, double y_c){
    this -> x_c = x_c;
    this -> y_c = y_c;
}

double Point :: getX() const{
    return this -> x_c;
}

double Point :: getY() const{
    return this -> y_c;
}

double Point :: distance(const Point other){
    return (std :: sqrt(std :: pow(this ->x_c - other.getX(), 2) + std :: pow(this ->y_c - other.getY(),2)));
}

Point Point :: moveTowards(const Point origin, const Point destination, double distance){
    return Point(0,0);
}

string Point :: print(){
    string s = "(" + to_string(this ->x_c) + " , " + to_string(this ->y_c) + " )";
    return s;    
}

// bool Point :: operator==(Point& other){
//     if (this ->x_c == other.getX() && this ->y_c == other.getY()){
//         return true;
//     }
//     return false;
// }
