#pragma once
#include <ostream>
#include "Figure.hpp"
#include "vector1.hpp"
#include "FigureValidator.h"

using namespace std;

// для него валидатор: чтобы поинтов было не больше двух, чтобы из них получался квадрат, и чтобы координаты не были одинаковыми.

class Rectangle : public Figure {
protected:
  Vector<Point> _points;

public:
  ~Rectangle()= default;
  explicit Rectangle(Vector<Point> p);
  explicit Rectangle(Point p1, Point p2); 

  Rectangle& operator=(Rectangle& req); 
  bool operator==(Rectangle& req)const;
  explicit operator double() const;

  Point center() const override;
  double area() const override;

  friend std::ostream &operator<<(ostream &os, const Rectangle &P) {
    for (int i = 0; i < P._points.getSize(); ++i) {
      os << P._points[i].x << " " << P._points[i].y;
      os << "\n";
    }
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Rectangle &P) {
	double x,y;
	for (int i = 0; i < 2; ++i) {
	  is >> x >> y;
	  P._points.push_back({x,y});
	}
	return is;
  }

    static Rectangle create_instance(Vector<Point> &points);

    static Rectangle create_instance(Point x, Point y);

};
