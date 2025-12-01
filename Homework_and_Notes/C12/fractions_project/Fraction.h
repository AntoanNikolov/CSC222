#include <string>
struct Fraction
{
    int numerator, denominator;

    Fraction();
    Fraction(int n);
    Fraction(int n,int d);
    Fraction(std::string a);
    std::string to_string();
    bool operator==(const Fraction& f2) const;
    bool operator>(const Fraction& f2) const;
    bool operator<(const Fraction& f2) const;
    bool operator>=(const Fraction& f2) const;
    bool operator<=(const Fraction& f2) const;
    bool operator!=(const Fraction& f2) const;
    Fraction operator+(const Fraction& f2);
    Fraction operator-(const Fraction& f2);
    Fraction operator*(const Fraction& f2);
    Fraction operator/(const Fraction& f2);

};
int gcd(int a, int b); 