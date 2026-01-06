#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
using namespace std;

class Complex
{
    double real, imag;
    double mag, theta;
    bool polar;

public:
    Complex() {
        real = 0; imag = 0;
        polar = false;
    }

    Complex(double r, double i) {
        real = r; imag = i;
        polar = false;
    }

    double Complex::get_real()
    {
        return real;
    }

    double Complex::get_imag()
    {
        return imag;
    }

    void Complex::calculate_polar()
    {
        mag = sqrt(real * real + imag * imag);
        theta = atan(imag / real);
        polar = true;
    }

    double Complex::get_mag()
    {
        if (polar == false) calculate_polar();
        return mag;
    }

    double Complex::get_theta()
    {
        if (polar == false) calculate_polar();
        return theta;
    }

    Complex Complex::operator + (const Complex& c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex Complex::operator - (const Complex& c)
    {
        return Complex(c.real - real, c.imag - imag);
    }

};