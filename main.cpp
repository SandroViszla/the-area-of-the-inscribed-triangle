#include <iostream>
#include <cmath>
class Triangle;
class Point{
protected:
    float x;
    float y;
public:
    Point(float xx = 0.0, float yy = 0.0) : x(xx), y(yy) {};
    friend  Point operator / (Point &source, float c);
    friend Point operator + (Point &, Point &);
    friend class Triangle;
    friend std::istream& operator >> (std::istream&, Point& z);
};
std::istream& operator >> (std::istream& input, Point& z)
{
    char semicolon;
    input >> z.x >> semicolon >> z.y;
    return  input;
}
Point operator+(Point & first, Point & second) {
    return *( new Point( first.x + second.x, first.y + second.y) );
}

Point operator/(Point & source, float c) {
    return *( new Point( source.x / c, source.y / c ) );
}

class Triangle{
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle(Point p, Point q, Point f) : p1(p), p2(q), p3(f) {};
    Triangle(float xa, float ya, float xb, float yb, float xc, float yc) : p1(xa,ya), p2(xb,yb), p3(xc, yc){};
    Triangle center();
    float square();

};
Triangle Triangle::center()
{
    Point w_1 = p1 + p2;
    Point w_2 = p2 + p3;
    Point w_3 = p1 + p3;
    return *( new Triangle( w_1 / 2, w_2 / 2, w_3 / 2 ) );
}
float Triangle::square()
{
    return 0.5 * abs(((p2.x - p1.x)*(p3.y-p1.y) - (p3.x - p1.x)*(p2.y - p1.y)));
}

int main()
{
    Point A, B, C;
    std::cin >> A >> B >> C;
    Triangle source(A,B,C);
    std::cout<<source.center().square();
    return 0;
}
