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
#ifndef RECTANGLE_H
#define RECTANGLE_H

//defines the Rectangle class
class Rectangle
{
//private classes of Rectangle
private:
    double width;
    double length;
//public classes of Rectangle
public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
    double getPerimeter() const;
};
#endif
