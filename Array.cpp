#include "Array.h"
#include "Complex.h"
#include <climits>
#include <iostream>
using namespace std;

static Complex ERROR(INT_MIN, INT_MIN);
// signalizator gresaka

Array::Array(int initialCapacity) : capacity(initialCapacity), length(0)
{
    // dodatna rigoroznost ako se proslijedi kapacitet koji je <=0 pri pozivu konstruktora
    if (initialCapacity < 0)
        this->capacity = 0;
    this->data = new Complex[capacity];
}
Array::Array(Array &&other) : capacity(other.capacity), length(other.length), data(other.data)
{
    // pomjerajuci konstruktor, moramo nulirati "other" koji je koristen za konstrukciju
    other.data = nullptr;
    other.capacity = 0;
    other.length = 0;
}
Array::~Array()
{
    // destruktor
    this->dispose();
    this->capacity = 0;
    this->length = 0;
}
void Array::dispose()
{
    // pomocna funkcija da preuzme proces dealokacije
    delete[] this->data;
    this->data = nullptr;
}
int Array::getLength() const
{
    return this->length;
}
int Array::getCapacity() const
{
    return this->capacity;
}
void Array::append(const Complex &other)
{
    if (this->length >= this->capacity)
        this->resize(this->capacity * 2);
    this->data[this->length++] = other;
}
void Array::resize(int newCapacity)
{
    if (this->capacity == 0)
        newCapacity = 1;
    /*
    zasto postoji ova linija iznad? zato sto sam u parametrizovanom konstruktoru omogucio prosljedjivanje inicijalnog kapaciteta manjeg od 1 (kapacitet moze biti jednak 0), pa ako se u takav niz pokusa dodati novi element, mora kapacitet postati 1, inace (this->capacity *2) nema efekta kad je capacity = 0.
    */

    Complex *temp = new Complex[newCapacity];
    this->length = (this->capacity > newCapacity) ? newCapacity : this->length;
    for (int i = 0; i < this->length; i++)
        temp[i] = this->data[i];
    this->dispose();
    this->data = temp;
    this->capacity = newCapacity;
}
Complex &Array::at(int index)
{
    if (index > -1 && index < this->length)
        return this->data[index];
    else
        return ERROR;
}
const Complex &Array::at(int index) const
{
    if (index > -1 && index < this->length)
        return this->data[index];
    else
        return ERROR;
}
void Array::transform(Complex (*f)(Complex))
{
    for (int i = 0; i < this->length; i++)
        this->data[i] = (*f)(this->data[i]);
}
void Array::transform(Complex (*f)(Complex)) const
{
    for (int i = 0; i < this->length; i++)
        this->data[i] = (*f)(this->data[i]);
}
Array &Array::operator=(Array &&other)
{
    if (this == &other)
        return *this;

    this->capacity = other.capacity;
    this->length = other.length;

    this->data = other.data;

    other.data = nullptr;

    other.capacity = 0;
    other.length = 0;

    return *this;
}
std::ostream &operator<<(std::ostream &os, const Array &other)
{
    os << "[  ";
    for (int i = 0; i < other.getLength(); i++)
        os << other.at(i) << "  ";
    os << "]";
    return os;
}