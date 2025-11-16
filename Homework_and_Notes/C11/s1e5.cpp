#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <string>
using namespace std;


struct Point {
    double x, y;

    Point();
    Point(double a, double b);
    
    Point operator+(const Point&);

};

Point::Point(){
    x=0;
    y=0;
}

Point::Point(double a, double b){
    x=a;
    y = b;
}

Point Point::operator+(const Point& otherpoint) {
    return Point(x + otherpoint.x, y + otherpoint.y);
}



TEST_CASE("Test can create Points") {
    Point p1;
    CHECK(p1.x == 0.0);
    CHECK(p1.y == 0.0);
    Point p2(3, 4);
    CHECK(p2.x == 3.0);
    CHECK(p2.y == 4.0);
}

TEST_CASE("Test can add Points") {
    Point p1(3, 4);
    Point p2(5, 2);
    Point p3 = p1 + p2;
    CHECK(p3.x == 8.0);
    CHECK(p3.y == 6.0);
}

// TEST_CASE("Test can render Points as strings") {
//    Point p(8, 7);
//    string expected = "(8.000000, 7.000000)";
//    CHECK(p.to_string() == expected);
// }
