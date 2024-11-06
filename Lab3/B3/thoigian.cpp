#include "thoigian.h"
#include <iostream>

using namespace std;

ThoiGian::ThoiGian()
{
    iGio = iPhut = iGiay = 0;
}

ThoiGian::ThoiGian(int Gio, int Phut, int Giay)
{
    iGio = Gio;
    iPhut = Phut;
    iGiay = Giay;
}

int ThoiGian::TinhGiay() const
{
    return iGio * 3600 + iPhut * 60 + iGiay;
}

ThoiGian ThoiGian::TinhLaiGio(int s) const
{
    ThoiGian tg;
    tg.iGio = s / 3600;
    tg.iPhut = (s % 3600) / 60;
    tg.iGiay = s % 60;
    return tg;
}

ThoiGian ThoiGian::operator+(const ThoiGian& other) const
{
    ThoiGian tg;
    tg.iGiay = iGiay + other.iGiay;
    tg.iPhut = iPhut + other.iPhut + tg.iGiay / 60;
    tg.iGiay %= 60;
    tg.iGio = iGio + other.iGio + tg.iPhut / 60;
    tg.iPhut %= 60;
    return tg;
}

ThoiGian ThoiGian::operator-(const ThoiGian& other) const
{
    ThoiGian tg;
    tg.iGiay = iGiay - other.iGiay;
    if (tg.iGiay < 0)
    {
        tg.iGiay += 60;
        tg.iPhut--;
    }
    tg.iPhut += iPhut - other.iPhut;
    if (tg.iPhut < 0)
    {
        tg.iPhut += 60;
        tg.iGio--;
    }
    tg.iGio += iGio - other.iGio;
    return tg;
}

ThoiGian operator+(const ThoiGian& time, int s)
{
    ThoiGian tg;
    tg.iGio = time.iGio;
    tg.iPhut = time.iPhut;
    tg.iGiay = time.iGiay + s;
    tg.iPhut += tg.iGiay / 60;
    tg.iGiay %= 60;
    tg.iGio += tg.iPhut / 60;
    tg.iPhut %= 60;
    return tg;
}

ThoiGian operator+(int s, const ThoiGian& time)
{
    return time + s;
}

ThoiGian operator-(const ThoiGian& time, int s)
{
    ThoiGian tg;
    if (time.TinhGiay() - s < 0)
        tg = time.TinhLaiGio(time.TinhGiay() - s + 86400);
    else 
        tg = time.TinhLaiGio(time.TinhGiay() - s);
    return tg;
}

ThoiGian operator-(int s, const ThoiGian& time)
{
    s -= time.TinhGiay();
    if (s < 0)
        s += 86400; 
    return time.TinhLaiGio(s);
}

ThoiGian& ThoiGian::operator++()
{
    ++iGiay;
    if (iGiay == 60)
        ++iPhut, iGiay = 0;
    if (iPhut == 60)
        ++iGio, iPhut = 0;

    return *this;
}

ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

ThoiGian& ThoiGian::operator--()
{
    --iGiay;
    if (iGiay == -1)
        --iPhut, iGiay = 59;
    if (iPhut == -1)
        --iGio, iPhut = 59;

    return *this;
}

ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

bool ThoiGian::operator>(const ThoiGian& other) const
{
    return TinhGiay() > other.TinhGiay();
}

bool ThoiGian::operator<(const ThoiGian& other) const
{
    return TinhGiay() < other.TinhGiay();
}

bool ThoiGian::operator==(const ThoiGian& other) const
{
    return TinhGiay() == other.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& other) const
{
    return TinhGiay() != other.TinhGiay();
}

bool ThoiGian::operator>=(const ThoiGian& other) const
{
    return TinhGiay() >= other.TinhGiay();
}

bool ThoiGian::operator<=(const ThoiGian& other) const
{
    return TinhGiay() <= other.TinhGiay();
}

istream& operator >> (istream& inp, ThoiGian &time)
{
    cout << "Nhap gio: ";
    inp >> time.iGio;
    cout << "Nhap phut: ";
    inp >> time.iPhut;
    cout << "Nhap giay: ";
    inp >> time.iGiay;

    return inp;
}

ostream& operator << (ostream& out, const ThoiGian& time)
{
    out << time.iGio << ':' << time.iPhut << ":" << time.iGiay;
    return out;
}