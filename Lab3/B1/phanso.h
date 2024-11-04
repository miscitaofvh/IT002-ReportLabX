#include <iostream>

class PhanSo {
private:
    int iTu, iMau;
public:
    PhanSo();
    PhanSo(int num);
    PhanSo(int Tu, int Mau);
    friend PhanSo operator + (const PhanSo u, const PhanSo v);
    friend PhanSo operator - (const PhanSo u, const PhanSo v);
    friend PhanSo operator * (const PhanSo u, const PhanSo v);
    friend PhanSo operator / (const PhanSo u, const PhanSo v);
    bool operator != (const PhanSo& u);
    bool operator == (const PhanSo& u);
    bool operator >= (const PhanSo& u);
    bool operator <= (const PhanSo& u);
    bool operator > (const PhanSo& u);
    bool operator < (const PhanSo& u);
    friend std::istream& operator >> (std::istream& inp, PhanSo& u);
    friend std::ostream& operator << (std::ostream& out, const PhanSo& u);
    void rutgon();
};