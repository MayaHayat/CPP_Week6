#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"

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

TEST_CASE("Check constructors"){
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
    
}

TEST_CASE("Check functions"){
    Point c_location(50,50);
    Cowboy c_1("Woody", c_location);
    Point location_old(0,5);
    OldNinja old("miyagi", location_old);
    YoungNinja yng("Daniel LaRusso" , Point(0,8));
    TrainedNinja trn("Trained ninja", Point(15,6));

    CHECK(c_1.distance(old) == 67.2681);
    CHECK(yng.distance(trn) == 15.132);
    
}

TEST_CASE("Check before and after games"){
    Point c_location(50,50);
    Cowboy *c_1 = new Cowboy("Woody", c_location);
    Point location_old(0,5);
    OldNinja *old = new OldNinja("miyagi", location_old);
    YoungNinja *yng = new YoungNinja("Daniel LaRusso" , Point(0,8));
    TrainedNinja *trn = new TrainedNinja("Trained ninja", Point(115,30));

    CHECK(yng->getAlivePoints() == 100);
    old->slash(yng);
    CHECK(yng->getAlivePoints() == 69);

    CHECK(trn->getAlivePoints() == 120);
    CHECK(location_old.distance( Point(115,30)) > 100);
    old->slash(trn);
    CHECK(trn->getAlivePoints() == 120);
    
}

TEST_CASE("Checking the move function"){
    Point location_old(0,5);

    OldNinja *old = new OldNinja("miyagi", location_old);
    TrainedNinja *trn = new TrainedNinja("Trained ninja", Point(105,30));

    CHECK(old->getLocation().distance(trn->getLocation()) == 107);
    CHECK(old->getSpeed() == 8);

    old->move(trn);
    cout<< "OldNinja was at " << location_old.print() << " and now is at " << old->getLocation().print() << endl;
    CHECK_NOTHROW(old->getLocation().print());
    CHECK(old->getLocation().distance(trn ->getLocation()) == 99);
    double moved = (old->getLocation().distance(location_old));
    double old_speed = old->getSpeed();
    bool ans = moved == 8.0;
    cout << moved << " " << old_speed << " " << ans << " i" << endl;
    CHECK_EQ(moved, old_speed);

}