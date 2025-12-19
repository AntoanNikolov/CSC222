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
