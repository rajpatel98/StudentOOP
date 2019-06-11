#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

Complex::Complex(double real, double imag): real(real), imag(imag){}



ostream& operator<< (ostream& os, const Complex& c)
{
    os << "Real: " << c.real << " Imag: " << c.imag;
    return os;
}

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
    real++;
    return temp;
}

Complex& Complex::operator--()
{
    real--;
    return *this;

}

Complex Complex::operator--(int dummy)
{
    Complex temp = *this;
    real--;
    return temp;
}

Complex Complex::operator-=(const Complex& c)
{
    real-=c.real;
    imag-=c.imag;
    return *this;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
    return Complex(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag());
}

bool operator== (const Complex& c1, const Complex& c2)
{
    if (c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag())
    {
        return true;
    }
    return false;
}

bool operator!= (const Complex& c1, const Complex& c2)
{
    return !(c1==c2);
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

