# Objects of Vectors  
- enum values are a type where each value has its own numbered id  
- By default, the first value in enumerated types is 0  
- By convention, the values in enumerated types have names with all capital letters.  
- enums go in the header file  
Given we have a rank and suit enum type:  
```
struct Card
{
    Rank rank;
    Suit suit;

    Card(Suit s, Rank r);
};
```  
- Now, a card can be created with ```Card card(DIAMONDS, JACK);```  
New code for building deck:  
```
vector<Card> build_deck()
{
    vector<Card> deck(52);
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank+1)) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}
```  
Use a switch statement to convert to a string:  
```
switch(suit) {
    case CLUBS: return "Clubs";
    case DIAMONDS: return "Diamonds";
    case HEARTS: return "Hearts";
    case SPADES: return "Spades";
    default: return "Not a valid suit";
}
```  
### to summarize so far, each card has enums, deciding the suit and rnak, cards belong to a deck. Cards and Decks have their own member functions for construction. Decks have additional functions, like finding a specific card.  
continuing...  
- shuffling:
```
void Deck::shuffle()
{
    for (int i = 0; i < cards.size(); i++) {
        int rand_card = random_between(0, cards.size() - 1);
        swap_cards(i, rand_card);
    }
}
```  
For hands of cards, we might want a function, subdeck, that takes a vector of cards and a range of indices, and returns a new vector of cards that contains the specified subset of the deck:
```
Deck Deck::subdeck(int l, int h) const
{
    Deck sub(h-l+1);

    for (int i = 0; i < sub.cards.size(); i++) {
        sub.cards[i] = cards[l+i];
    }
    return sub;
}
```  
- merge sort works by sorting small portions and them sorting the portions together
#### example of inheritance (like Python):  
```
struct WarCard : Card
{
    using Card::Card;

    bool operator==(const WarCard& c2) const;
    bool operator!=(const WarCard& c2) const;
    bool operator>(const WarCard& c2) const;
    bool operator>=(const WarCard& c2) const;
    bool operator<(const WarCard& c2) const;
    bool operator<=(const WarCard& c2) const;
};
```  
The : Card following WarCard tells the compiler that the WarCard object is a derived object that inherits from its parent Card object. The using Card::Card line is a using-declaration that tells the compiler that WarCards inherit the constructors of its parent.  
  
- In a c++ queue, the element inserted first is the first one to be removed. Elements are added to the back (rear) and removed from the front (head).  
```
#include <queue>
#include <iostream>

int main() {
    std::queue<int> q; // Declares a queue of integers
    // ... operations ...
    return 0;
}
```