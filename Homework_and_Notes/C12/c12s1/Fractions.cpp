#include "Fraction.h"
// #include <string>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        }
    return a;
}

Fraction::Fraction() {
    denominator = 1;
    numerator = 0;
}


Fraction::Fraction(int n,int d) {
    int divisor = gcd(n,d);
    denominator = d/divisor;
    numerator = n/divisor;
}

Fraction::Fraction(std::string a) {
    int slash = a.find('/');
    numerator = std::stoi(a.substr(0, slash)); // stoi is more intuitive
    denominator = std::stoi(a.substr(slash + 1));
    int divisor = gcd(numerator,denominator);
    numerator /= divisor;
    denominator /= divisor;
}

std::string Fraction::to_string() {
    std::string output = std::to_string(numerator) + "/" + std::to_string(denominator);
    return output;
}