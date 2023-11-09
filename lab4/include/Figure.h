#pragma once

#include "My_Array.h"

using namespace std;

template <class T>
class Point {
    public:
    T x;
    T y;
    Point() = default;

    Point(T _x, T _y) : x(_x), y(_y) {}
};


template <class T>
class Figure {
public:
    Figure() = default;

    virtual Point<T> center() const = 0;
    virtual double area() const = 0;
    friend std::ostream &operator<<(ostream &os, const Figure<T> &P){
        os<<"Figure "<<endl;
        return os;
    }
            virtual void print(std::ostream & os) {
            os << *this;
        }

    ~Figure() = default;

    protected: 
        vector<Point<T>> _points;
};


