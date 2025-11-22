#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include <doctest.h>
#include "Fraction.h"
using namespace std;

TEST_CASE("Test can create Fractions using two constructors") {
    Fraction f1;
    CHECK(f1.numerator == 0);
    CHECK(f1.denominator == 1);
    Fraction f2(3, 4);
    CHECK(f2.numerator == 3);
    CHECK(f2.denominator == 4);
}
TEST_CASE("Test third Fraction constructor using a string") {
    Fraction f1("3/4");
    CHECK(f1.numerator == 3);
    CHECK(f1.denominator == 4);
    Fraction f2("37/149");
    CHECK(f2.numerator == 37);
    CHECK(f2.denominator == 149);
}
TEST_CASE("Test can render a Fraction as a string") {
    Fraction f1(17, 25);
    CHECK(f1.to_string() == "17/25");
    Fraction f2(-7, 11);
    CHECK(f2.to_string() == "-7/11");
}
TEST_CASE("Test Fractions are stored in lowest terms") {
    Fraction f1(6, 8);
    CHECK(f1.to_string() == "3/4");
    Fraction f2(8, 16);
    CHECK(f2.to_string() == "1/2");
}
TEST_CASE("Test gcd function") {
    CHECK(gcd(4, 14) == 2);
    CHECK(gcd(16, 12) == 4);
    CHECK(gcd(18, 27) == 9);
}
TEST_CASE("Test integer Fractions render properly") {
    Fraction f1(5, 1);
    CHECK(f1.to_string() == "5");
    Fraction f2(18, 3);
    CHECK(f2.to_string() == "6");
}
TEST_CASE("Test can construct Fraction from integer") {
    Fraction f1(5);
    CHECK(f1.numerator == 5);
    CHECK(f1.denominator == 1);
    Fraction f2(42);
    CHECK(f2.numerator == 42);
    CHECK(f2.denominator == 1);
}
TEST_CASE("Test string constructor with integers") {
    Fraction f1("15");
    CHECK(f1.numerator == 15);
    CHECK(f1.denominator == 1);
    Fraction f2("42");
    CHECK(f2.numerator == 42);
    CHECK(f2.denominator == 1);
}
TEST_CASE("Test comparison operators for Fractions") {
    Fraction f1(1, 4);
    Fraction f2(3, 4);
    Fraction f3(2, 5);
    Fraction f4(6, 8);
    CHECK((f2 > f1) == true);
    CHECK((f2 == f4) == true);
    CHECK((f1 < f3) == true);
    CHECK((f3 != f2) == true);
    CHECK((f4 >= f1) == true);
    CHECK((f4 <= f2) == true);
}
TEST_CASE("Additon, subtraction, multiplication, division") {
    Fraction f1(1, 4);
    Fraction f2(3, 2);
    CHECK((f1+f2)==(7/4));
    //Fraction f3(1, 4);
    //Fraction f4(3, 5);


}