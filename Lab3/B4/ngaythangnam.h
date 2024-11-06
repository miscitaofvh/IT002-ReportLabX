#include <iostream>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);

    int TinhNgay() const;

    NgayThangNam operator+(int ngay) const;
    NgayThangNam operator-(int ngay) const;
    int operator-(const NgayThangNam& a) const;

    NgayThangNam& operator++();
    NgayThangNam operator++(int);
    NgayThangNam& operator--();
    NgayThangNam operator--(int);

    bool operator==(const NgayThangNam& a) const;
    bool operator!=(const NgayThangNam& a) const;
    bool operator>=(const NgayThangNam& a) const;
    bool operator<=(const NgayThangNam& a) const;
    bool operator>(const NgayThangNam& a) const;
    bool operator<(const NgayThangNam& a) const;

    friend std::istream& operator>>(std::istream& is, NgayThangNam& a);
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& a);
    friend NgayThangNam operator+(int ngay, const NgayThangNam& a);
    friend NgayThangNam operator-(int ngay, const NgayThangNam& a);
};
