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
