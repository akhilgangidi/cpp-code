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
#ifndef Bank_h
#define Bank_h
#include <iostream>
#include <string>

using namespace std;

//defines the Bank class
class Bank
{
//protected variables
protected:
    string accountNumber;
    string name;
    double balance;
    string accountType;

//public fucntions
public:
    Bank();
    Bank(string, string, double);
    string withdraw(double);
    double deposit(double);
    void setName(string);
    void setAccountNumber(string);
    void setBalance(double);
    string getAccountNumber();
    string getName();
    double getBalance();
};

//defines checkings class
class Checkings:public Bank
{
//private variables
private:
    double minimumBalance;
    double monthlyFee;
   
//public functions
public:
    Checkings();
    Checkings(string, string, double, double, double);
    void setMinimumBalance(double);
    void setMonthlyFee(double);
};

//defines savings class
class Savings:public Bank
{
//private variables
private:
    int days;
    double interest;
    
//public functions
public:
    Savings();
    Savings(string, string, double, float, int);
    void setInterestRate(float);
    void setDays(int);
    double addInterest();
};


#endif

cout
