#include "ngaythangnam.h"
#include <iostream>

int main() {
    // Create instances of NgayThangNam
    NgayThangNam date1(2023, 10, 15);
    NgayThangNam date2(2022, 5, 10);

    // Display the dates
    std::cout << "Date 1: " << date1 << std::endl;
    std::cout << "Date 2: " << date2 << std::endl;

    // Calculate total days
    std::cout << "Total days in Date 1: " << date1.TinhNgay() << std::endl;
    std::cout << "Total days in Date 2: " << date2.TinhNgay() << std::endl;

    // Add and subtract days
    NgayThangNam date3 = date1 + 20;
    NgayThangNam date4 = date2 - 15;
    std::cout << "Date 1 + 20 days: " << date3 << std::endl;
    std::cout << "Date 2 - 15 days: " << date4 << std::endl;

    // Demonstrate int + NgayThangNam and int - NgayThangNam
    NgayThangNam date5 = 30 + date1;
    NgayThangNam date6 = 30 - date2;
    std::cout << "30 + Date 1: " << date5 << std::endl;
    std::cout << "30 - Date 2: " << date6 << std::endl;

    // Difference between two dates
    int diff = date1 - date2;
    std::cout << "Difference between Date 1 and Date 2: " << diff << " days" << std::endl;

    // Increment and decrement operators
    std::cout << "Date 1 before increment: " << date1 << std::endl;
    ++date1;
    std::cout << "Date 1 after increment: " << date1 << std::endl;
    date1++;
    std::cout << "Date 1 after post-increment: " << date1 << std::endl;

    std::cout << "Date 2 before decrement: " << date2 << std::endl;
    --date2;
    std::cout << "Date 2 after decrement: " << date2 << std::endl;
    date2--;
    std::cout << "Date 2 after post-decrement: " << date2 << std::endl;

    // Comparison operators
    std::cout << "Date 1 == Date 2: " << (date1 == date2) << std::endl;
    std::cout << "Date 1 != Date 2: " << (date1 != date2) << std::endl;
    std::cout << "Date 1 >= Date 2: " << (date1 >= date2) << std::endl;
    std::cout << "Date 1 <= Date 2: " << (date1 <= date2) << std::endl;
    std::cout << "Date 1 > Date 2: " << (date1 > date2) << std::endl;
    std::cout << "Date 1 < Date 2: " << (date1 < date2) << std::endl;

    // Input and Output
    NgayThangNam date7;
    std::cout << "Enter a date (day month year): ";
    std::cin >> date7;
    std::cout << "You entered: " << date7 << std::endl;

    return 0;
}