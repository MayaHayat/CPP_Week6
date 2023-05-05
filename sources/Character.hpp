#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"

using namespace std;
namespace ariel{};

class Character{

    private:
        Point location;

        int alivePoints;

        string name;

    public:
        Character(string name, Point location, int alivePoints);

        Character(string name, Point location);


        int getAlivePoints()const;

        void setAlivePoints(int toAdd);

        bool isAlive();

        double distance(Character& other);

        void hit(int numPoints);

        string getName();

        Point getLocation();

        void setLocation(Point &other);

        // string to_string();

        string print();

};


#endif