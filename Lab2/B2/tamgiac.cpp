#include "tamgiac.h"
#include <bits/stdc++.h>

using namespace std;

TamGiac::TamGiac(Diem A, Diem B, Diem C) {
    this->A = A;
    this->B = B;
    this->C = C;
}

void TamGiac::Xuat() {
    cout << "Toa do cac diem cua tam giac: ";
    cout << " (" << A.GetHoanhDo() << " ," << A.GetTungDo() << ")";
    cout << " (" << B.GetHoanhDo() << " ," << B.GetTungDo() << ")";
    cout << " (" << C.GetHoanhDo() << " ," << C.GetTungDo() << ")";
}
void TamGiac::Nhap() {
    Diem tmp;

    cout << "Nhap toa do diem A: ";
    cin >> tmp.iHoanh;
    cin >> tmp.iTung;
    A = Diem(tmp);
    cout << "Nhap toa do diem B: ";
    cin >> tmp.iHoanh;
    cin >> tmp.iTung;
    B = Diem(tmp);
    cout << "Nhap toa do diem C: ";
    cin >> tmp.iHoanh;
    cin >> tmp.iTung;
    C = Diem(tmp);
}
void TamGiac::TinhTien(float x, float y) {
    A.TinhTien(x, y);
    B.TinhTien(x, y);
    C.TinhTien(x, y);
}
void TamGiac::Quay(float goc) {
    float rad = goc*M_PI/180;
    float xA = A.iHoanh, yA = A.iTung;
    float xB = B.iHoanh, yB = B.iTung;
    float xC = C.iHoanh, yC = C.iTung;
    
    A.iHoanh = xA * cos(rad) - yA * sin(rad);
    A.iTung = xA * sin(rad) + yA * cos(rad);
    B.iHoanh = xB * cos(rad) - yB * sin(rad);
    B.iTung = xB * sin(rad) + yB * cos(rad);
    C.iHoanh = xC * cos(rad) - yC * sin(rad);
    C.iTung = xC * sin(rad) + yC * cos(rad);
}
void TamGiac::PhongTo(float k) {
    A.iHoanh = A.iHoanh*k;
    A.iTung = A.iTung*k;
    B.iHoanh = B.iHoanh*k;
    B.iTung = B.iTung*k;
    C.iHoanh = C.iHoanh*k;
    C.iTung = C.iTung*k;
}
void TamGiac::ThuNho(float k) {
    PhongTo(1/k);
}