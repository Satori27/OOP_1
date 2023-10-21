#pragma once
#include <Figure.hpp>
#include <FigureValidator.h>
#include <IFigureValidator.h>


using namespace std;

// для него валидатор: чтобы поинтов было не больше двух, чтобы из них получался квадрат, и чтобы координаты не были одинаковыми.

class Romb : public Figure {
protected:
  Vector<Point> _points;

public:
  explicit Romb(Vector<Point> p);
  explicit Romb(Point x, Point y, Point x1,Point y1); 

  Romb& operator=(Romb& sq); 
  bool operator==(Romb& sq)const;
  explicit operator double() const;

  Point center() const override;
  double area() const override;

  friend std::ostream &operator<<(ostream &os, const Romb &P) {
    for (int i = 0; i < P._points.getSize(); ++i) {
      os << P._points[i].x << " " << P._points[i].y;
      os << "\n";
    }
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Romb &P) {
	double x,y;
	for (int i = 0; i < 4; ++i) {
	  is >> x >> y;
	  P._points.push_back({x,y});
	}
	return is;
  }

    static Romb create_instance(Vector<Point> &points);

    static Romb create_instance(Point x, Point y, Point x1, Point y1);

};
