#pragma once
#include <iostream>
using namespace std;

class Complex
{
    double re, im;

public:
    Complex(double re = 0.0, double im = 0.0);
    ~Complex();
    double getRe() const;
    double getIm() const;
    Complex operator=(const Complex &);
    Complex operator+(const Complex &) const;
    const Complex operator+(const Complex &);
};

std::ostream &operator<<(std::ostream &os, const Complex &);