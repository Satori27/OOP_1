#include <Square.h>
#include <Rectangle.h>
#include <string>
using namespace std;


int main() {
    Vector<Point> vec;
    Point p(4,4);
    vec.push_back(p);
    p = {5,5};
    vec.push_back(p);
    // Square a(vec);
    // Square b(vec);
    Rectangle e({1,2}, {2,1});
    // cin>>a;
    // cout<<a << b;
    // a=b;
    // cout<<a << b; 
    // double c = (double)a;
    // cout<<c<<endl;
    // cin>>a;
}