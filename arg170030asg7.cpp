/************************************************************************************
 * Simple Employee Class
 *
 * This program checks whether the phrase the user inputs is a valid palindrome.
 
 * The program first asks the user to input a phrase to test. Once the user inputs a
 * phrase, the program will proceed to check whether the phrase is a palindrome or
 * not. The program will ignore punctuations and commas and check whether the phrase
 * is the same whether it is written forwards or backwards. Once the program
 * determines that it is a palindrome, it will print out 'This phrase is a palindrome'
 * and then ask the user to input another phrase. If the phrase is not a palindrome,
 * it will print out 'This phrase is not a palindrome' and will then ask the user to
 * input another phrase to check. If the user doesn't input a phrase, the program
 * terminates.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting April 10, 2018.
 *************************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//function prototype with one parameter
bool isPalindrome(string);

int main()
{
    //while loop so the user can keep inputting different phrases to check
    while(1)
    {
        //variable declaration
        string input;
        
        //asks the user to enter a phrase and waits until the user inputs a phrase
        cout << "Please enter a phrase to test whether it is a palindrome: ";
        getline(cin, input);
        
        //if the user does not input a phrase the program will terminate
        if (input.length() == 0)
            return 0;
        
        //if the phrase is a palindrome, program will output that it is a palindrome
        else if (isPalindrome(input) == true)
            cout << "This phrase is a palindrome." << endl;
        
        //else the phrase is not a palindrome
        else
            cout << "This phrase is not a palindrome." << endl;
    }
}
//function checks whether it is a palindrome or not
bool isPalindrome(string str)
{
    //variable declarations
    int length = str.length(); //keeps track of the length of the string
    int start = 0;
    int end = 1;
    
    //if the length of the string is less than or equal to 1, the function will return true
    if (length <= 1)
        return true;
    
    //if there is a whitespace or punctutation in the last character of the array, it will disregard it and compare the rest of the string with one another
    else if (isspace(str[length - 1]) || ispunct(str[length - 1]))
    {
        str = str.substr(start, length - 2);
        return isPalindrome(str); 
    }
    //if there is a whitespace or punctutation in the first character of the string, it will disregard it and compare the rest of the string with one another
    else if (isspace(str[0]) || ispunct(str[0]))
    {
        str = str.substr(end, length - 1);
        return isPalindrome(str);
    }
    //if the characters are the same for the first and last characters of the string, it will compare the rest of the string with one another
    else if (toupper(str[0]) == toupper(str[length - 1]))
    {
        str = str.substr(end, length - 2);
        return isPalindrome(str);
    }
    //if the string didn't pass the palindrome check, the function will return false
    else
        return false;
}


