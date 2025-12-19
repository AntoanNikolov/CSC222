#include <string>
#include <vector>
#include <queue>
using namespace std;

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES, NONE};
enum Rank {JOKER, TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
           NINE, TEN, JACK, QUEEN, KING, ACE};

string suit_string(Suit);
string rank_string(Rank);

struct Card
{
    Suit suit;
    Rank rank;

    // constructors
    Card();
    Card(Suit s, Rank r);

    // member functions
    string to_string() const;
    bool operator==(const Card& c2) const;
    bool operator>(const Card& c2) const;
    bool operator<(const Card& c2) const;
    bool operator>=(const Card& c2) const;
    bool operator<=(const Card& c2) const;
    bool operator!=(const Card& c2) const;

    Card merge_sort();
};

void swap_cards(Card* c1, Card* c2);

struct Deck
{
    vector<Card> cards;

    // constructors
    Deck(int size);
    Deck();

    // modifiers
    void swap_cards(int i, int j);
    void shuffle();
    void add_card(const Card& c);
    Card remove_card();
    void add_cards(const Deck& d);
    void sort();

    // member functions
    int size();
    int find(const Card& card) const;
    Deck subdeck(int l, int h) const;
    Deck merge(const Deck& d) const;
    Deck merge_sort() const;
    // void print() const;
    int find_lowest(int l, int h);
};
