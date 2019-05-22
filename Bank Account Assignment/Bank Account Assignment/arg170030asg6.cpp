/******************************************************************************************
 * Bank Classes Assignment
 
 * This program is an implementation of a simplified banking system which demonstrates the
 * ability to create and manipulate classes, data members, and member functions. It also
 * aims at creating a C++ projet to handle multiple files (one header file and two .cpp
 * files) at the same time.
 
 * The program first asks the user to input a menu option from a menu displayed. The first
 * option lets the user create a savings account and asks the user to input data specific
 * to that menu option. The second option lets the user create a checkings account and asks
 * the user to input data specific to the checkings account. The third option creates a bank
 * account with no parameters. The fourth option lets the user deposit any amount into any
 * account that was created. The fifth option lets the user withdraw any amount of money as
 * long as the amount withdrawn does not exceed the amount of money in the account. The
 * sixth option lets you display all the accounts. The seventh option lets you exit the
 * program.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting April 3, 2018.
 ******************************************************************************************/
#include <iostream>
#include <string>
#include "Bank.h"

//defines the size of the array and the dynamic array
const int ARRAY_SIZE = 10;
Bank *accounts[ARRAY_SIZE];

//function prototype for the display
void displayAccounts(int, Bank accounts[]);

using namespace std;

int main()
{
    //defined variables for entire program
    int menuOption;
    string accountNumber;
    string name;
    double minimumBalance;
    double monthlyFee;
    double balance;
    double dep;
    double with;
    float interestRate;
    int period;
    bool found;
    int count = 0;
    
    while(true)
    {
        //displayed menu
        cout << "1. Create a Savings Account" << endl;
        cout << "2. Create a Checkings Account" << endl;
        cout << "3. Create a Bank Account without any Parameters" << endl;
        cout << "4. Deposit to a Bank Acount" << endl;
        cout << "5. Withdraw from a Bank Account" << endl;
        cout << "6. Display all Accounts" << endl;
        cout << "7. Exit" << endl;
        
        //waits for user to input a menu option
        cin >> menuOption;
        
        //if user inputs 7 program exits
        if(menuOption == 7)
        {
            return 0;
        }
        //if user inputs 1
        else if(menuOption == 1)
        {
            //checks if there are less than 10 accounts
            if (count < 10)
            {
                //asks for all the savings account data
                cout << "Enter Savings Account Number: ";
                cin >> accountNumber;
                cout << "Enter Holder's Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Balance: ";
                cin >> balance;
                cout << "Enter Interest rate: ";
                cin >> interestRate;
                cout << "Enter the Compounding Period: ";
                cin >> period;
                cout << endl;
                
                //sets the array equal to the savings account
                accounts[count] = new Savings(accountNumber, name, balance, interestRate, period);

                //keeps track of the amount of data in array
                count++;
            }
            //error for if the array reaches more than 10 accounts
            else
                cout << "Max account limit reached. Cannot create the account." << endl;
        }
        //if user inputs 2
        else if(menuOption == 2)
        {
            //checks if there are less than 10 accounts
            if (count < 10)
            {
                //asks for all the checkings account data
                cout << "Enter Checkings Account Number: ";
                cin >> accountNumber;
                cout << "Enter Holder's Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Balance: ";
                cin >> balance;
                cout << "Enter Minimum Balance: ";
                cin >> minimumBalance;
                cout << "Enter Monthly Fee: ";
                cin >> monthlyFee;
                
                //sets the array equal to the checkings account
                accounts[count] = new Checkings(accountNumber, name, balance, minimumBalance, monthlyFee);
                
                //keeps track of the amount of data in array
                count++;
            }
            //error for if the array reaches more than 10 accounts
            else
                cout << "Max account limit reached. Cannot create the account." << endl;
        }
        //if user inputs 3
        else if (menuOption == 3)
        {
            //checks if there are less than 10 accounts
            if (count < 10)
            {
                //creates account with no parameters
                accounts[count] = new Bank();
                count++;
            }
            //error for if the array reaches more than 10 accounts
            else
                cout << "Max account limit reached. Cannot create the account." << endl;
        }
        //if user inputs 4
        else if (menuOption == 4)
        {
            //sets found to false
            found = false;
            
            //asks and waits for the account number
            cout << "Enter the account number for your deposit: " << endl;
            cin >> accountNumber;
            
            //for loop to check all accounts for account number that was inputted by the user
            for (int i = 0; i < count; i++)
            {
                //if user input matches with entered accounts
                if (accounts[i] -> getAccountNumber() == accountNumber)
                {
                    //asks user to enter deposit amount and manipulates the data accordingly
                    cout << "Please enter the amount you want to deposit: " << endl;
                    cin >> dep;
                    accounts[i] -> deposit(dep);
                    
                    //sets found to true
                    found = true;
                }
            }
            //if account could not be found
            if (found == false)
                cout << "Account could not be found. Please try again." << endl;
        }
        //if user inputs 5
        else if (menuOption == 5)
        {
            //sets found to false
            found = false;
            
            //asks and waits for the account number
            cout << "Enter the account number for your withdrawal: " << endl;
            cin >> accountNumber;
            
            //for loop to check all accounts for account number that was inputted by the user
            for (int i = 0; i < count; i++)
            {
                //if user input matches with entered accounts
                if (accounts[i] -> getAccountNumber() == accountNumber)
                {
                    //asks user to enter deposit amount and manipulates the data accordingly
                    cout << "Please enter the amount you want to withdraw: " << endl;
                    cin >> with;
                    accounts[i] -> withdraw(with);
                    
                    //sets found to true
                    found = true;
                }
            }
            //if account could not be found
            if (found == false)
                cout << "Account could not be found. Please try again." << endl;
        }
        //if user inputs 6
        else if (menuOption == 6)
        {
            cout << "-------------------------------------" << endl;
            
            //for loop to input all the accounts in the program
            for (int i = 0; i < count; i++)
            {
                cout << "Account Number: " << accounts[i] -> getAccountNumber() << endl;
                cout << "Account Holder Name: " << accounts[i] -> getName() << endl;
                cout << "Account Balance: " << accounts[i] -> getBalance() << endl;
                cout << "-------------------------------------" << endl;
            }
        }
    }
}
//function displays all the accounts in the program
void displayAccounts(int size, Bank accounts[])
{
    cout << "Account Number: " << accounts[size].getAccountNumber() << endl;
    cout << "Account Holder Name: " << accounts[size].getName() << endl;
    cout << "Account Balance: " << accounts[size].getBalance() << endl;
    cout << "-------------------------------------" << endl;
}
