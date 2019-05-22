/******************************************************************************
 * Linear Insertion Sort Program.
 *
 * This program sorts a set of numbers in a file and prints out the sorted set
 * of numbers.
 *
 * The program first asks the user to enter a file name. If the user defined
 * file is not found, the program will print an error and the program will ask
 * the user to enter another file name. If the user enters an asterisk, the
 * program will stop running. Once the user inputs a valid file name, the
 * program will then sort the numbers and print the sorted set of numbers in
 * the command window.
 
 * After a successful sort, the program will ask the user to input a new file
 * name to sort.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting March 1, 2017.
 *******************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //defining ifstream as 'inputFile'
    ifstream inputFile;
    
    //defines the size of the array as an integer and defines the array as a double
    const int SIZE = 100;
    double array[SIZE];
    
    //while loop to keep the program running until user enters '*'
    while(1)
    {
        //initializes count as an integer as sets it to zero
        int count = 0;
        
        //asks user to enter the file name and waits until user enters a name
        cout << "Please enter file name: ";
        char fileName[256];
        cin >> fileName;
        
        //opens the file based on what the user inputs
        inputFile.open(fileName);
        
        //if the user enters an asterisk, the program terminates
        if (fileName[0] == '*' && !fileName[1])
            return 0;
        
        //if the inputFile fails to open the program will retrun an error
        else if (inputFile.fail())
        {
            cout << "Could not locate .txt file." << endl;
            cout << "Please try again.\n" << endl;
        }
        
        //if statement for when the program works
        else
        {
            //while loop to find the amount of elements in the file
            while (inputFile >> array[count])
                count++;
            //initializes 'temp' and 'j' as integers
            int temp;
            int j;
            
            //if statement for when there are no elements in the file
            if (count == 0)
            {
                cout << "There are no elements in the file." << endl;
                cout << "Please enter a new file name with elements." << endl;
            }
            
            //essentially what happens here is that the program will place the first
            //number in the file as the first element in the array and it will compare
            //that element to every other element in the file which would sort the
            //elements in order from least to greatest
            
            //algorithm shown below
            else
            {
                for (int i = 1; i < count; i++)
                {
                    temp = array[i];
                    j = i-1;
                    while (j >= 0 && array[j] > temp)
                    {
                        array[j+1] = array[j];
                        j--;
                        array[j+1] = temp;
                    }
                }
                //the modified array prints
                cout << "Sorted file displayed below:" << endl;
                for (int i = 0; i < count; i++)
                    cout << array[i] << endl;
            }
            //inputFile closes
            inputFile.close();
        }
    }
}
