#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Cards.h"
using namespace std;

TEST_CASE("Test create Deck") {
    Deck d1(10);
    CHECK(d1.cards.size() == 10);
    CHECK(d1.cards[0].to_string() == "Joker");
    Deck d2;
    CHECK(d2.cards.size() == 52);
    CHECK(d2.cards[0].to_string() == "2 of Clubs");
    CHECK(d2.cards[51].to_string() == "Ace of Spades");
}

TEST_CASE("Test find Card in Deck") {
    Deck d;
    Card c(HEARTS, QUEEN);
    int pos = d.find(c);
    CHECK(d.cards[pos].to_string() == "Queen of Hearts");
    // Create non-existant card to confirm it isn't in the deck
    Card c2(NONE, QUEEN);
    int pos2 = d.find(c2);
    CHECK(pos2 == -1);
}

TEST_CASE("Test swap_cards in Deck") {
    Deck d;
    d.swap_cards(0, 51);
    CHECK(d.cards[0].to_string() == "Ace of Spades");
    CHECK(d.cards[51].to_string() == "2 of Clubs");
}

TEST_CASE("Test remove_card and add_card") {
    Deck deck;
    deck.shuffle();
    CHECK(deck.cards.size() == 52);
    Card c = deck.remove_card();
    CHECK(deck.cards.size() == 51);
    Deck deck2(0);
    CHECK(deck2.cards.size() == 0);
    deck2.add_card(c);
    CHECK(deck2.cards.size() == 1);
    CHECK((deck2.cards[0] == c) == true);
}

TEST_CASE("Test can swap two random cards") {
    Card c1(HEARTS, QUEEN);
    Card c2(DIAMONDS, JACK);
    swap_cards(&c1, &c2);
    CHECK(c1.to_string() == "Jack of Diamonds");
    CHECK(c2.to_string() == "Queen of Hearts");
}

TEST_CASE("Test create subdecks") {
    Deck deck;
    Deck subdeck = deck.subdeck(2, 10);
    CHECK(subdeck.cards.size() == 9);
    CHECK(subdeck.cards[0].to_string() == "4 of Clubs");
}

TEST_CASE("Test add_cards and merge_sort") {
    Deck d1(0);
    Deck d2(0);
    d1.add_card(Card(HEARTS, QUEEN));
    d1.add_card(Card(SPADES, ACE));
    d1.add_card(Card(CLUBS, FOUR));
    d1.add_card(Card(DIAMONDS, FOUR));
    d2.add_card(Card(CLUBS, FIVE));
    d2.add_card(Card(HEARTS, TEN));
    d2.add_card(Card(CLUBS, TWO));
    d1.add_cards(d2);
    Deck d3 = d1.merge_sort();
    CHECK(d3.cards[0].to_string() == "2 of Clubs");
    CHECK(d3.cards[1].to_string() == "4 of Clubs");
}
