#include "thoigian.h"
#include <iostream>

using namespace std;

int main() {
    ThoiGian a(23, 59, 59);
    ThoiGian b(1, 0, 0);
    
    std::cout << "Initial times:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Increment and Decrement
    ++a;
    std::cout << "After pre-increment a: " << a << std::endl;
    a++;
    std::cout << "After post-increment a: " << a << std::endl;
    --b;
    std::cout << "After pre-decrement b: " << b << std::endl;
    b--;
    std::cout << "After post-decrement b: " << b << std::endl;

    // Addition and Subtraction
    ThoiGian c = a + b;
    std::cout << "a + b: " << c << std::endl;
    ThoiGian d = a - b;
    std::cout << "a - b: " << d << std::endl;

    // Friend Addition and Subtraction
    ThoiGian e = a + 3600; // Add 1 hour
    std::cout << "a + 3600 seconds: " << e << std::endl;
    ThoiGian f = 3600 + a; // Add 1 hour
    std::cout << "3600 seconds + a: " << f << std::endl;
    ThoiGian g = a - 3600; // Subtract 1 hour
    std::cout << "a - 3600 seconds: " << g << std::endl;
    ThoiGian h = 3600 - a; // Subtract 1 hour
    std::cout << "3600 seconds - a: " << h << std::endl;
    
    // Comparison
    std::cout << "Comparison results:" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;

    // Input and Output
    ThoiGian time;
    std::cout << "Enter time: " << endl;
    std::cin >> time;
    std::cout << "You entered: " << time << std::endl;

    return 0;
}