#include "tamgiac.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    TamGiac A;
    cout << "Nhap du lieu cho tam giac: " << endl;
    A.Nhap();
    A.Xuat();
    cout << endl;
    A.TinhTien(101, 110);
    cout << "Tam giac sau khi tinh tien la: "; 
    A.Xuat(); 
    cout << endl;
    A.Quay(90); 
    cout << "Tam giac sau khi xoay 90 do: " << endl; 
    A.Xuat(); 
    cout << endl;
    cout << "Tam giac sau khi phong to la: " << endl; 
    A.PhongTo(10); 
    A.Xuat(); 
    cout << endl;
    cout << "Tam giac sau khi thu nho la: " << endl; 
    A.ThuNho(10); 
    A.Xuat();
    cout << endl;
}