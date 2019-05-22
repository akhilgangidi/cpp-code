/********************************************************************************
 * Simple Rectangle Class
 *
 * This program asks user to input information about a rectangle then
 * dynamically allocates the data in an array.
 
 * The program first asks the user to pick from a menu of options. The first
 * option allows the user to input information for a new rectangle and stores
 * it in an array. The second option displays the rectangles stored in the
 * array and displays the number of rectangles allocated. The third option prints
 * the last array element and then deletes it from the array then displays the
 * amount of rectangles remaining. Entering '0' will terminate the program.

 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting March 1, 2017.
 *********************************************************************************/
#include <iostream>
#include "Rectangle.h" //user created header file
#include <cstdlib>

using namespace std;

//declares the dynamically allocated array and sets the limit to 10
const int ARRAY_SIZE = 10;
Rectangle *rectangleArray[ARRAY_SIZE];
Rectangle *ptrArray = nullptr;

int main()
{
    //defined variables
    int menuOption;
    int i;
    int j = 0;
    double length;
    double width;
    
    while(1) //while loop that loops menu and lets program keep running until menuOption == 0
    {
        //menu displayed
        cout << "Please select an option: " << endl;
        cout << "1) Input new rectangle" << endl;
        cout << "2) Show all rectangles" << endl;
        cout << "3) Show dimensions and delete last rectangle" << endl;
        
        //waits for user to input menuOption
        cin >> menuOption;
        
        //if the user inputs 0, the program will terminate
        if (menuOption == 0)
            return 0;
        
        //if the user inputs 1
        else if (menuOption == 1)
        {
            //if j = 10, the program will not let the user input any more values
            if (j == 10)
            {
                //displayed error
                cout << "There are already 10 rectangles." << endl;
                cout << "Try to delete one using option 3." << endl;
            }
            else
            {
                //dynamically allocates a new triangle
                ptrArray = new Rectangle;
                cout << "Please enter length: ";
                cin >> length;
                cout << "Please enter width: ";
                cin >> width;
                
                //array points to the memory addresses of the length and width variables
                ptrArray->setLength(length);
                ptrArray->setWidth(width);
                
                //sets the data to rectangleArray and increments j
                rectangleArray[j] = ptrArray;
                j++;
            }
            
        }
        //if the user inputs 2
        else if (menuOption == 2)
        {
            //for loop that prints all the rectangles
            for (i = 0; i < j; i++)
            {
                cout << "Rectangle " << i+1 << " length: " << rectangleArray[i] -> getLength() << " width: " << rectangleArray[i] -> getWidth() << " area: " << rectangleArray[i] -> getArea() << " perimeter: " << rectangleArray[i] -> getPerimeter() << endl;
            }
            //displays the amount of rectangles allocated
            cout << j << " rectangle(s) are allocated." << endl;
        }
        //if the user inputs 3
        else if (menuOption == 3)
        {
            if (j == 0)
            {
                cout << "There are no rectangles." << endl;
                cout << "Please add some using option 1." << endl;
            }
            else
            {
                //displays the last rectangle in array
                cout << "Rectangle " << j << " length: " << rectangleArray[j-1] -> getLength() << " width: " << rectangleArray[j-1] -> getWidth() << " area: " << rectangleArray[j-1] -> getArea() << " perimeter: " << rectangleArray[j-1] -> getPerimeter() << endl;
                
                //deletes last element and decrements j
                rectangleArray[j-1] = nullptr;
                j--;
                
                //displays the amount of rectangles remaining
                cout << j << " rectangle(s) remaining" << endl;
            }
            
        }
        else //displays error if menu option isn't valid
            cout << "Menu option is not valid, please try again" << endl;
    }
}
