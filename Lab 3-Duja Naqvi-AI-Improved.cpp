#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double balance;
    int numChecks;
    double checkRate;
    double checkFees;
    double totalFees;

    const double MONTHLY_FEE = 10.00;
    const double LOW_BALANCE_FEE = 15.00;

    cout << "Enter the beginning balance: ";
    cin >> balance;

    cout << "Enter the number of checks written: ";
    cin >> numChecks;

    // Input validation
    if (balance < 0) {
        cout << "URGENT: The account is overdrawn." << endl;
    }

    if (numChecks < 0) {
        cout << "Error: Number of checks cannot be negative." << endl;
        return 1;
    }

    // Determine the check rate
    if (numChecks < 20) {
        checkRate = 2.50;
    }
    else if (numChecks <= 39) {
        checkRate = 1.50;
    }
    else if (numChecks <= 59) {
        checkRate = 1.00;
    }
    else {
        checkRate = 0.50;
    }

    // Calculate fees
    checkFees = numChecks * checkRate;
    totalFees = MONTHLY_FEE + checkFees;

    // Apply low balance fee
    if (balance < 400) {
        totalFees += LOW_BALANCE_FEE;
    }

    // Display total
    cout << fixed << setprecision(2);
    cout << "Total monthly service charges: $" << totalFees << endl;

    return 0;
}
