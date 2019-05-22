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
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

//defines NumberList class
class NumberList
{
//private variables definitions
private:
    //defines the structure 'ListNode'
    struct ListNode
    {
        double value;
        struct ListNode *next;
    };
    
    ListNode *head; //defines ListNode
    
//private varaible definitions
public:
    NumberList()
        { head = nullptr; }
    
    //defintions
    void insertNode(double);
    void displayList() const;
};

#endif
