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
#include "Rectangle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//variable that sets width
void Rectangle::setWidth(double w)
{
    width = w;
}
//variable that sets height
void Rectangle::setLength(double len)
{
    length = len;
}
//variable that returns width
double Rectangle::getWidth() const
{
    return width;
}
//variable that returns length
double Rectangle::getLength() const
{
    return length;
}
//variable that returns area
double Rectangle::getArea() const
{
    return width * length;
}
//variable that returns perimeter 
double Rectangle::getPerimeter() const
{
    return 2*(length + width);
}
