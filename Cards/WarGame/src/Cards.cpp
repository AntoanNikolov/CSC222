#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "Cards.h"
#include "random.h"
using namespace std;

string suit_string(Suit suit) {
    switch (suit) {
        case CLUBS: return "Clubs";
        case DIAMONDS: return "Diamonds";
        case HEARTS: return "Hearts";
        case SPADES: return "Spades";
        default: return "Not a valid suit";
    }
}

string rank_string(Rank rank) {
    switch (rank) {
        case JOKER: return "Joker";
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
        case ACE: return "Ace";
        default: return "Not a valid rank";
    }
}

Card::Card()
{
    suit = NONE;
    rank = JOKER;
}

Card::Card(Suit s, Rank r)
{
    suit = s; rank = r;
}

string Card::to_string() const
{
    if (rank == JOKER) return "Joker";
    return rank_string(rank) + " of " + suit_string(suit);
}

bool Card::operator==(const Card& c2) const
{
    return (suit == c2.suit && rank == c2.rank);
}

bool Card::operator>(const Card& c2) const
{
    // first check the suits
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;

    // if suits are equal, check ranks 
    if (rank > c2.rank) return true;
    if (rank < c2.rank) return false;

    // if ranks are equal too, 1st card is not greater than the 2nd 
    return false;
}

bool Card::operator!=(const Card& c2) const
{
    return !(this->operator==(c2));
}

bool Card::operator<=(const Card& c2) const
{
    return !(this->operator>(c2));
}

bool Card::operator<(const Card& c2) const
{
    return !(this->operator>(c2) && this->operator==(c2));
}

bool Card::operator>=(const Card& c2) const
{
    return this->operator>(c2) || this->operator==(c2);
}

void swap_cards(Card* c1, Card* c2)
{
    Card temp;
    temp.suit = c1->suit;
    temp.rank = c1->rank;
    c1->suit = c2->suit;
    c1->rank = c2->rank;
    c2->suit = temp.suit;
    c2->rank = temp.rank;
}

Deck::Deck(int size)
{
    vector<Card> temp(size);
    cards = temp;
}

Deck::Deck()
{
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank+1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

int Deck::size() {
    return cards.size();
}


int Deck::find(const Card& card) const
{
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == card) return i;
    }
    return -1;
}

void Deck::swap_cards(int i, int j)
{
    Card temp_card = cards[i];
    cards[i] = cards[j];
    cards[j] = temp_card;
}

int Deck::find_lowest(int l, int h)
{
    int lowest = l;
    for (int i = l + 1; i <= h; i++) {
        if (cards[lowest] > cards[i]) lowest = i;
    }
    return lowest;
}

void Deck::shuffle()
{
    for (int i = 0; i < cards.size(); i++) {
        int rand_card = random_between(0, cards.size() - 1);
        swap_cards(i, rand_card);
    }
}

void Deck::add_card(const Card& c)
{
    cards.push_back(c);
}

Card Deck::remove_card()
{
    Card card = cards[cards.size()-1];
    cards.pop_back();
    return card;
}

void Deck::add_cards(const Deck& d)
{
    cards.resize(cards.size() + d.cards.size());
    int i = d.cards.size();
    for (int j = 0; j < d.cards.size(); j++) {
        cards[i++] = d.cards[j];
    }
}

void Deck::sort()
{
    for (int i = 0; i < cards.size(); i++) {
        int lowest = find_lowest(i, cards.size() - 1);
        swap_cards(i, lowest);
    }
}

Deck Deck::merge(const Deck& d) const
{
    Deck result(cards.size() + d.cards.size());
    int i = 0;
    int j = 0;
    for (int k = 0; k < result.cards.size(); k++) {
        if (!(i < cards.size())) {
            result.cards[k] = d.cards[j++];
        }
        else if (!(j < d.cards.size())) {
            result.cards[k] = cards[i++];
        }
        else if (cards[i] > d.cards[j]) {
            result.cards[k] = d.cards[j++];
        }
        else {
            result.cards[k] = cards[i++];
        }
    }
    return result;
}

Deck Deck::merge_sort() const // this should work for now, but should be recursive
{
    int mid = cards.size() / 2; // find middle
    Deck lhalf = subdeck(0, mid - 1); // create lower half
    Deck uhalf = subdeck(mid, cards.size()-1); // create upper half
    
    lhalf.sort(); // sort lower half
    uhalf.sort(); // sort upper half

    return lhalf.merge(uhalf); // merge the two halves
}

Deck Deck::subdeck(int l, int h) const
{
    Deck sub(h-l+1);

    for (int i = 0; i < sub.cards.size(); i++) {
        sub.cards[i] = cards[l+i];
    }
    return sub;
}

bool WarCard::operator==(const WarCard& c2) const
{
    return (rank == c2.rank);
}

bool WarCard::operator>(const WarCard& c2) const
{
    // Handle Jokers high
    if (rank == JOKER && c2.rank != JOKER) return true;
    if (c2.rank == JOKER && rank != JOKER) return false;
    // Handle rest of ranks
    if (rank > c2.rank) return true;
    return false;
}
