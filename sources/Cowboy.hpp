#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel{};

class Cowboy : public Character{

    private:
       int numBullets; 

       int bulletsInGun;

    public:
        Cowboy(string name, Point location);
        
        void shoot(Character* other);

        bool hasboolets(); // checks if there are bullets left in the gun

        void reload(); // adds 6 bullets to gun

        

};


#endif