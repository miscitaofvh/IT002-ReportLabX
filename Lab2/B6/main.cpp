#include "Diem.h"
#include <iostream>
using namespace std;

int main() {
    Diem A, B, C;
    A.Nhap(); 
    B.Nhap(); 
    C.Nhap();
    float goc, d;
    cin >> goc >> d;
    
    A.TinhTien(goc, d);
    B.TinhTien(goc, d);
    C.TinhTien(goc, d);

    A.Xuat(); B.Xuat(); C.Xuat();
    return 0;
}