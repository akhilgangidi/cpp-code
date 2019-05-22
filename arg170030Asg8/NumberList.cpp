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
#include "NumberList.h"

using namespace std;

void NumberList::insertNode(double num)
{
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;
    
    newNode = new ListNode;
    newNode->value = num;
    
    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;
        previousNode = nullptr;
        
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void NumberList::displayList() const
{
    ListNode *nodePtr;
    nodePtr = head;
    
    while(nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
        
    }
}
