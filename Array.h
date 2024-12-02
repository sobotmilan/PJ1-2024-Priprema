#pragma once
#include "Complex.h"

class Array
{
    int length, capacity;
    /*
    length = trenutni broj elemenata (zadnji element se nalazi na data[length-1])
    capacity = maksimalan broj elemenata koji trenutno moze stati u red
    */
    Complex *data;

public:
    Array(int initialCapacity = 1); // podrazumijevano neprazan niz
    Array(const Array &) = delete;  // onemoguceno kopiranje u svakom kontekstu: i kopirajuca konstrukcija i kopirajuca dodjela
    Array(Array &&);                // ali omogucena pomjerajuca konstrukcija, kao i pomjerajuca dodjela
    ~Array();

    int getLength() const;
    int getCapacity() const;

    void append(const Complex &);
    void resize(int newCapacity);
    void dispose();

    Complex &at(int index);             // posto se u tekstu trazi mogucnost mijenjanja dohvacenog elementa liste, nemamo const iza zagrade.
    const Complex &at(int index) const; // trazeno je funkcionisanje i u konstantnom kontekstu, ali ovdje promjena nece biti, ovo je samo za pristup.

    void transform(Complex (*)(Complex)); // obratiti paznju, u tekstu nije nigdje pomenuto da se prosljedjuje referenca u ovu (*) funkciju, znaci dobro razmisliti kako ce bezimena funkc izgledati u mainu
    void transform(Complex (*)(Complex)) const;

    Array &operator=(const Array &) = delete; // opet, onemogucena kopirajuca dodjela
    Array &operator=(Array &&);               // opet,omogucena pomjerajuca dodjela
};

std::ostream &operator<<(std::ostream &os, const Array &);