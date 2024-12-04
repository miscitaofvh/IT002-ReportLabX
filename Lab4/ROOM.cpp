#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở Room
class Room {
protected:
    int soDem;

public:
    Room(int soDem) : soDem(soDem) {}

    virtual double TinhDoanhThu() const = 0; 

    virtual ~Room() {}
};

// Lớp Deluxe
class Deluxe : public Room {
private:
    double phiDichVu;
    double phiPhucVu;

public:
    Deluxe(int soDem, double phiDV, double phiPV)
        : Room(soDem), phiDichVu(phiDV), phiPhucVu(phiPV) {}

    double TinhDoanhThu() const override {
        return soDem * 750000 + phiDichVu + phiPhucVu;
    }
};

// Lớp Premium
class Premium : public Room {
private:
    double phiDichVu;

public:
    Premium(int soDem, double phiDV)
        : Room(soDem), phiDichVu(phiDV) {}

    double TinhDoanhThu() const override {
        return soDem * 500000 + phiDichVu;
    }
};

// Lớp Business
class Business : public Room {
public:
    Business(int soDem) : Room(soDem) {}

    double TinhDoanhThu() const override {
        return soDem * 300000;
    }
};

int main() {
    // Khởi tạo 5 phòng
    Deluxe a(5, 200000, 100000);  // 5 đêm, phí dịch vụ 200000, phí phục vụ 100000
    Deluxe b(3, 150000, 80000);   // 3 đêm, phí dịch vụ 150000, phí phục vụ 80000
    Premium c(4, 120000);         // 4 đêm, phí dịch vụ 120000
    Premium d(6, 180000);         // 6 đêm, phí dịch vụ 180000
    Business e(7);                // 7 đêm

    // Tính doanh thu
    double doanhThuDeluxe = a.TinhDoanhThu() + b.TinhDoanhThu();
    double doanhThuPremium = c.TinhDoanhThu() + d.TinhDoanhThu();
    double doanhThuBusiness = e.TinhDoanhThu();
    int doanhThuDeluxeInt = static_cast<int>(doanhThuDeluxe);
    int doanhThuPremiumInt = static_cast<int>(doanhThuPremium);
    int doanhThuBusinessInt = static_cast<int>(doanhThuBusiness);
   

    // Tìm loại phòng có doanh thu cao nhất
    double maxDoanhThu = max(doanhThuDeluxe, max(doanhThuPremium, doanhThuBusiness));
    string loaiPhong;

    if (maxDoanhThu == doanhThuDeluxe)
        loaiPhong = "Deluxe";
    else if (maxDoanhThu == doanhThuPremium)
        loaiPhong = "Premium";
    else
        loaiPhong = "Business";

    // Hiển thị kết quả
    cout << "Doanh thu Deluxe: " << doanhThuDeluxeInt << "\n";
    cout << "Doanh thu Premium: " << doanhThuPremiumInt << "\n";
    cout << "Doanh thu Business: " << doanhThuBusinessInt << "\n";
    cout << "Loai phong co doanh thu cao nhat: " << loaiPhong << "\n";

    return 0;
}
