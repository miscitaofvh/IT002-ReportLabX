#include "phanso.h"
#include <iostream>

using namespace std;

int main()
{
    PhanSo A, B;
    cout << "Nhap phan so thu nhat: ";
    cin >> A;
    cout << "Nhap phan so thu hai: ";
    cin >> B;
    PhanSo C(2, 3);

    cout << "Phan so C la: " << C << endl;
    cout << "Tong hai phan so la: " << A + B << endl;
    cout << "Hieu hai phan so la: " << A - B << endl;
    cout << "Tich hai phan so la: " << A * B << endl;
    cout << "Thuong hai phan so la: " << A / B << endl;
    cout << "A + 1411 = " << A + 1411 << endl;
    cout << "1411 + A = " << 1411 + A << endl;
    cout << "B - 1411 = " << B + 1411 << endl;
    cout << "1411 - B = " << 1411 - B << endl;
    cout << "A * 1411 = " << A * 1411 << endl;
    cout << "1411 * A = " << 1411 * A << endl;
    cout << "B / 1411 = " << B / 1411 << endl;
    cout << "1411 / B = " << 1411 / B << endl;

    if (A == B) 
        cout << "Phan so A va B bang nhu" << endl;
    if (A != B) 
        cout << "Phan So A va B khac nhau" << endl;
    if (A >= C) 
        cout << "Phan so A lon hon hoac bang phan so C" << endl;
    if (A <= C) 
        cout << "Phan so A be hon hoac bang phan so C" << endl;
    if (B > A)
        cout << "Phan so B lon hon phan so A" << endl;
    if (B < A) 
        cout << "Phan so B be hon phan so A" << endl;

    return 0;
}