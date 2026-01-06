#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <cmath>
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

    double get_real()
    {
        return real;
    }

    double get_imag()
    {
        return imag;
    }

    void calculate_polar()
    {
        mag = sqrt(real * real + imag * imag);
        theta = atan(imag / real);
        polar = true;
    }

    double get_mag()
    {
        if (polar == false) calculate_polar();
        return mag;
    }

    double get_theta()
    {
        if (polar == false) calculate_polar();
        return theta;
    }

    double abs()
    {
        return sqrt(real * real + imag * imag);
    }

    Complex operator + (const Complex& c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (const Complex& c)
    {
        return Complex(real - c.real, imag - c.imag);
    }
    
};