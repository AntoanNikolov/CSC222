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

std::string Fraction::to_string() {
    std::string output = std::to_string(numerator) + "/" + std::to_string(denominator);
    return output;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        }
    return a;
}