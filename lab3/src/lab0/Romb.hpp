#include <Romb.h>

Romb::Romb(Vector<Point> p) { _points = p; }
Romb::Romb(Point x, Point y, Point x1,Point y1){
  _points.push_back(x);
  _points.push_back(y);
  _points.push_back(x1);
  _points.push_back(y1);
}

double Romb::area() const { 
  double diagonal1 = sqrt(pow(_points[1].x- _points[3].x, 2) + pow(_points[1].y- _points[3].y, 2));
  double diagonal2 = sqrt(pow(_points[2].x- _points[4].x, 2) + pow(_points[2].y- _points[4].y, 2));
  double area = (diagonal1+diagonal2)/2;
  return area;
}

Point Romb::center() const {
  double x_center = (_points[0].x + _points[1].x + _points[2].x + _points[3].x) / 4;
  double y_center = (_points[0].y + _points[1].y + _points[2].y + _points[3].y) / 4;
  return {x_center, y_center};
}

Romb::operator double() const {
  return this->area();
}

Romb& Romb::operator=(Romb& sq){
  for( int i=0;i <sq._points.getSize();++i){
    this->_points.push_back(sq._points[i]);
  }
  return *this;
}


bool Romb::operator==(Romb& sq) const {
  for( int i=0; i < sq._points.getSize(); ++i){
    bool is_equal = this->_points[i].x != sq._points[i].x || this->_points[i].y != sq._points[i].y;
    if(is_equal){
      return false;
    }
  }
  return true;
}


     Romb Romb::create_instance(Vector<Point> &points) {
        FigureValidator::Validate(typeid(Romb), points);

        return Romb(points);
    }

     Romb Romb::create_instance(Point x, Point y, Point x1, Point y1) {
        Vector<Point> points;
        points.push_back(x);
        points.push_back(y);
        points.push_back(x1);
        points.push_back(y1);
        FigureValidator::Validate(typeid(Romb), points);

        return Romb(x, y, x1, y1);
    }   

