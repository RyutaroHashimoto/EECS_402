//library
#include <iostream>
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: September 21, 2021
//purpose: This program will get balance and accrues interest and print 
//interest and balance over the specified number of months. Result will be 
//printed to the console.

//global constant
const double MINIMUM_INTEREST_RATE = 0.0015;
const double MAXIMUM_INTEREST_RATE = 0.004;
const double STANDARD_INTEREST_RATE = 0.00225;
const double LOWER_BALANCE_BORDER = 1000.00;
const double UPPER_BALANCE_BORDER = 15000.00;

//global function
//Function: Call accrueOneMonthsInterest for numMonths times.
bool accrueInterest(
    double &balanceAmt,
    const int numMonths,
    const bool doPrintEachMonth);

//Function: Calculate interest and final balance for a single month.
bool accrueOneMonthsInterest(
    double &balanceAmt,
    const bool doPrintInfo);

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
    int numMonths;
    double balanceAmt;
    bool doPrintEachMonth = false;
    string settingInput;

    // Get initial balance from prompt
    cout << "Enter the initial balance of the account: "; 
    cin >> balanceAmt;

    // Get num month to compute from prompt
    cout << "Enter the number of months to accrue interest: "; 
    cin >> numMonths;

    // Get setting option whether show month-by-month results from prompt
    cout << "EShow month-by-month results - 'y' for yes, any other for no: ";
    cin >> settingInput;
    if (settingInput == "y")
    {
        doPrintEachMonth = true;
    }

    // accrue interest
    if (!(accrueInterest(balanceAmt, numMonths, doPrintEachMonth)))
    {
        // Exit whith error
        cout << "Sorry, an error was detected. Unable to provide results!" 
             << endl;
        return 1;
    } else {
        // Exit whithout 
        return 0;
    }
}
#endif

bool accrueInterest(
    double &balanceAmt, 
    const int numMonths, 
    const bool doPrintEachMonth)
{
    double initialBalance = 0;
    int i;

    // Check whether input values are logical
    if (numMonths <= 0)
    {
        // Return false with error
        cout << "ERROR in accrueInterest: numMonths must be > 0, "
             << "but the value " << numMonths << " was provided!" << endl;
        return false;
    }

    initialBalance = balanceAmt;

    // Execute the calculation
    for (i = 0; i < numMonths; i++)
    {
        if (!(accrueOneMonthsInterest(balanceAmt, doPrintEachMonth)))
        {
            // Return false with error
            return false;
        }
    }

    // Print result
    cout << "Interest accrued for " << numMonths << " months!" << endl 
         << endl;
    cout << "Initial balance: " << initialBalance << endl;
    cout << "Total interest accrued: " << balanceAmt - initialBalance << endl;
    cout << "Final balance: " << balanceAmt << endl;

    return true;
}

bool accrueOneMonthsInterest(
    double &balanceAmt,
    const bool doPrintInfo)
{
    double interest;
    double interestRate;
    double initialBalance;

    // Check whether input values are logical
    if (balanceAmt < 0)
    {
        // Return false with error
        cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0, "
             << "but the value " << balanceAmt << " was provided!" << endl;
        return false;
    }

    // Get interest rate according to current balance
    if (balanceAmt >= UPPER_BALANCE_BORDER)
    {
        interestRate = MAXIMUM_INTEREST_RATE;
    }
    else if (balanceAmt >= LOWER_BALANCE_BORDER)
    {
        interestRate = STANDARD_INTEREST_RATE;
    }
    else 
    {
        interestRate = MINIMUM_INTEREST_RATE;
    }

    // Calculate interest and new balance
    initialBalance = balanceAmt;
    interest = balanceAmt * interestRate;
    balanceAmt += interest;

    // print info if requested
    if (doPrintInfo)
    {
        cout << "Accruing interest for 1 month:" << endl;
        cout << "  Initial balance: " << initialBalance << endl;
        cout << "  Initial rate: " << interestRate << endl;
        cout << "  Interest accrued: " << interest << endl;
        cout << "  New balance: " << balanceAmt << endl;
    }

    // exit without error
    return true;
    }