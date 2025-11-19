# Chapter 12 Notes
- We can use vectors to hold an array of structs/objects. An example usage is a deck of cards.
- The True boolean value is "larger" than false. Example:
```#include <iostream>
using namespace std;

int main()
{
    bool p = true;
    bool q = false;

    if (p > q) {
        cout << "Truth prevails over falsehood." << endl;
    }

    return 0;
}
```  
- ```->``` dereferences the ```this``` pointer.
```   
bool Card::operator<(const Card& c2) const
{
    return !(this->operator>(c2) || this->operator==(c2));
}
```   
Alternative Way to write it:  
```return !((*this).operator>(c2) || (*this).operator==(c2));```
- Binary searches are the most efficient, as they search based on order (given the array/vector of items is ordered)
- Example binary search:
```
int bin_search(const Card& card, const vector<Card>& deck, int l, int h) {
    int m = (l + h) / 2;

    if (deck[m].equals(card)) return mid;

    if (deck[m].is_greater(card))
        return bin_search(card, deck, l, m-1)
    else
        return bin_search(card, deck, m+1, h);
    if (h < l) return -1;
}
```