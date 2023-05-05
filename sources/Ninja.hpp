#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel{};

class Ninja : public Character{

    private:
        int speed;

    public:

        Ninja(string name, Point location, int alivePoints, int speed);

        void move(Character* other);

        void slash(Character* other);

        int getSpeed() const;

};


#endif
