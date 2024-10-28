#ifndef TAMGIAC_H
#define TAMGIAC_H
#include "diem.h"

class TamGiac {
private:
    Diem A, B, C;
public:
    TamGiac(Diem A = Diem(), Diem B = Diem(), Diem C = Diem());
    void Xuat();
    void Nhap();
    void TinhTien(float x, float y);
    void Quay(float goc);
    void PhongTo(float k);
    void ThuNho(float k);
};
#endif