/******************************************************************************
 * Simple Series Program.
 *
 * The program requests a number greater than 1.  If zero is entered, the
 * program stops. If a number equal to 1 or less than 0 is entered, the program
 * should give an error and return to request another number. The same is true
 * for entering anything other than a number.
 
 * If the number entered is N, sum the series 1/N + 2/N-1 + 3/N-2+ … N/1.
 * Display the original number and the sum.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting January 18, 2018.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
    //variable definitions
    double i = 0;
    int number;
    double answer = 0;
    
    //Asks the user to enter a number greater than 0 and waits for user to input a value
    cout << "Please enter a number greater than 1" << endl;
    cin >> number;
    
    //while loop to restart the program when a new value is entered
    while (1)
    {
        //if statement for if the value is not a number
        if (!number)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The input isn't valid. Please try again." << endl;
            cin >> number;
        }
        //else if statement for when number is equal to 0
        if (number == 0)
            return 0;
        
        //else if statement for if the value is equal to 1 or less than 0
        else if (number == 1 || number < 0)
        {
            cout << "This number isn't valid. Please try another numeber." << endl;
            cin.clear();
            cin >> number;
        }
        //else if statement for when number is greater than 1
        else if (number > 1)
        {
            //outputs the number user input
            cout << "Original Number: " << number << endl;
            //while statement calculates series sum
            while (number > 0)
            {
                i++;
                answer += i/number--;
            }
            //outputs the sum
            cout << "Series sum: " << answer << endl;
            cin.clear();
            cin >> number;
        }
    }
}
