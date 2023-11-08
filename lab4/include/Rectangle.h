#pragma once
#include "Figure.h"
#include <ostream>


using namespace std;


template <class T>
requires std::is_arithmetic_v<T>
class Rectangle : public Figure<T> {
protected:
  vector<Point<T>> _points;
    void Validate(vector<Point<T>> points) {
        if (points.size() != 2) {
          cout<<points.size()<<"\n";
            throw invalid_argument("Invalid number of points");
        }
        if(points[0].x==points[1].x || points[0].y==points[1].y){
            throw invalid_argument("Points can't be equal");
        }
        if(abs(points[0].x - points[1].x) == abs(points[0].y - points[1].y)){
            throw invalid_argument("It is square, not rectangle");
        }
    }

public:
  ~Rectangle() = default;
  explicit Rectangle(vector<Point<T>> p);
  explicit Rectangle(Point<T> p1, Point<T> p2);

  Rectangle &operator=(Rectangle &req);
  bool operator==(Rectangle &req) const;
  explicit operator double() const;

  Point<T> center() const override;
  double area() const override;

  friend std::ostream &operator<<(ostream &os, const Rectangle &P) {
	for (int i = 0; i < P._points.size(); ++i) {
	  os << P._points[i].x << " " << P._points[i].y;
	  os << "\n";
	}
	return os;
  }
  void print(std::ostream & os) override {
    os << *this;
  }

  friend std::istream &operator>>(std::istream &is, Rectangle &P) {
	double x, y;
  P._points.clear();
	for (int i = 0; i < 2; ++i) {
	  is >> x >> y;
	  P._points.push_back({x, y});
	}
	return is;
  }

};

#include "/home/satori/oop/OOP_1/lab4/src/lab0/Rectangle.hpp"
