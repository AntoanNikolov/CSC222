#include <string>
struct Fraction
{
    int numerator, denominator;

    Fraction();
    Fraction(int n);
    Fraction(int n,int d);
    Fraction(std::string a);
    std::string to_string();

};
int gcd(int a, int b); 