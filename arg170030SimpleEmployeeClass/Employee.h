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
#include <string>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

//defines the Employee class
class Employee
{
//private classes of Rectangle
private:
    string ID;
    string firstName;
    string lastName;
    string birthDate;
    char sex;
    string startDate;
    double salary;
    
//public classes of Rectangle
public:
    Employee(); //no arguments as instructed in assignment instructions
    Employee(string id);
    Employee(string id, string first, string last, string dob, char gender, string start, double sal);
    string getID();
    void setID(string id);
    string getFirstName();
    void setFirstName(string first);
    string getLastName();
    void setLastName(string last);
    string getBirthDate();
    void setBirthDate(string dob);
    char getSex();
    void setSex(char gender);
    string getStartDate();
    void setStartDate(string start);
    double getSalary();
    void setSalary(double sal);
};
#endif 
