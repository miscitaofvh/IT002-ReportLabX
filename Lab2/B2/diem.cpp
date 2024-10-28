#include "diem.h"
#include <bits/stdc++.h>

using namespace std;

Diem::Diem() {
    iHoanh = 0;
    iTung = 0;
};

Diem::Diem(float iHoanh, float iTung) {
    this->iHoanh = iHoanh;
    this->iTung = iTung;
};

Diem::Diem(const Diem&x) {
    this->iHoanh = x.iHoanh;
    this->iTung = x.iTung;
};

void Diem::Xuat() {
    cout << "Toa do la: (" << iHoanh << "," << iTung << ")" << endl;
}

float Diem::GetTungDo() {
    return iTung;
}

float Diem::GetHoanhDo() {
    return iHoanh;
}

void Diem::SetTungDo(float iTung) {
    this->iTung = iTung;
}

void Diem::SetHoanhDo(float iHoanh) {
    this->iHoanh = iHoanh;
}

void Diem::TinhTien(float x, float y) {
    iHoanh += x;
    iTung += y;
}