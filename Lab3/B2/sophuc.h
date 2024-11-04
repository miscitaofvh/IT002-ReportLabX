#ifndef SOPHUC_H
#define SOPHUC_H

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    SoPhuc();
    SoPhuc(double thuc, double ao);

    // Getter and Setter
    double getThuc() const;
    void setThuc(double thuc);
    double getAo() const;
    void setAo(double ao);

    // Operator overloading
    SoPhuc operator+(const SoPhuc& other) const;
    SoPhuc operator-(const SoPhuc& other) const;
    SoPhuc operator*(const SoPhuc& other) const;
    SoPhuc operator/(const SoPhuc& other) const;

    // Friend functions for input and output
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
};

#endif // SOPHUC_H