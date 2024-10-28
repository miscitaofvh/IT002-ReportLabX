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
    cin >> n;
    Dinh = new Diem[n];
    for(int i = 0; i < n; i++) 
    {
        cin >> tmp.iHoanh >> tmp.iTung;
        Dinh[i] = tmp; 
    }
}

void DaGiac::Xuat() {
    for(int i = 0; i < n; i++) 
        Dinh[i].Xuat();
    cout << endl;
}

float DaGiac::DienTich() {
    float s = 0;
    for(int i = 0; i < n; i++) 
    {
        s += Dinh[i].iHoanh * Dinh[(i + 1) % n].iTung - Dinh[i].iTung * Dinh[(i + 1) % n].iHoanh;
    }
    return abs(s) / 2; 
}