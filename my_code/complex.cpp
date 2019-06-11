#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
    return true;  // temp!
}

ostream& operator<< (ostream& os, const Complex& c)
{
    os << "Real: " << c.get_real() << " Imag: " << c.get_imag();
    return os;
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c)
{
    double real, imag;
    is >> real >> imag;
    c.real = real;
    c.imag = imag;
    return is;
}


Complex::operator bool() const
{
    if (real == 0 && imag == 0) return false;
    return true;
}

Complex& Complex::operator++()
{
    real++;
    return *this;
}

Complex Complex::operator++(int dummy)
{
    Complex temp = *this;
    imag++;
    return temp;
}

Complex Complex::operator+(const Complex& c)
{
    return Complex(real + c.get_real(), imag + c.get_imag());
}

double Complex::get_real() const
{
    return real;
}

double Complex::get_imag() const
{
    return imag;
}

Complex Complex::operator*(const int i)
{
    return Complex(real*i, imag*i);

}

