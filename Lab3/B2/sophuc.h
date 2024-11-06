#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>

class SoPhuc {
private:
    int dThuc;
    int dAo;

public:
    SoPhuc();
    SoPhuc(int thuc, int ao);

    // Getter and Setter
    int getThuc() const;
    void setThuc(int thuc);
    int getAo() const;
    void setAo(int ao);

    // Operator overloading
    SoPhuc operator+(const SoPhuc& other) const;
    SoPhuc operator-(const SoPhuc& other) const;
    SoPhuc operator*(const SoPhuc& other) const;
    SoPhuc operator/(const SoPhuc& other) const;
    bool operator==(const SoPhuc& other) const;
    bool operator!=(const SoPhuc& other) const;

    // Friend functions for input and output
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);

    // Additional operator overloading for int + SoPhuc and SoPhuc + int
    friend SoPhuc operator+(int lhs, const SoPhuc& rhs);
    friend SoPhuc operator+(const SoPhuc& lhs, int rhs);
    friend SoPhuc operator-(int lhs, const SoPhuc& rhs);
    friend SoPhuc operator-(const SoPhuc& lhs, int rhs);
    friend SoPhuc operator*(int lhs, const SoPhuc& rhs);
    friend SoPhuc operator*(const SoPhuc& lhs, int rhs);
    friend SoPhuc operator/(int lhs, const SoPhuc& rhs);
    friend SoPhuc operator/(const SoPhuc& lhs, int rhs);
};

#endif // SOPHUC_H