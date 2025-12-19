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
    CHECK((wc1 != wc2) == false);
    CHECK((wc3 > wc2) == true);
    CHECK((wc4 > wc3) == true);
    CHECK((wc4 <= wc3) == false);
    CHECK((wc2 >= wc4) == false);
    CHECK((wc2 < wc3) == true);
}

TEST_CASE("Test create empty pile") {
    Pile p;
    CHECK(p.size() == 0);
}

TEST_CASE("Test add and remove cards from pile") {
    Pile p;
    p.add_card(WarCard(HEARTS, QUEEN));
    CHECK(p.size() == 1);
    p.add_card(WarCard(HEARTS, TEN));
    p.add_card(WarCard(HEARTS, TWO));
    CHECK(p.size() == 3);
    WarCard c = p.remove_card();
    CHECK(p.size() == 2);
    // Check FIFO behavior for piles (removed card is Queen of Hearts)
    CHECK(c.to_string() == "Queen of Hearts");
}

TEST_CASE("Test create piles from subdeck") {
    Deck d;
    Card c;
    Card c2;
    d.add_card(c);
    d.add_card(c2);
    CHECK(d.cards.size() == 54);
    d.shuffle();
    Pile p1(d.subdeck(0, 26));
    Pile p2(d.subdeck(27, 53));
    CHECK(p1.size() == 27);
    CHECK(p2.size() == 27);
}

TEST_CASE("Test move cards from one pile to another") {
    Deck d;
    Pile p1(d.subdeck(0, 9));
    Pile p2(d.subdeck(10, 19));
    CHECK(p1.size() == 10);
    CHECK(p2.size() == 10);
    p1.move_cards(p2);
    CHECK(p1.size() == 20);
    CHECK(p2.size() == 0);
}
