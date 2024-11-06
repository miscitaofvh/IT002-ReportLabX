#include <iostream>

class ThoiGian
{
private:
    int iGio, iPhut, iGiay;
public:
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay); 
    int TinhGiay() const;
    ThoiGian TinhLaiGio(int) const;
    ThoiGian operator + (const ThoiGian&) const;
    ThoiGian operator - (const ThoiGian&) const;
    friend ThoiGian operator + (const ThoiGian&, int);
    friend ThoiGian operator + (int, const ThoiGian&);
    friend ThoiGian operator - (const ThoiGian&, int);
    friend ThoiGian operator - (int, const ThoiGian&); 
    ThoiGian& operator++();      
    ThoiGian operator++(int);    
    ThoiGian& operator--();
    ThoiGian operator--(int);
    bool operator > (const ThoiGian&) const;
    bool operator < (const ThoiGian&) const;
    bool operator == (const ThoiGian&) const;
    bool operator != (const ThoiGian&) const;
    bool operator >= (const ThoiGian&) const;
    bool operator <= (const ThoiGian&) const;
    friend std::istream& operator >> (std::istream&, ThoiGian&);
    friend std::ostream& operator << (std::ostream&, const ThoiGian&);
};