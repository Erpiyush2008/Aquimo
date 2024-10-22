#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    
    srand(time(0));

    
    int lb, ub;
    cout << "Enter the range to guess the number: " << endl;
    
    
    do {
        cout << "Lower Bound: ";
        cin >> lb;
        cout << "Upper Bound: ";
        cin >> ub;
        if (ub <= lb) {
            cout << "Upper bound must be greater than Lower bound. Try again." << endl;
        }
    } while (ub <= lb);

    
    int number = rand() % (ub - lb + 1) + lb;

    
    int guess;
    int attempts = 0;

    cout << "Guess the number: ";
    
    do {
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high, try again: ";
        } else if (guess < number) {
            cout << "Too low, try again: ";
        }
    } while (guess != number);


    cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;

    return 0;
}
