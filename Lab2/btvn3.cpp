#include <bits/stdc++.h>

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
        out << u.tu << '/' << u.mau;
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

    bool operator == (const PhanSo& u) const
    {
        return tu * u.mau == mau * u.tu;
    }
    
    // Dinh nghia dau *
    PhanSo operator * (const PhanSo& u)
    {
        return PhanSo(tu * u.tu, mau * u.mau);        
    }

    // Dinh nghia dau *=
    void operator *= (const PhanSo& u)
    {
        tu *= u.tu;
        mau *= u.mau;
    }
};

vector<PhanSo> a, res;
int n, ans = -1;
PhanSo k;

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
    
    cout << "Nhap phan so dich: " << endl;
    cin >> k;

    if (k == PhanSo()) return 0;

    for (int mask = 1; mask < (1 << n); ++mask)
    {
        PhanSo product = PhanSo(1, 1);
        for (int i = 0; i < n; ++i) 
            if ((mask >> i) & 1)
                product *= a[i];

        if (product == k)
        {
            if (ans == -1 || __builtin_popcount(mask) < __builtin_popcount(ans))
                ans = mask;
        }
    }

    for (int i = 0; i < n; ++i) 
        if ((ans >> i) & 1)
            res.push_back(a[i]);

    if (res.size())
    {
        sort(res.begin(), res.end());
        cout << "Danh sach cac phan so co tich bang phan so dich la: ";

        for (auto v : res)
            cout << v << " ";

        cout << endl;
    }

    return 0;
}