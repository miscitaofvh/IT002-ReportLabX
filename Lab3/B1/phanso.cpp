#include "phanso.h"
#include <iostream>

using namespace std;

PhanSo::PhanSo() {
    iTu = 0;
    iMau = 1;
};
PhanSo::PhanSo(int num)
{
    this->iTu = num;
    this->iMau = 1;
};
PhanSo::PhanSo(int Tu, int Mau) {
    this->iTu = Tu;
    this->iMau = Mau + (Mau == 0);
    rutgon();
};
PhanSo operator + (const PhanSo u, const PhanSo v)
{
    return PhanSo(u.iTu * v.iMau + u.iMau * v.iTu, u.iMau * v.iMau);
};
PhanSo operator - (const PhanSo u, const PhanSo v)
{
    return PhanSo(u.iTu * v.iMau - u.iMau * v.iTu, u.iMau * v.iMau);
};
PhanSo operator * (const PhanSo u, const PhanSo v)
{
    return PhanSo(u.iTu * v.iTu, u.iMau * v.iMau);
};
PhanSo operator / (const PhanSo u, const PhanSo v)
{
    if (v.iTu == 0) 
        throw std::invalid_argument("Khong the chia bang 0!");
    return PhanSo(u.iTu * v.iMau, u.iMau * v.iTu);
};
bool PhanSo::operator != (const PhanSo& u)
{
    return (iTu * u.iMau != iMau * u.iTu);
};
bool PhanSo::operator == (const PhanSo& u)
{
    return (iTu * u.iMau == iMau * u.iTu);
};
bool PhanSo::operator >= (const PhanSo& u)
{
    return (iTu * u.iMau >= iMau * u.iTu);
};
bool PhanSo::operator <= (const PhanSo& u)
{
    return (iTu * u.iMau <= iMau * u.iTu);
};
bool PhanSo::operator > (const PhanSo& u)
{
    return (iTu * u.iMau > iMau * u.iTu);
};
bool PhanSo::operator < (const PhanSo& u)
{
    return (iTu * u.iMau < iMau * u.iTu);
};
std::istream& operator >> (std::istream& inp, PhanSo& u)
{
    inp >> u.iTu >> u.iMau;
    u.rutgon();
    return inp;
};
std::ostream& operator << (std::ostream& out, const PhanSo& u)
{
    if (u.iMau == 1)
        out << u.iTu;
    else 
        out << u.iTu << '/' << u.iMau;
    return out;
};
void PhanSo::rutgon()
{
    int a = this->iTu;
    int b = this->iMau;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    this->iTu /= a;
    this->iMau /= a;

    if (this->iMau < 0)
        this->iTu *= -1, 
        this->iMau *= -1;
};