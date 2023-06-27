/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" 
#include "sources/SmartTeam.hpp" 
#include "sources/Team2.hpp" 

using namespace ariel;


int main() {
   Point pa(32.3,44),pb(1.3,3.5);
   assert(pa.distance(pb) == pb.distance(pa));
   Cowboy *tom = new Cowboy("Tom", pa);
   OldNinja *sushi = new OldNinja("sushi", pb);
   tom->shoot(sushi);
   cout << tom->print() <<endl;

   cout << "----------- Team1 - smart --------------" << endl;

   SmartTeam team{new Cowboy("11", Point(-1,-1))};
   team.add(new YoungNinja("12", Point(0,0)));
   team.add(new TrainedNinja("13", Point(-10,0)));
   team.add(new OldNinja("14", Point(-0.5,0)));
   team.add(new Cowboy("15", Point(64,57)));

   team.print();

   cout << "----------- Team2  - normal --------------" << endl;


   Cowboy* a = new Cowboy("4", Point(2,2));
   YoungNinja* b = new YoungNinja("1", Point(0,0));
   Team team2(b);
   team2.add(new TrainedNinja("2", Point(1,1)));
   team2.add(new OldNinja("3", Point(3,3)));
   team2.add(a);
   team2.add(new Cowboy("5", Point(6,57)));
	team2.add(new Cowboy("6", Point(64,9)));
	team2.add(new Cowboy("7", Point(10,5)));

   team2.print();

   cout << "----------- Team3  - 2 --------------" << endl;


   Cowboy* c = new Cowboy("4", Point(2,2));
   YoungNinja* d = new YoungNinja("1", Point(0,0));
   Team2 team3(d);
   team3.add(new TrainedNinja("2", Point(1,1)));
   team3.add(new OldNinja("3", Point(3,3)));
   team3.add(c);
   team3.add(new Cowboy("5", Point(6,57)));
	team3.add(new Cowboy("6", Point(64,9)));
	team3.add(new Cowboy("7", Point(10,5)));

   team3.print();
    

   // ----------------- Start war -----------------

   team.attack(&team2);
   team2.print();

   cout << "-----------" << endl;
    

   team.attack(&team2);
   team2.print();
   cout << "-----------" << endl;

   team.attack(&team2);
   team2.print();
   

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}