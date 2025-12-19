#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "random.h"
#include <ctime>

TEST_CASE("6-sided die rolls must be in valid range") {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int roll = random_between(1, 6);
        CHECK(roll >= 1);
        CHECK(roll <= 6);
    }
}

TEST_CASE("reversed parameter order") {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int value = random_between(6, 3);
        CHECK(value >= 3);
        CHECK(value <= 6);
    }
}

TEST_CASE("equal parameters") {
    int value = random_between(5, 5);
    CHECK(value == 5);
}