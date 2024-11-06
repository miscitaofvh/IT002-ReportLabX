#include "ngaythangnam.h"
#include <iostream>

// Constructor
NgayThangNam::NgayThangNam() : iNgay(14), iThang(11), iNam(2005) {}

NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) : iNam(Nam), iThang(Thang), iNgay(Ngay) {}

// Helper function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Helper function to get the number of days in a month
int daysInMonth(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 31;
    }
}

// Calculate the total number of days
int NgayThangNam::TinhNgay() const {
    int totalDays = 0;
    for (int y = 1; y < iNam; ++y) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < iThang; ++m) {
        totalDays += daysInMonth(m, iNam);
    }
    totalDays += iNgay;
    return totalDays;
}

// Operator overloading
NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam result = *this;
    result.iNgay += ngay;
    while (result.iNgay > daysInMonth(result.iThang, result.iNam)) {
        result.iNgay -= daysInMonth(result.iThang, result.iNam);
        result.iThang++;
        if (result.iThang > 12) {
            result.iThang = 1;
            result.iNam++;
        }
    }
    return result;
}

NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam result = *this;
    result.iNgay -= ngay;
    while (result.iNgay < 1) {
        result.iThang--;
        if (result.iThang < 1) {
            result.iThang = 12;
            result.iNam--;
        }
        result.iNgay += daysInMonth(result.iThang, result.iNam);
    }
    return result;
}

int NgayThangNam::operator-(const NgayThangNam& a) const {
    return this->TinhNgay() - a.TinhNgay();
}

NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

NgayThangNam NgayThangNam::operator++(int) {
    NgayThangNam temp = *this;
    ++(*this);
    return temp;
}

NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp = *this;
    --(*this);
    return temp;
}

bool NgayThangNam::operator==(const NgayThangNam& a) const {
    return iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam;
}

bool NgayThangNam::operator!=(const NgayThangNam& a) const {
    return !(*this == a);
}

bool NgayThangNam::operator>=(const NgayThangNam& a) const {
    return this->TinhNgay() >= a.TinhNgay();
}

bool NgayThangNam::operator<=(const NgayThangNam& a) const {
    return this->TinhNgay() <= a.TinhNgay();
}

bool NgayThangNam::operator>(const NgayThangNam& a) const {
    return this->TinhNgay() > a.TinhNgay();
}

bool NgayThangNam::operator<(const NgayThangNam& a) const {
    return this->TinhNgay() < a.TinhNgay();
}

std::istream& operator>>(std::istream& is, NgayThangNam& a) {
    is >> a.iNgay >> a.iThang >> a.iNam;
    return is;
}

std::ostream& operator<<(std::ostream& os, const NgayThangNam& a) {
    os << a.iNgay << "/" << a.iThang << "/" << a.iNam;
    return os;
}

NgayThangNam operator+(int ngay, const NgayThangNam& a) {
    return a + ngay;
}

NgayThangNam operator-(int ngay, const NgayThangNam& a) {
    NgayThangNam result = a;
    result.iNgay = ngay - result.iNgay;
    while (result.iNgay < 1) {
        result.iThang--;
        if (result.iThang < 1) {
            result.iThang = 12;
            result.iNam--;
        }
        result.iNgay += daysInMonth(result.iThang, result.iNam);
    }
    return result;
}
