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
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include "Employee.h" //user created header file

using namespace std;

//initializing the dynamically allocated array
const int ARRAY_SIZE = 100;
Employee *employeeArray[ARRAY_SIZE];
Employee *ptrArray = nullptr;

int main()
{
    //initializing the count variable and sets it to 0
    int count = 0;
    
    //defines inputFile and tries to open 'Employee.txt'
    ifstream inputFile;
    inputFile.open("Employee.txt");
    
    //if statement for if it fails to open
    if(inputFile.fail())
    {
        cout << "Employee.txt was not found." << endl;
        cout << "Program will create it when option 'E' is used." << endl;
    }
    //if it succeeds in opening the data will be read into the array
    else
    {
        string ID;
        string firstName;
        string lastName;
        string birthDate;
        char gender;
        string startDate;
        double salary;
        
        cout << "Employee.txt was found!" << endl;
        cout << "Putting data in the program...";
        while(inputFile >> ID >> firstName >> lastName >> birthDate >> gender >> startDate >> salary)
        {
            employeeArray[count] = new Employee(ID, firstName, lastName, birthDate, gender, startDate, salary);
            count++;
        }
        cout << "complete!" << endl;
    }
    //defines the menuOption variable
    char menuOption;
    
    //while loop to keep the menu until option 'E' is chosen
    while(1)
    {
        if (count == 100)
        {
            cout << "Program can only store up to 100 employees. Please choose option E to transfer data and end program." << endl;
        }
        cout << "A) Add new employee" << endl;
        cout << "B) Display all employees" << endl;
        cout << "C) Search for an employee" << endl;
        cout << "D) Remove an employee" << endl;
        cout << "E) Save all data to a text file and exit program" << endl;
    
        //waits for user to enter an option
        cin >> menuOption;
        
        //if statement for when first option is chosen, the program asks user to input data for new employee
        if(menuOption == 'A' || menuOption == 'a')
        {
            //variable definitions
            string ID;
            string firstName;
            string lastName;
            string birthDate;
            char gender;
            string startDate;
            double salary;

            //declares new employee
            ptrArray = new Employee;
    
            cout << "Enter Employee ID: ";
            cin.ignore();
            getline(cin, ID);
            //checks to see if ID is already taken by another employee
            for (int i = 0; i < count; i++)
            {
                while(employeeArray[i] -> getID() == ID)
                {
                    cout << "ID is already in use by another employee." << endl;
                    cout << "Please enter a unique Employee ID: ";
                    getline(cin, ID);
                    i=0;
                }
            }
            ptrArray -> setID(ID);
            
            cout << "Enter Employee's First Name: ";
            cin >> firstName;
            ptrArray -> setFirstName(firstName);
            
            cout << "Enter Employee's Last Name: ";
            cin >> lastName;
            ptrArray -> setLastName(lastName);
            
            cout << "Enter Employee's Date of Birth (MM/DD/YYYY): ";
            cin >> birthDate;
            ptrArray -> setBirthDate(birthDate);
            
            cout << "Enter Employee's Gender (M/F): ";
            cin >> gender;
            //checks to see if gender is valid
            while (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f')
            {
                cout << "\nNot a valid gender. Please try again." << endl;
                cout << "Enter Employee's Gender (M/F): ";
                cin >> gender;
            }
            ptrArray -> setSex(gender);
            
            cout << "Enter Employee's Start Date (MM/DD/YYYY): ";
            cin >> startDate;
            ptrArray -> setStartDate(startDate);
            
            cout << "Enter Employee's Salary: ";
            cin >> salary;
            ptrArray -> setSalary(salary);
            
            //transfers all data to employeeArray
            employeeArray[count] = ptrArray;
            count++;
        }
        //if statement for if seconds option is chosen, displays all employees
        else if(menuOption == 'B' || menuOption == 'b')
        {
            string ID;

            Employee *tempEmployee;
            
            //sorts employees alphabetically
            for(int i = 0; i < count; i++)
            {
                for (int j = 0; j < count - i - 1; j++)
                {
                    if(employeeArray[j] -> getLastName() > employeeArray[j+1] -> getLastName())
                    {
                        tempEmployee = employeeArray[j];
                        employeeArray[j] = employeeArray[j+1];
                        employeeArray[j+1] = tempEmployee;
                    }
                }
                //standard output for employee data
                cout << "-------------------------" << endl;
                cout << "Last Name: " << employeeArray[i] -> getLastName() << endl;;
                cout << "First Name: " << employeeArray[i] -> getFirstName() << endl;
                cout << "Employee ID: " << employeeArray[i] -> getID() << endl;
                cout << "DOB: " << employeeArray[i] -> getBirthDate() << endl;
                cout << "Gender: " << employeeArray[i] -> getSex() << endl;
                cout << "Start Date: " << employeeArray[i] -> getStartDate() << endl;
                cout << fixed << setprecision(0) << "Salary: $" << employeeArray[i] -> getSalary() << endl;
                cout << "-------------------------" << endl;
            }
            
        }
        //if statement for when third option is chosen, searches for employee through ID
        else if(menuOption == 'C' || menuOption == 'c')
        {
            //initializes variables
            int idCheck = 0;
            string ID;

            //waits for user to enter ID
            cout << "Enter an Employee ID: ";
            cin.ignore();
            getline(cin, ID);
            //searches for if ID is associated with any employee
            for (int i = 0; i < count; i++)
            {
                if(employeeArray[i] -> getID() == ID)
                {
                    cout << "-------------------------" << endl;
                    cout << "Last Name: " << employeeArray[i] -> getLastName() << endl;;
                    cout << "First Name: " << employeeArray[i] -> getFirstName() << endl;
                    cout << "Employee ID: " << employeeArray[i] -> getID() << endl;
                    cout << "DOB: " << employeeArray[i] -> getBirthDate() << endl;
                    cout << "Gender: " << employeeArray[i] -> getSex() << endl;
                    cout << "Start Date: " << employeeArray[i] -> getStartDate() << endl;
                    cout << fixed << setprecision(0) << "Salary: $" << employeeArray[i] -> getSalary() << endl;
                    cout << "-------------------------" << endl;
                    
                    //sets idCheck to 1
                    idCheck = 1;
                }
            }
            //if id is not found, error is printed
            if(idCheck == 0)
                cout << "ID is not associated with any employees. Please try again." << endl;
            
        }
        //if statment for fourth option, deletes employee based on ID
        else if(menuOption == 'D' || menuOption == 'd')
        {
            //intializes variables
            int idCheck = 0;
            string ID;
            
            //waits for user to enter ID
            cout << "Enter an Employee ID: ";
            cin.ignore();
            getline(cin, ID);
            //checks to see if ID is associated with any employees and deletes employee
            for (int i = 0; i < count; i++)
            {
                if(employeeArray[i] -> getID() == ID)
                {
                    for (int j = i; j < count - 1; j++)
                    {
                        employeeArray[j] = employeeArray[j+1];
                    }
                    employeeArray[i] = NULL;
                    cout << "Employee was successfully removed." << endl;
                    count--;
                    //sets idCheck to 1
                    idCheck = 1;
                    break;
                }
            }
            //if id is not associated with any employees
            if (idCheck == 0)
                cout << "ID is not associated with any employees. Please try again." << endl;

        }
        //if statement for option 5, transfers all data to file and terminates program
        else if(menuOption == 'E' || menuOption == 'e')
        {
            cout << "Copying data to Employee.txt..." << endl;
            
            //defines outputFile and initializes it and creates/opens "Employee.txt"
            ofstream outputFile;
            outputFile.open("Employee.txt");
            
            //puts all data in file
            for (int i = 0; i < count; i++)
            {
                outputFile << employeeArray[i] -> getID()<< "\t" << employeeArray[i]->getFirstName()<< "\t" << employeeArray[i]->getLastName() << "\t" << employeeArray[i]->getBirthDate()<< "\t" << employeeArray[i]->getSex()<< "\t" << employeeArray[i]->getStartDate()<< "\t" << fixed << setprecision(0) << employeeArray[i]->getSalary() <<endl;
            }
            //closes outputFile
            outputFile.close();
            cout << "Copy Complete!" << endl;
            return 0;
        }
        //if user inputs an invalid option
        else
        {
            cout << "Invalid menu option. Please try again." << endl;
            cin.clear();
        }
    }
}
