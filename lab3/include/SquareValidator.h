#pragma once

#include "IFigureValidator.h"
#include "Square.h"


class SquareValidator : public IFigureValidator {
public:
    void Validate(Vector<Point> points) {
        if (points.getSize() != 2) {
            throw invalid_argument("Invalid number of points");
        }
        if(points[0].x==points[1].x || points[0].y==points[1].y){
            throw invalid_argument("Points can't be equal");
        }
        if(abs(points[0].x - points[1].x) != abs(points[0].y - points[1].y)){
            throw invalid_argument("It is rectangle, not square");
        }
    }

    // bool IsAllowedFor(const std::type_info &type) {
    //     return typeid(Square) == type;
    // }
};
