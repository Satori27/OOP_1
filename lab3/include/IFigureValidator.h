#pragma once


#include "Figure.hpp"
#include "vector1.hpp"


class IFigureValidator {
public:
    void Validate(const std::type_info &type, Vector<Point> points);

    void Validate(Vector<Point> points);

    bool IsAllowedFor(const std::type_info &type);

    static double distance(Point p1, Point p2){
        double x = p1.x-p2.x;
        double y = p1.y-p2.y;
        double dist = sqrt(x*x+y*y);
        return dist;
    };
};

