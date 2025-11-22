#include "Fraction.h"
// #include <string>

Fraction::Fraction() {
    denominator = 1;
    numerator = 0;
}




Fraction::Fraction(int n,int d) {
    denominator = d;
    numerator = n;
}

Fraction::Fraction(std::string a) {
    int slash = a.find('/');
    numerator = std::stoi(a.substr(0, slash)); // stoi is more intuitive
    denominator = std::stoi(a.substr(slash + 1));
}