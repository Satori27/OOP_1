#include <Rectangle.h>

Rectangle::Rectangle(Vector<Point> p) { _points = p; }

Rectangle::Rectangle(Point p1, Point p2){
    _points.push_back(p1);
    _points.push_back(p2);
}

double Rectangle::area() const { 
  double x = _points[0].x - _points[1].x;
  double y = _points[0].y - _points[1].y;
  return abs(x*y);
}


Point Rectangle::center() const {
  double x_center = (_points[0].x + _points[1].x) / 2;
  double y_center = (_points[0].y + _points[1].y) / 2;
  return {x_center, y_center};
}

Rectangle::operator double() const {
  return this->area();
}

Rectangle& Rectangle::operator=(Rectangle& req){
  for( int i=0;i <req._points.getSize();++i){
    this->_points.push_back(req._points[i]);
  }
  return *this;
}


bool Rectangle::operator==(Rectangle& req) const {
  for( int i=0; i < req._points.getSize(); ++i){
    bool is_equal = this->_points[i].x != req._points[i].x || this->_points[i].y != req._points[i].y;
    if(is_equal){
      return false;
    }
  }
  return true;
}


       Rectangle Rectangle::create_instance(Vector<Point> &points) {
        FigureValidator::Validate(typeid(Rectangle), points);

        return Rectangle(points);
    }

     Rectangle Rectangle::create_instance(Point x, Point y) {
        Vector<Point> points;
        points.push_back(x);
        points.push_back(y);
        FigureValidator::Validate(typeid(Rectangle), points);

        return Rectangle(x, y);
    }  
