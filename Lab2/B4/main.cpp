#include "thisinh.h"
#include<iostream>

int main() {
    int n; 
    cout << "Nhap so luong thi sinh: "; 
    cin >> n;
    vector<ThiSinh> a(n);

    // Nhap thong tin cho tung thi sinh
    for(int i=0; i<n; i++)
    {
        cout << "Nhap thong tin cua thi sinh thu " << i+1 << ": " << endl;
        a[i].Nhap();
    }

    // Thong tin cac thi sinh co tong diem lon hon 15
    cout << "Danh sach thi sinh co tong diem lon hon 15: " << endl;
    for(int i=0; i<n; i++) 
    {
        if(a[i].Tong() > 15) a[i].Xuat();
    }
    // Thi sinh co tong diem cao nhat
    float maxx = a[0].Tong();
    int idx = 0;
    for(int i=1; i<n; i++) 
    {
        if(a[i].Tong() > maxx) 
        {
            maxx = a[i].Tong();
            idx = i;
        }
    }
    cout << "Thi sinh co tong diem cao nhat la:" << endl;
    a[idx].Xuat();
}