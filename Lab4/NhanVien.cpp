#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở NhanVien
class NhanVien {
protected:
    string maSo;
    string ten;
    double luongCoBan;

public:
    NhanVien(const string& ms = "", const string& t = "", double lcb = 0)
        : maSo(ms), ten(t), luongCoBan(lcb) {}

    virtual double TienThuong() const = 0; // Hàm ảo thuần túy để tính tiền thưởng

    virtual void Xuat() const {
        cout << "Ma so: " << maSo << "\n"
             << "Ten: " << ten << "\n"
             << "Luong co ban: " << luongCoBan << "\n";
    }

    virtual ~NhanVien() {}
};

// Lớp Quản lý
class QuanLy : public NhanVien {
private:
    double tyLeThuong;

public:
    QuanLy(const string& ms, const string& t, double lcb, double tlt)
        : NhanVien(ms, t, lcb), tyLeThuong(tlt) {}

    double TienThuong() const override {
        return static_cast<int>(luongCoBan * tyLeThuong);
    }

    void Xuat() const override {
        NhanVien::Xuat();
        cout << "Ty le thuong: " << tyLeThuong << "\n"
             << "Tien thuong: " << static_cast<int>(TienThuong()) << "\n";
    }
};;

// Lớp Kỹ sư
class KySu : public NhanVien {
private:
    int soGioLamThem;

public:
    KySu(const string& ms, const string& t, double lcb, int sglt)
        : NhanVien(ms, t, lcb), soGioLamThem(sglt) {}

    double TienThuong() const override {
        return soGioLamThem * 100000;
    }

    void Xuat() const override {
        NhanVien::Xuat();
        cout << "So gio lam them: " << soGioLamThem << "\n"
             << "Tien thuong: " << static_cast<int>(TienThuong()) << "\n";
    }
};

int main() {
    // Nhập thông tin quản lý
    string maQL, tenQL;
    double luongCoBanQL, tyLeThuong;
    cout << "Nhap thong tin Quan Ly:\n";
    cout << "Ma so: "; cin >> maQL;
    cout << "Ten: "; cin.ignore(); getline(cin, tenQL);
    cout << "Luong co ban: "; cin >> luongCoBanQL;
    cout << "Ty le thuong: "; cin >> tyLeThuong;
    QuanLy quanLy(maQL, tenQL, luongCoBanQL, tyLeThuong);

    // Nhập thông tin kỹ sư
    string maKS, tenKS;
    double luongCoBanKS;
    int soGioLamThem;
    cout << "\nNhap thong tin Ky Su:\n";
    cout << "Ma so: "; cin >> maKS;
    cout << "Ten: "; cin.ignore(); getline(cin, tenKS);
    cout << "Luong co ban: "; cin >> luongCoBanKS;
    cout << "So gio lam them: "; cin >> soGioLamThem;
    KySu kySu(maKS, tenKS, luongCoBanKS, soGioLamThem);

    // Hiển thị thông tin
    cout << "\nThong tin Quan Ly:\n";
    quanLy.Xuat();

    cout << "\nThong tin Ky Su:\n";
    kySu.Xuat();

    return 0;
}
