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

Fraction::Fraction(int n) {
    numerator = n;
    denominator = 1;
}

Fraction::Fraction(int n,int d) {
    int divisor = gcd(n,d);
    denominator = d/divisor;
    numerator = n/divisor;
}

Fraction::Fraction(std::string a) {
    int slash = a.find('/');
    if (slash != std::string::npos) {
    numerator = std::stoi(a.substr(0, slash)); // stoi is more intuitive
    denominator = std::stoi(a.substr(slash + 1));
    int divisor = gcd(numerator,denominator);
    numerator /= divisor;
    denominator /= divisor;
    }
    else {
        numerator = std::stoi(a.substr(0, slash));
        denominator = 1;
    }
}

std::string Fraction::to_string() {
    if (denominator != 1) {
        std::string output = std::to_string(numerator) + "/" + std::to_string(denominator);
        return output;
    }
    else {
        std::string output = std::to_string(numerator);
        return output;
    }
}

// having everything be a double to begin with and only converting to ints in to_string would have been
// more optimized but oh well

bool Fraction::operator>(const Fraction& f2) const
{
    double val1 = static_cast<double>(numerator) / denominator;
    double val2 = static_cast<double>(f2.numerator) / f2.denominator;
    return (val1 > val2);
}
bool Fraction::operator==(const Fraction& f2) const
{
    double val1 = static_cast<double>(numerator) / denominator;
    double val2 = static_cast<double>(f2.numerator) / f2.denominator;
    return (val1 == val2);
}
bool Fraction::operator<(const Fraction& f2) const
{
    double val1 = static_cast<double>(numerator) / denominator;
    double val2 = static_cast<double>(f2.numerator) / f2.denominator;
    return (val1 < val2);
}
bool Fraction::operator!=(const Fraction& f2) const
{
    double val1 = static_cast<double>(numerator) / denominator;
    double val2 = static_cast<double>(f2.numerator) / f2.denominator;
    return (val1 != val2);
}
bool Fraction::operator>=(const Fraction& f2) const
{
    double val1 = static_cast<double>(numerator) / denominator;
    double val2 = static_cast<double>(f2.numerator) / f2.denominator;
    return (val1 >= val2);
}
bool Fraction::operator<=(const Fraction& f2) const
{
    double val1 = static_cast<double>(numerator) / denominator;
    double val2 = static_cast<double>(f2.numerator) / f2.denominator;
    return (val1 <= val2);
}

// lcm is needed for below functions
int lcm(int a, int b) { 
    return a * b / gcd(a, b);
}

Fraction Fraction::operator+(const Fraction& f2) {
    if (denominator == f2.denominator) {
        int newnum = numerator + f2.numerator;
        int newden = denominator;
        return Fraction(newnum, newden);
    }
    // i need to find the least common factor between the two denominators
    else { 
        int newden = lcm(denominator, f2.denominator);
        int factor1 = newden / denominator; // to multiply first numerator accordingly (accounting for denominator change)
        int factor2 = newden / f2.denominator; // same for second numerator
        int newnum = numerator * factor1 + f2.numerator * factor2;
        return Fraction(newnum, newden);
    }
}
Fraction Fraction::operator-(const Fraction& f2) {
    if (denominator == f2.denominator) {
        int newnum = numerator - f2.numerator;
        int newden = denominator;
        return Fraction(newnum, newden);
    }
    // i need to find the least common factor between the two denominators
    else { 
        int newden = lcm(denominator, f2.denominator);
        int factor1 = newden / denominator; // to multiply first numerator accordingly (accounting for denominator change)
        int factor2 = newden / f2.denominator; // same for second numerator
        int newnum = numerator * factor1 - f2.numerator * factor2;
        return Fraction(newnum, newden);
    }
}

Fraction Fraction::operator*(const Fraction& f2) {
    int newnum = numerator * f2.numerator;
    int newden = denominator *f2.denominator;
    return Fraction(newnum, newden);
}
// reciprocals for division
Fraction Fraction::operator/(const Fraction& f2) {
    int newnum = numerator * f2.denominator;
    int newden = denominator *f2.numerator;
    return Fraction(newnum, newden);
}