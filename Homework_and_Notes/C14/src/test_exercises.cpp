#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "s0.cpp"
using namespace std;

TEST_CASE("Tests can subtract complex numbers") {
    Complex c1(4.0, 5.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 - c2;
    CHECK(c3.get_real() == 3.0);
    CHECK(c3.get_imag() == 3.0);
}