#include "sophuc.h"
#include <iostream>

using namespace std;

int main() {
    // Create complex numbers
    SoPhuc sp1(3, 4);
    SoPhuc sp2(1, 2);

    // Display the complex numbers
    cout << "Complex number 1: " << sp1 << endl;
    cout << "Complex number 2: " << sp2 << endl;

    // Addition
    SoPhuc sum = sp1 + sp2;
    cout << "Sum: " << sum << endl;

    // Subtraction
    SoPhuc diff = sp1 - sp2;
    cout << "Difference: " << diff << endl;

    // Multiplication
    SoPhuc prod = sp1 * sp2;
    cout << "Product: " << prod << endl;

    // Division
    try {
        SoPhuc quot = sp1 / sp2;
        cout << "Quotient: " << quot << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    // Equality
    bool isEqual = (sp1 == sp2);
    cout << "sp1 == sp2: " << (isEqual ? "true" : "false") << endl;

    // Inequality
    bool isNotEqual = (sp1 != sp2);
    cout << "sp1 != sp2: " << (isNotEqual ? "true" : "false") << endl;

    // Operations with int
    SoPhuc sp3 = sp1 + 5;
    cout << "sp1 + 5: " << sp3 << endl;

    SoPhuc sp4 = 5 + sp1;
    cout << "5 + sp1: " << sp4 << endl;

    SoPhuc sp5 = sp1 - 5;
    cout << "sp1 - 5: " << sp5 << endl;

    SoPhuc sp6 = 5 - sp1;
    cout << "5 - sp1: " << sp6 << endl;

    SoPhuc sp7 = sp1 * 5;
    cout << "sp1 * 5: " << sp7 << endl;

    SoPhuc sp8 = 5 * sp1;
    cout << "5 * sp1: " << sp8 << endl;

    try {
        SoPhuc sp9 = sp1 / 5;
        cout << "sp1 / 5: " << sp9 << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        SoPhuc sp10 = 5 / sp1;
        cout << "5 / sp1: " << sp10 << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    // Input complex numbers
    SoPhuc spInput;
    cout << "Enter a complex number:" << endl;
    cin >> spInput;
    cout << "You entered: " << spInput << endl;

    return 0;
}
