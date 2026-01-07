- Inside add_card and other instance member functions, you can access instance variables without using the keyword this.  
- pop_back removes final item  
##### Example of class inheritance syntax in c++  
```
struct Deck: CardCollection {
    Deck(string label) : CardCollection(label) {
        for (int suit = 0; suit <= 3; suit++) {
            for (int rank = 1; rank <= 13; rank++) {
                add_card(Card(rank, suit))
            }
        }
    }
};
```
- colon to indicate that Deck extends the class CardCollection
- Deck object has the same instance variables and member functions as a CardCollection
- Constructors are NOT inherited
- The definition of the constructor uses a colon then the constructor from the superclass. This colon invokes the constructor of the base class before continuing.
```
struct Player {
    string name;
    Hand hand;

    Player(string name) {
        this->name = name;
        this->hand = Hand(name);
    }
};
```
- here, this-> specifically references the parameters.
- Composition is also known as a HAS-A relationship, as in “Eights has a Hand”. Inheritance is also known as an IS-A relationship, as in “Hand is a CardCollection”.