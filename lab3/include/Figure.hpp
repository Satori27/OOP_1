#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector1.hpp>
#include <cmath>
// #include "FigureValidator.h"
// #include "IFigureValidator.h"

using namespace std;

struct Point {
    double x;
    double y;
    Point() = default;

    Point(double _x, double _y) : x(_x), y(_y) {}
};

class Figure {

public:
    Figure() = default;

    virtual Point center() const = 0;
    virtual double area() const = 0;

    ~Figure() = default;

};



// inline std::ostream &operator<<(ostream &os, const Figure &P) {
//   os << P.x1 << " "<<P.y1;
//   return os;
// }

// inline std::istream &operator>>(istream &is, Figure &P) {
//   int x1, y1;
//   is >> x1 >> y1;
//   P.x1 = x1;
//   P.y1 = y1;
//   return is;
// }