#pragma once

#include "Romb.h"

class RombValidator : public IFigureValidator {
public:
    void Validate(Vector<Point> points) {
        double ab = distance(points[0], points[1]);
        double bc = distance(points[1], points[2]);
        double cd = distance(points[2], points[3]);
        double da = distance(points[3], points[0]);

        bool equal_side =  (ab == bc) && (bc == cd) && (cd == da);
        if(!equal_side){
            throw invalid_argument("Sides must be equals");
        }

        Point ab_vector {points[0].x - points[2].x, points[0].y - points[2].y};
        Point cd_vector {points[1].x - points[3].x, points[1].y - points[3].y};
        double scalar = ab_vector.x*cd_vector.x + ab_vector.y*cd_vector.y;
        if(scalar!=0){
            cout<<scalar<<"\n";
            throw invalid_argument("Diagonals must be perpendicular");
        }
    }

    bool IsAllowedFor(const std::type_info &type) {
        return typeid(Romb) == type;
    }
};
