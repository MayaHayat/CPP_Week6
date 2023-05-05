#include <iostream>
#include "Team.hpp"

Team :: Team(Character* leader) : leader(*leader){
}


//~Team();
    
void Team :: add(Character* newChr){
    this ->numberMembers += 1;
}

void  Team :: attack(Team* other){
    cout << " team is attacking " << endl;

}

int Team :: stillAlive(){
    return this ->numberMembers;
}

void Team :: print(){
    cout << " printing " << endl;
}