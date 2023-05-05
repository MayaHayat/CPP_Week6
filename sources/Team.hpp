#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
namespace ariel{};

class Team{

    private:
        int numberMembers;

        Character leader;

        static const int maxMembers = 10;

        vector <Character> members;

    public:
        Team(Character* leader);
        

        //~Team();
    
        void add(Character* newChr);

        void attack(Team* other);

        int stillAlive();

        void print();

};


#endif