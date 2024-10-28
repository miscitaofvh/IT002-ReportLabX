#include "dagiac.h"
#include <bits/stdc++.h>

using namespace std;

DaGiac::DaGiac(int n) {
    this->n = n;
    Dinh = new Diem[n];
}
DaGiac::DaGiac(const DaGiac& x) {
    n = x.n;
    Dinh = new Diem[n];
    for(int i = 0; i < n; i++) Dinh[i] = x.Dinh[i];
}
void DaGiac::Nhap() {
    Diem tmp;
    cout << "Nhap so dinh cua da giac: "; 
    cin >> n;
    Dinh = new Diem[n];
    for(int i = 0; i < n; i++) 
    {
        cout << "Nhap toa do dinh thu " << i + 1 << endl;
        cin >> tmp.iHoanh >> tmp.iTung;
        Dinh[i] = tmp; 
    }
}
void DaGiac::Xuat() {
    for(int i = 0; i < n; i++) 
        Dinh[i].Xuat();
    cout << endl;
}
void DaGiac::TinhTien(float x, float y) {
    for(int i = 0; i < n; i++) 
    {
        Dinh[i].iHoanh = Dinh[i].iHoanh + x;
        Dinh[i].iTung = Dinh[i].iTung + y;
    }
}
void DaGiac::PhongTo(float k) {
    for(int i = 0; i < n; i++) 
    {
        Dinh[i].iHoanh = Dinh[i].iHoanh * k;
        Dinh[i].iTung = Dinh[i].iTung * k;
    }
}
void DaGiac::ThuNho(float k) {
    PhongTo(1/k);
}
void DaGiac::Quay(float goc) {
    float rad = goc*M_PI/180;
    for(int i=0; i<n; i++) 
    {
        Dinh[i].iHoanh = Dinh[i].iHoanh * cos(rad) - Dinh[i].iTung * sin(rad);
        Dinh[i].iTung = Dinh[i].iHoanh * sin(rad) + Dinh[i].iTung * cos(rad);
    }
}