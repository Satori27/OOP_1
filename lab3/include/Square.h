#pragma once
#include <ostream>
#include "Figure.hpp"
#include "vector1.hpp"
#include "FigureValidator.h"

using namespace std;

// для него валидатор: чтобы поинтов было не больше двух, чтобы из них получался квадрат, и чтобы координаты не были одинаковыми.

class Square : public Figure {
protected:
  Vector<Point> _points;

public:
  explicit Square(Vector<Point> p); // проверка что вектор не больше 2, а ромбе не больше 4 и проверить что они не одинаковые
  explicit Square(Point p1, Point p2); 
  
  Square& operator=(Square& sq); 
  bool operator==(Square& sq)const;
  explicit operator double() const;

  Point center() const override;
  double area() const override;

  friend std::ostream &operator<<(ostream &os, const Square &P) {
    for (int i = 0; i < P._points.getSize(); ++i) {
      os << P._points[i].x << " " << P._points[i].y;
      os << "\n";
    }
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Square &P) {
	double x,y;
	for (int i = 0; i < 2; ++i) {
	  is >> x >> y;
	  P._points.push_back({x,y});
	}
	return is;
  }
    static Square create_instance(Vector<Point> &points);

    static Square create_instance(Point x, Point y);

};
