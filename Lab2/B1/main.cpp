#include "diem.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    Diem A; 
    Diem B(1411, 2005);
    Diem C(B);

    A.Xuat();
    B.Xuat();
    C.Xuat();
    
    A.SetHoanhDo(3);
    A.SetTungDo(4);
   
    cout << "Hoanh do cua A: " << A.GetHoanhDo() << endl;
    cout << "Tung do cua A: " << A.GetTungDo() << endl;
   
    B.TinhTien(101, 110);
    cout << "Toa do cua B sau khi tinh tien la: "; 
    B.Xuat();
       
    return 0;
}