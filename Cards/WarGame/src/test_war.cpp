#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Cards.h"
using namespace std;

TEST_CASE("Test create WarCards") {
    WarCard wc1(DIAMONDS, JACK);
    WarCard wc2(HEARTS, ACE);
    WarCard wc3;
    CHECK(wc1.to_string() == "Jack of Diamonds");
    CHECK(wc2.to_string() == "Ace of Hearts");
    CHECK(wc3.to_string() == "Joker");
}

TEST_CASE("Test compare WarCards") {
    WarCard wc1(DIAMONDS, JACK);
    WarCard wc2(CLUBS, JACK);
    WarCard wc3(HEARTS, ACE);
    WarCard wc4;
    WarCard wc5(CLUBS, TEN);
    CHECK((wc1 == wc2) == true);
    // CHECK((wc1 != wc2) == false);
    CHECK((wc3 > wc2) == true);
    CHECK((wc4 > wc3) == true);
    // CHECK((wc4 <= wc3) == false);
    // CHECK((wc2 >= wc4) == false);
    // CHECK((wc2 < wc3) == true);
}
