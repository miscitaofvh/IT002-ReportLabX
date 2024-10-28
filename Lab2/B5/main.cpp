#include "diem.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    Diem A;
    int n; 

    A.Nhap();
    cin >> n;

    // Xu li cac truy van
    for (int x, i = 0; i < n; i++) 
    {
        cin >> x;

        switch (x)
        {
        case 1:
            A.NhanDoi();
            break;
        case 2:
            A.Reset();
            break;
        case 3:
            int k; float x;
            cin >> k >> x;
            A.TinhTien(k, x);
            break;
        default:
            break;
        }
    }

    A.Xuat();

    return 0;
}