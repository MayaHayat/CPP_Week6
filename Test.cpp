#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"


using namespace std;
using namespace ariel;

TEST_CASE("Check Point functions"){
    Point p_1 (0,0);
    Point p_2 (3,4);

    CHECK_EQ(p_1.getX(),0);
    CHECK_EQ(p_1.getY(),0);
    CHECK(p_2.getX() == 3);
    CHECK(p_2.getY() == 4);
    CHECK(p_1.distance(p_2) == 5);
    CHECK(p_2.distance(Point(7,7)) == 5);
    
}

TEST_CASE("Check constructors and isAlive"){
    Point c_location(50,50);
    Cowboy c_1("Woody", c_location);
    Point location_old(0,5);
    OldNinja old("miyagi", location_old);
    YoungNinja yng("Daniel LaRusso" , Point(0,8));
    TrainedNinja trn("Trained ninja", Point(15,6));

    CHECK(c_1.getName() == "Woody");
    CHECK(old.getName() == "miyagi");
    CHECK(yng.getName() == "Daniel LaRusso");
    CHECK(trn.getName() == "Trained ninja");
    
    CHECK(old.getAlivePoints() == 150);
    CHECK(yng.getAlivePoints() == 100);
    CHECK(trn.getAlivePoints() == 120);
    
    CHECK(old.isAlive() == true);
    CHECK(yng.isAlive() == true);
    CHECK(trn.isAlive() == true);

    CHECK(old.getSpeed() == 8);
    CHECK(yng.getSpeed() == 14);
    CHECK(trn.getSpeed() == 12);
    
}

TEST_CASE("Check distance function"){
    Point c_location(50,50);
    Cowboy c_1("Woody", c_location);
    Point location_old(0,5);
    OldNinja old("miyagi", location_old);
    YoungNinja yng("Daniel LaRusso" , Point(0,8));
    TrainedNinja trn("Trained ninja", Point(15,6));

    CHECK(int(c_1.getLocation().distance(old.getLocation())) == 67);
    CHECK(int(yng.getLocation().distance(trn.getLocation())) == 15);
    
}

TEST_CASE("Check slash"){
    Point c_location(0.5,8);
    Cowboy *c_1 = new Cowboy("Woody", c_location);
    
    Point location_old(0,5);
    OldNinja *old = new OldNinja("miyagi", location_old);
    
    YoungNinja *yng = new YoungNinja("Daniel LaRusso" , Point(0,8));
    
    TrainedNinja *trn = new TrainedNinja("Trained ninja", Point(115,30));

    CHECK(yng->getAlivePoints() == 100);
    old->slash(yng);
    CHECK(yng->getAlivePoints() == 100);

    CHECK(trn->getAlivePoints() == 120);
    CHECK(location_old.distance( Point(115,30)) > 100);
    old->slash(trn);
    CHECK(trn->getAlivePoints() == 120);
    
}


TEST_CASE("Check slash"){
    Point c_location(0.5,8);
    Cowboy *c_1 = new Cowboy("Woody", c_location);

    Point location_old(0,5);
    OldNinja *old = new OldNinja("miyagi", location_old);
    
    YoungNinja *yng = new YoungNinja("Daniel LaRusso" , Point(0,8));
    
    Cowboy *c_2 = new Cowboy("Woody", Point(52,1));


    CHECK(yng->getAlivePoints() == 100);
    CHECK(c_1->getNumBullets() == 6);

    c_1->shoot(yng);
    CHECK(yng->getAlivePoints() == 90);
    CHECK(c_1->getNumBullets() == 5);
    CHECK(c_2->getNumBullets() == 6);

    c_1->shoot(yng);
    c_2->shoot(yng);
    CHECK(yng->getAlivePoints() == 70);
    CHECK(c_1->getNumBullets() == 4);
    CHECK(c_2->getNumBullets() == 5);
    
    c_1->shoot(yng);
    c_2->shoot(yng);
    CHECK(yng->getAlivePoints() == 50);
    CHECK(c_1->getNumBullets() == 3);
    CHECK(c_2->getNumBullets() == 4);

    c_1->shoot(yng);
    c_1->shoot(yng);
    c_1->shoot(yng);
    CHECK(yng->getAlivePoints() == 20);
    CHECK(c_1->getNumBullets() == 0);
    CHECK(c_2->getNumBullets() == 4);

    c_1->shoot(yng); // should do nothing
    c_2->shoot(yng);
    CHECK(yng->getAlivePoints() == 10);
    CHECK(c_1->getNumBullets() == 0);
    CHECK(c_2->getNumBullets() == 3);

    c_1->reload();
    CHECK(c_1->getNumBullets() == 6);
    c_1->shoot(yng);
    CHECK(yng->getAlivePoints() == 0);
    CHECK(yng->isAlive() == false);
    CHECK(c_1->getNumBullets() == 5);
    
}


TEST_CASE("Checking the move function"){
    Point location_old(0,5);

    OldNinja *old = new OldNinja("miyagi", location_old);
    TrainedNinja *trn = new TrainedNinja("Trained ninja", Point(105,30));

    CHECK(int(old->getLocation().distance(trn->getLocation())) == 107);
    CHECK(old->getSpeed() == 8);

    old->move(trn);
    CHECK_NOTHROW(old->getLocation().print());
    CHECK(int(old->getLocation().distance(trn ->getLocation())) == 99);
    double moved = (old->getLocation().distance(location_old));
    double old_speed = old->getSpeed();
    bool ans = moved == 8.0;
    CHECK(moved == old_speed);

}

TEST_CASE("Number of fighters"){
    Team team{new Cowboy("11", Point(-1,-1))};
    team.add(new YoungNinja("12", Point(0,0)));
    team.add(new TrainedNinja("13", Point(-10,0)));
    team.add(new OldNinja("14", Point(-0.5,0)));
    team.add(new Cowboy("15", Point(64,57)));
    team.add(new YoungNinja("16", Point(0,0)));
    team.add(new TrainedNinja("17", Point(-10,0)));
    team.add(new OldNinja("18", Point(-0.5,0)));
    team.add(new Cowboy("19", Point(64,57)));
    team.add(new Cowboy("19", Point(64,57)));

    CHECK(team.stillAlive() == 10);
    CHECK_THROWS(team.add(new Cowboy("20", Point(64,57))));
    CHECK(team.stillAlive() == 10);

    
}


TEST_CASE("Testing the Team"){
    Team team{new Cowboy("11", Point(-1,-1))};
    team.add(new YoungNinja("12", Point(0,0)));
    team.add(new TrainedNinja("13", Point(-10,0)));
    team.add(new OldNinja("14", Point(-0.5,0)));
    team.add(new Cowboy("15", Point(64,57)));

    CHECK_EQ(team.stillAlive(), 5);

    Cowboy* a = new Cowboy("4", Point(2,2));
    YoungNinja* b = new YoungNinja("1", Point(0,0));
    Team team2{b};
    team2.add(new TrainedNinja("2", Point(1,1)));
    team2.add(new OldNinja("3", Point(3,3)));
    team2.add(a);
    team2.add(new Cowboy("5", Point(6,57)));
	team2.add(new Cowboy("6", Point(64,9)));
	team2.add(new Cowboy("7", Point(10,5)));

    CHECK(team2.stillAlive() == 7);
    CHECK_NOTHROW(team2.print());

    team.attack(&team2);

    CHECK(team2.stillAlive() == 6);
    CHECK(b->isAlive() == 0);


    team.attack(&team2);
    // team2.print();
    team.attack(&team2);
    //team2.print();
    CHECK(team2.stillAlive() == 5);

}

TEST_CASE("Testing the Team2"){
    Team2 team{new Cowboy("11", Point(-1,-1))};
    team.add(new YoungNinja("12", Point(0,0)));
    team.add(new TrainedNinja("13", Point(-10,0)));
    team.add(new OldNinja("14", Point(-0.5,0)));

    CHECK_EQ(team.stillAlive(), 4);

    Cowboy* a = new Cowboy("4", Point(2,2));
    YoungNinja* b = new YoungNinja("1", Point(0,0));
    Team team2{b};
    team2.add(new TrainedNinja("2", Point(1,1)));
    team2.add(new OldNinja("3", Point(3,3)));
    team2.add(a);
    team2.add(new Cowboy("5", Point(6,57)));
	team2.add(new Cowboy("6", Point(64,9)));
	team2.add(new Cowboy("7", Point(10,5)));

    // can't attack self
    CHECK_THROWS(team2.attack(&team2));


    // playing war on team2
    team2.attack(&team);
    CHECK(team.stillAlive() == 4);
    team2.attack(&team);
    team2.attack(&team);
    team2.attack(&team);
    

    team2.attack(&team);
    CHECK(team.stillAlive() == 1);

    team2.attack(&team);
    CHECK(team.stillAlive() == 0);


    CHECK_THROWS(team2.attack(&team));
    

}


TEST_CASE("Testing the smartTeam"){
    SmartTeam team{new Cowboy("11", Point(-1,-1))};
    team.add(new YoungNinja("12", Point(0,0)));
    team.add(new TrainedNinja("13", Point(-10,0)));
    team.add(new OldNinja("14", Point(-0.5,0)));
    team.add(new Cowboy("15", Point(64,57)));

    CHECK_EQ(team.stillAlive(), 5);

    Cowboy* a = new Cowboy("4", Point(2,2));
    YoungNinja* b = new YoungNinja("1", Point(0,0));
    Team team2{b};
    team2.add(new TrainedNinja("2", Point(1,1)));
    team2.add(new OldNinja("3", Point(3,3)));
    team2.add(a);
    team2.add(new Cowboy("5", Point(6,57)));
	team2.add(new Cowboy("6", Point(64,9)));
	team2.add(new Cowboy("7", Point(10,5)));

    CHECK(team2.stillAlive() == 7);
    // playing war on team2
    team.attack(&team2);
    // print to see what went wrong
    //team2.print();
    CHECK(b->getAlivePoints() < a->getAlivePoints());
    CHECK(b->isAlive() == false);
    CHECK(team2.stillAlive() == 6);
    CHECK_FALSE(a->isAlive() == 0);

    team.attack(&team2);
    team2.print();
    CHECK(a->getAlivePoints() == 90);

    team.attack(&team2);
    team2.print();
    CHECK(a->getAlivePoints() == 0);
    CHECK(team2.stillAlive() == 5);

}