/************************************************************************************
 * Simple Employee Class
 *
 * This program first tries to read in data from a file. If file is not found,
 * the file will be created using option 'E'. The program's goal is to keep track
 * of employee information. Things that we are keeping track of is the employee's ID,
 * first name, last name, DOB, gender, start date, and salary.
 
 * The program first asks the user to pick from a menu of options. The first
 * option allows the user to input information for a new employee and stores
 * it in an dynamic array. The second option displays all the employees stored in the
 * array which was either user created or read in from the file. The third option
 * allows the user to search for the employee using their respective ID number. The
 * fourth option allows the user to delete an employee by using their ID number as well.
 * The fifth option allows you to copy all remaining data in the array to the file then
 * ends the program.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting March 1, 2017.
 *************************************************************************************/
#include "Employee.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

//defines Employee()
Employee::Employee()
{
    //no arguments as instructed in assignment instructions
}
//defines Employee(string id)
Employee::Employee(string id)
{
    ID = id;
}
//defines (string id, string first, string last, string dob, char gender, string start, double sal)
Employee::Employee(string id, string first, string last, string dob, char gender, string start, double sal)
{
    ID = id;
    firstName = first;
    lastName = last;
    birthDate = dob;
    sex = gender;
    startDate = start;
    salary = sal;
}
//defines getID()
string Employee::getID()
{
    return ID;
}
//defines setID(string id)
void Employee::setID(string id)
{
    ID = id;
}
//defines getFirstName()
string Employee::getFirstName()
{
    return firstName;
}
//defines setFirstName(string first)
void Employee::setFirstName(string first)
{
    firstName = first;
}
//defines getLastName()
string Employee::getLastName()
{
    return lastName;
}
//defines setLastName(string last)
void Employee::setLastName(string last)
{
    lastName = last;
}
//defines getBirthDate()
string Employee::getBirthDate()
{
    return birthDate;
}
//defines setBirthDate(string dob)
void Employee::setBirthDate(string dob)
{
    birthDate = dob;
}
//defines getSex()
char Employee::getSex()
{
    return sex;
}
//defines setSex(char gender)
void Employee::setSex(char gender)
{
    sex = gender;
}
//defines getStartDate()
string Employee::getStartDate()
{
    return startDate;
}
//defines setStartDate(string start)
void Employee::setStartDate(string start)
{
    startDate = start;
}
//defines getSalary()
double Employee::getSalary()
{
    return salary;
}
//defines setSalary(double sal)
void Employee::setSalary(double sal)
{
    salary = sal;
}
