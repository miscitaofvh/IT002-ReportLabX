#ifndef DAGIAC_H
#define DAGIAC_H
#include "diem.h"
class DaGiac {
private:
    int n;
    Diem *Dinh;
public:
    DaGiac(int n = 1);
    DaGiac(const DaGiac& x);
    void Nhap();
    void Xuat();
    float DienTich();
};
#endif