/************************************************************************************
 * Linked List Sorting Program
 *
 * This program sorts data from a .txt file and outputs it into the console window
 * using linked lists.
 
 * The program first asks the user to input the file name into the console window. If
 * the user inputs '*', the program will terminate. If the user inputs a file name and
 * the program does not find that specific file, the program outputs an error and asks
 * for another file name. Once the program finds the specified file, the program will
 * then use linked lists to sort the data in the .txt file and output the sorted list
 * in the console window. Once it outputs the data, the program asks the user for a
 * different file name to sort.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting April 20, 2018.
 *************************************************************************************/
#include <iostream>
#include <fstream>
#include "NumberList.h"

using namespace std;

int main()
{
    //while loop so the user can keep inputing file names
    while(1)
    {
        //Defines a linked list
        NumberList list;
        
        //variable definitions
        double value;
        ifstream inputFile;
        
        //defines 'fileName' then asks the user to input fileName and opens that file
        char fileName[256];
        cout << "Enter a file name with data to sort: ";
        cin >> fileName;
        inputFile.open(fileName);
        
        //if the user inputs '*' the program terminates
        if(fileName[0] == '*' && !fileName[1])
            return 0;
        
        //if the file fails to open the program outputs the following
        else if(inputFile.fail())
        {
            cout << "Could not find the file." << endl;
            cout << "Please check the file name or try another file name.\n" << endl;
        }
        
        //if the file opens successfully the program runs
        else
        {
            //while loop keeps going until end of file
            while (inputFile >> value)
            {
                //puts values in linked list
                list.insertNode(value);
            }
            //displays the list
            list.displayList();
            inputFile.close();
        }
    }
}
