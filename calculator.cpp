#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    int choice;


    cout << "Enter two numbers: " << endl;
    cout << "First Number: ";
    cin >> num1;
    cout << "Second Number: ";
    cin >> num2;

    cout << "Choose an operation to perform: " << endl;
    cout << "1. Addition" << "\n"
         << "2. Subtraction" << "\n"
         << "3. Multiplication" << "\n"
         << "4. Division" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Result of Addition: " << num1 + num2 << endl;
    } else if (choice == 2) {
        cout << "Result of Subtraction: " << num1 - num2 << endl;
    } else if (choice == 3) {
        cout << "Result of Multiplication: " << num1 * num2 << endl;
    } else if (choice == 4) {
        if (num2 != 0) {
            cout << "Result of Division: " << num1 / num2 << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Invalid choice. Please run the program again." << endl;
    }

    return 0;
}
