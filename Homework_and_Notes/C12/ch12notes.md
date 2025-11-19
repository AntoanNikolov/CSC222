# Chapter 12 Notes
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