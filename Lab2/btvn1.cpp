#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo(int _tu = 0, int _mau = 1)
    {
        tu = _tu;
        mau = _mau;

        if (mau == 0) mau = 1;
    }
    
    // Dinh nghia >> de nhap phan so
    friend istream& operator>>(istream& inp, PhanSo& u)
    {
        cout << "Nhap tu so: ";
        inp >> u.tu;
        cout << "Nhap mau so: ";
        inp >> u.mau;

        while (u.mau == 0)
        {
            cout << "Mau so cua phan so khong the bang 0. Nhap lai: ";
            inp >> u.mau;
        }

        return inp;
    }

    // Dinh nghia << de xuat ra phan so 
    friend ostream& operator<<(ostream& out, const PhanSo& u) 
    {
        out << u.tu << '/' << u.mau << endl;
        return out;  
    }

    // Dinh nghia dau be hon
    bool operator < (const PhanSo& u) const
    {
        return tu * u.mau < mau * u.tu;
    }

    // Dinh nghia dau lon hon
    bool operator > (const PhanSo& u) const
    {
        return tu * u.mau > mau * u.tu;
    }
};

vector<PhanSo> a;
int n;

int main()
{
    cout << "Nhap so luong phan so: "; 
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; ++i) 
    {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        cin >> a[i];
    }

    cout << "Phan so lon nhat la: " << *max_element(a.begin(), a.end());
    cout << "Phan so be nhat la: " << *min_element(a.begin(), a.end());
    return 0;
}