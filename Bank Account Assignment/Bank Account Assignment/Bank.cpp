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
#include "Bank.h"
#include <string>
#include <stdio.h>

using namespace std;

//default constructor
Bank::Bank()
{
    accountNumber = "9999";
    name = " ";
    balance = 0.0;
}

//defined constructor
Bank::Bank(string accountNum, string name1, double balance1)
{
    accountNumber = accountNum;
    name = name1;
    balance = balance1;
}
//Saving constructor
Savings::Savings(string accountNum, string name1, double balance1, float intRate, int d)
{
    accountNumber = accountNum;
    name = name1;
    balance = balance1;
    interest = intRate;
    days = d;
}
//Checkings constructor
Checkings::Checkings(string accountNum, string name1, double balance1, double minBalance, double fee)
{
    accountNumber = accountNum;
    name = name1;
    balance = balance1;
    minimumBalance = minBalance;
    monthlyFee = fee;
}
//Deposit function
double Bank::deposit(double amt)
{
    balance += amt;
    return balance;
}
//Withdraw function
string Bank::withdraw(double amt)
{
    if(amt > balance)
        cout << "Balance is insufficient" << endl;
    
    else if(amt <= balance)
        balance -= amt;
    
    return to_string(balance);
}
//setName function
void Bank::setName(string name1)
{
    name = name1;
}
//setAccountNumber function
void Bank::setAccountNumber(string acctNumber)
{
    accountNumber = acctNumber;
}
//setBalance function
void Bank::setBalance(double balance1)
{
    balance = balance1;
}
//getName function
string Bank::getName()
{
    return name;
}
//getAccount function
string Bank::getAccountNumber()
{
    return accountNumber;
}
//getBalance function
double Bank::getBalance()
{
    return balance;
}
//setMinimumBalance function
void Checkings::setMinimumBalance(double minBalance)
{
    minimumBalance = minBalance;
}
//setMonthlyFee function
void Checkings::setMonthlyFee(double fee)
{
    monthlyFee = fee;
}
//setInterestRate function
void Savings::setInterestRate(float intRate)
{
    interest = intRate;
}
//setDays function
void Savings::setDays(int d)
{
    days = d;
}
//addInterest function
double Savings::addInterest()
{
    double intRate;
    days = days/365;
    intRate = days * interest;
    balance -= (intRate * balance);
    return intRate;
}
