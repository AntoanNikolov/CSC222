#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <string>
#include "Cards.h"
using namespace std;

TEST_CASE("Test can create Cards") {
    Card c1;
    CHECK(c1.suit == 0);
    CHECK(c1.rank == 0);
    Card c2(3, 4);
    CHECK(c2.suit == 3);
    CHECK(c2.rank == 4);
}

TEST_CASE("Test can render Cards") {
    Card c3(3, 12);
    CHECK(c3.to_string() == "Queen of Hearts");
    Card c4(2, 10);
    CHECK(c4.to_string() == "10 of Diamonds");
    Card c5;
    CHECK(c5.to_string() == "Joker");
}

TEST_CASE("Test comparison of Cards") {
    Card c1(2, 9);
    Card c2(1, 10);
    Card c3(1, 10);
    CHECK((c1 == c2) == false); // had to modify test to fix an error
    CHECK((c2 == c3) == true);
}

TEST_CASE("Test non-equal comparisons of Cards") {

    Card c1(1,10);
    Card c2(3,11);
    Card c3(2,12);
    Card c4(9, 10);
    Card c5(9,10);
    Card c6(1,12);
    CHECK((c1>c2) == false); // all higher
    CHECK((c2>c1) == true); // flipped above
    CHECK((c3>c6) == true); // higher suit, lower rank, first card value is most important so should be true
    CHECK((c3>c2) == false); // lower suit, higher rank, first card value is most important so should be false


}