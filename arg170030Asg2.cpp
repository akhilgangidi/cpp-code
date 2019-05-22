/********************************************************************************
 * Magic Squares.
 *
 * The program should ask the user for an odd number greater than or equal to 3
 * and print the magic square for that order.  It should reject invalid input 
 * with an appropriate message.  That is, the program should request a number,
 * print the magic square, then request another number, and print that magic
 * square.  The program ends when the user enters zero for the order.  You don’t
 * need to print the boxes around the numbers, but arrange the numbers in columns
 * so the square is readable, using print formatting.  After printing each
 * square, print the magic sum.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting February 6, 2018.
 ********************************************************************************/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>

using namespace std;

//Function will calculate the sum of the rows, cols, and diags
void calculateSum(int size)
{
    int sum = size * ((size * size) + 1)/2;
    cout << "The sum of each row is " << sum << endl;
}

//Computes the magic square for inputted grid size
void calculateSquare(int size)
{
    //initialize variables
    int magicSquare[size][size];
    int num1;
    int num2;
    
    //for loop to make array 0 throughout
    for(num1 = 0; num1 < size; num1++)
    {
        for(num2 = 0; num2 < size; num2++)
            magicSquare[num1][num2] = 0;
    }
    
    //Algorithm for determining where to put '1'
    int j = size / 2;
    int i = size - 1;
    int previousj = 0;
    int previousi = 0;
    
    //Algorithm for calculating where other numbers will go
    for (int num = 1; num <= size*size;)
    {
        if (i == size)
            i = 0;
        if (j < 0)
            j = size - 1;
        if (magicSquare[j][i])
        {
            j = previousj;
            i = previousi - 1;
            continue;
        }
        else
        {
            magicSquare[j][i] = num++; //set number
        }
        
        //makes the previous value the new value
        previousj = j;
        previousi = i;
    
        //will go up down a row and left for the column
        i++;
        j--;
    }
    
    //this will output the magic square
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            cout << setw(5) << magicSquare[j][i];
        cout << endl;
    }
}

//main function for program
int main()
{
    //initialize variable
    int num;
    
    //while loop that will repeat the program
    while(1)
    {
        //asks user to input value and waits for user
        cout << "Please choose a odd number greater than 2." << endl;
        cin >> num;
        //if num = 0 the program will stop
        if (num == 0)
            return 0;
        //determining if value is negative and not valid
        else if (num < 3 && num != 0)
        {
            cout << "Value invalid. ";
        }
        
        else
        {
            //Makes even numbers invalid
            if (num % 2 == 0)
            {
                cout << "Value invalid. ";
            }
            //carries program out if value is valid
            if (num % 2 != 0)
            {
                cout << "Computing " << num << "x" << num << " magic square..." << endl;

                calculateSum(num);
                calculateSquare(num);
            }
        }
    }
}
