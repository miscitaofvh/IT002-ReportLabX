#include "dagiac.h"
#include <bits/stdc++.h> 

using namespace std;

int main() {
    DaGiac A;
    A.Nhap();

    cout << "Toa do cac dinh cua do giac: " << endl; 
    A.Xuat();
    A.TinhTien(101, 110);
    cout << "Da giac sau khi tinh tien la: " << endl; 
    A.Xuat();
    A.PhongTo(10);
    cout << "Da giac sau khi phong to la: " << endl; 
    A.Xuat();
    A.ThuNho(4);
    cout << "Da giac sau khi thu nho la: " << endl; 
    A.Xuat();
    A.Quay(90);
    cout << "Da giac sau khi quay 90 do la: " << endl; 
    A.Xuat();
    return 0;
}