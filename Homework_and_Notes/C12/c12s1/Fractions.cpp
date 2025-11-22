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