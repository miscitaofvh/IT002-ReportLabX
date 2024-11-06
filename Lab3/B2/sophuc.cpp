#include "sophuc.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

SoPhuc::SoPhuc(int thuc, int ao) : dThuc(thuc), dAo(ao) {}

// Getter for the real part
int SoPhuc::getThuc() const {
    return dThuc;
}

// Getter for the imaginary part
int SoPhuc::getAo() const {
    return dAo;
}

// Setter for the real part
void SoPhuc::setThuc(int thuc) {
    dThuc = thuc;
}

// Setter for the imaginary part
void SoPhuc::setAo(int ao) {
    dAo = ao;
}

// Addition of two complex numbers
SoPhuc SoPhuc::operator+(const SoPhuc& other) const {
    return SoPhuc(dThuc + other.dThuc, dAo + other.dAo);
}

// Subtraction of two complex numbers
SoPhuc SoPhuc::operator-(const SoPhuc& other) const {
    return SoPhuc(dThuc - other.dThuc, dAo - other.dAo);
}

// Multiplication of two complex numbers
SoPhuc SoPhuc::operator*(const SoPhuc& other) const {
    return SoPhuc(dThuc * other.dThuc - dAo * other.dAo, dThuc * other.dAo + dAo * other.dThuc);
}

// Division of two complex numbers
SoPhuc SoPhuc::operator/(const SoPhuc& other) const {
    int denominator = other.dThuc * other.dThuc + other.dAo * other.dAo;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return SoPhuc((dThuc * other.dThuc + dAo * other.dAo) / denominator, (dAo * other.dThuc - dThuc * other.dAo) / denominator);
}

// Equality operator
bool SoPhuc::operator==(const SoPhuc& other) const {
    return dThuc == other.dThuc && dAo == other.dAo;
}

// Inequality operator
bool SoPhuc::operator!=(const SoPhuc& other) const {
    return !(*this == other);
}

// Overloading the insertion operator for output
ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.dThuc << " + " << sp.dAo << "i";
    return os;
}

// Overloading the extraction operator for input
istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "Enter the real part: ";
    is >> sp.dThuc;
    cout << "Enter the imaginary part: ";
    is >> sp.dAo;
    return is;
}

// Additional operator overloading for int + SoPhuc and SoPhuc + int
SoPhuc operator+(int lhs, const SoPhuc& rhs) {
    return SoPhuc(lhs + rhs.dThuc, rhs.dAo);
}

SoPhuc operator+(const SoPhuc& lhs, int rhs) {
    return SoPhuc(lhs.dThuc + rhs, lhs.dAo);
}

SoPhuc operator-(int lhs, const SoPhuc& rhs) {
    return SoPhuc(lhs - rhs.dThuc, -rhs.dAo);
}

SoPhuc operator-(const SoPhuc& lhs, int rhs) {
    return SoPhuc(lhs.dThuc - rhs, lhs.dAo);
}

SoPhuc operator*(int lhs, const SoPhuc& rhs) {
    return SoPhuc(lhs * rhs.dThuc, lhs * rhs.dAo);
}

SoPhuc operator*(const SoPhuc& lhs, int rhs) {
    return SoPhuc(lhs.dThuc * rhs, lhs.dAo * rhs);
}

SoPhuc operator/(int lhs, const SoPhuc& rhs) {
    int denominator = rhs.dThuc * rhs.dThuc + rhs.dAo * rhs.dAo;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return SoPhuc((lhs * rhs.dThuc) / denominator, (-lhs * rhs.dAo) / denominator);
}

SoPhuc operator/(const SoPhuc& lhs, int rhs) {
    if (rhs == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return SoPhuc(lhs.dThuc / rhs, lhs.dAo / rhs);
}