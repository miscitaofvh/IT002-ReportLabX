#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Lớp cơ sở GiaSuc
class GiaSuc {
protected:
    int soLuong;

public:
    GiaSuc(int soLuong) : soLuong(soLuong) {}

    virtual string TiengKeu() const = 0; // Hàm ảo thuần túy cho tiếng kêu
    virtual int SinhCon() const = 0;    // Hàm ảo thuần túy cho số con sinh
    virtual int ChoSua() const = 0;     // Hàm ảo thuần túy cho sữa

    int LaySoLuong() const { return soLuong; }

    virtual ~GiaSuc() {}
};

// Lớp Bò kế thừa từ GiaSuc
class Bo : public GiaSuc {
public:
    Bo(int soLuong) : GiaSuc(soLuong) {}

    string TiengKeu() const override { return "Bò: Ò... Ò..."; }

    int SinhCon() const override {
        return rand() % 2 + 1; // Mỗi bò sinh 1-2 con
    }

    int ChoSua() const override {
        return rand() % 21; // Sữa: 0-20 lít
    }
};

// Lớp Cừu kế thừa từ GiaSuc
class Cuu : public GiaSuc {
public:
    Cuu(int soLuong) : GiaSuc(soLuong) {}

    string TiengKeu() const override { return "Cừu: Beee..."; }

    int SinhCon() const override {
        return rand() % 3 + 1; // Sinh: 1-3 con
    }

    int ChoSua() const override {
        return rand() % 6; // Sữa: 0-5 lít
    }
};

// Lớp Dê kế thừa từ GiaSuc
class De : public GiaSuc {
public:
    De(int soLuong) : GiaSuc(soLuong) {}

    string TiengKeu() const override { return "Dê: Eeee..."; }

    int SinhCon() const override {
        return rand() % 2 + 1; // Sinh: 1-2 con
    }

    int ChoSua() const override {
        return rand() % 11; // Sữa: 0-10 lít
    }
};

int main() {
    srand(time(0)); // Khởi tạo seed ngẫu nhiên

    // Nhập số lượng gia súc ban đầu
    int soBo, soCuu, soDe;
    cout << "Nhap so luong bo: ";
    cin >> soBo;
    cout << "Nhap so luong cuu: ";
    cin >> soCuu;
    cout << "Nhap so luong de: ";
    cin >> soDe;

    // Khởi tạo các đối tượng
    Bo bo(soBo);
    Cuu cuu(soCuu);
    De de(soDe);

    cout << "\nTieng keu trong nong trai khi doi an:\n";
    if (soBo > 0) cout << bo.TiengKeu() << "\n";
    if (soCuu > 0) cout << cuu.TiengKeu() << "\n";
    if (soDe > 0) cout << de.TiengKeu() << "\n";

    int tongSoLuong = soBo + soCuu + soDe;
    int tongSua = 0;

    // Tính tổng số gia súc và tổng sữa
    for (int i = 0; i < soBo; i++) {
        tongSoLuong += bo.SinhCon();
        tongSua += bo.ChoSua();
    }

    for (int i = 0; i < soCuu; i++) {
        tongSoLuong += cuu.SinhCon();
        tongSua += cuu.ChoSua();
    }

    for (int i = 0; i < soDe; i++) {
        tongSoLuong += de.SinhCon();
        tongSua += de.ChoSua();
    }

    // In kết quả
    cout << "\nThong ke sau mot luot sinh va cho sua:\n";
    cout << "Tong so luong gia suc: " << tongSoLuong << "\n";
    cout << "Tong luong sua thu duoc: " << tongSua << " lit\n";

    return 0;
}
