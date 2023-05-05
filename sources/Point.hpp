#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
using namespace std;
namespace ariel{};

class Point{

    private:
        double x_c;

        double y_c;

    public:
        Point(double x_c, double y_c);

        double getX() const;

        double getY() const;

        double distance(const Point other);

        Point moveTowards(const Point origin, const Point destination, double distance);

        void print();

        string to_string() ;

        
};


#endif