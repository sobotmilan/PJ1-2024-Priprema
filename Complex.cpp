#include "Complex.h"

Complex::Complex(double re, double im) : re(re), im(im)
{
}
Complex::~Complex()
{
}
double Complex::getRe() const
{
    return this->re;
}
double Complex::getIm() const
{
    return this->im;
}
Complex Complex::operator+(const Complex &other) const
{
    return Complex(this->re + other.re, this->im + other.im);
}
const Complex Complex::operator+(const Complex &other)
{
    return Complex(this->re + other.re, this->im + other.im);
}
Complex Complex::operator=(const Complex &other)
{
    this->re = other.re;
    this->im = other.im;
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Complex &other)
{
    os << other.getRe() << (other.getIm() >= 0 ? "+" : "") << other.getIm() << "i";
    return os;
}