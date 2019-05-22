/*******************************************************************************
 * String Homework Assignment
 *
 * The program first asks the user to pick a menu option. The user can pick
 * from four menu options. The first one sums the digits in the string, the
 * second option counts the number on consonants in the string. The thrid option
 * counts the number of vowels in the string. The fourth option counts the
 * number of whitespaces in the string. The user can also input '0' to end the
 * program.
 
 * After the user chooses a menu option, the program then asks you to input a
 * string for the menu option. The program then loops back to the beginning where
 * the user can choose a new menu option and a new string.
 
 * Written by Akhil Gangidi (arg170030) at The University of Texas at Dallas
 * starting February 23, 2018.
 *******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function prototypes
int sumOfDigits (string);
int vowelCount (string);
int consonantCount (string);
int whitespaceCount (string);

//main function
int main()
{
    int menuChoice; //menuChoice definiton
    
    
    while (1)
    {
        //displays the menu
        cout << "Please enter menu choice:" << endl;
        cout << "1. Sum digits in string" << endl;
        cout << "2. Count number of consonants" << endl;
        cout << "3. Count the number of vowels" << endl;
        cout << "4. Count the whitespace characters\n" << endl;
        cout << "Or enter 0 to end program." << endl;
    
        //waits for user to input a menu option
        cin >> menuChoice;
        
        if (menuChoice == 0) //when user inputs '0'
        {
            return 0; //terminates program
        }
        else if (menuChoice == 1) //when user inputs '1'
        {
            //asks for user to end a string and waits for user to input string
            string input;
            cout << "Please enter a string: ";
            cin.get();
            getline(cin, input);
            cout << endl;
            //displays the sum of the digits in the string by calling the sumOfDigits function
            cout << "The sum of all the digits in the string is " << sumOfDigits(input) << "." << endl;
        }
        else if (menuChoice == 2) //when user inputs '2'
        {
            //asks for user to end a string and waits for user to input string
            string input;
            cout << "Please enter a string: ";
            cin.get();
            getline(cin, input);
            cout << endl;
            //displays the consonant count by calling the consonantCount function
            cout << "There are " << consonantCount(input) << " consonant(s)." << endl;
        }
        else if (menuChoice == 3) //when user inputs '3'
        {
            //asks for user to end a string and waits for user to input string
            string input;
            cout << "Please enter a string: ";
            cin.get();
            getline(cin, input);
            cout << endl;
            //displays the vowel count by calling vowelCount function
            cout << "There are " << vowelCount(input) << " vowel(s)." << endl;
        }
        else if (menuChoice == 4) //when user inputs '4'
        {
            //asks for user to end a string and waits for user to input string
            string input;
            cout << "Please enter a string: ";
            cin.get();
            getline(cin, input);
            cout << endl;
            //displays the whitespace count by calling the whitespaceCount function
            cout << "There are " << whitespaceCount(input) << " whitespace(s)." << endl;
        }
        else //when user inputs any other value
        {
            //displays below and asks user to input another menu option
            cout << "Invalid menu option. Please enter valid menu option." << endl;
        }
    }
}
//function adds all of the digits present in the string
int sumOfDigits (string stringPtr)
{
    //defines sum and sets it to 0
    int sum = 0;
    
    //for loop checks every item in string and check is string has any digits and if so adds the digits to sum
    for (int i = 0; i < stringPtr.size(); i++)
    {
        if (stringPtr[i] == '0')
            sum += 0;
        
        else if (stringPtr[i] == '1')
            sum += 1;
        
        else if (stringPtr[i] == '2')
            sum += 2;
        
        else if (stringPtr[i] == '3')
            sum += 3;
        
        else if (stringPtr[i] == '4')
            sum += 4;
        
        else if (stringPtr[i] == '5')
            sum += 5;
        
        else if (stringPtr[i] == '6')
            sum += 6;
        
        else if (stringPtr[i] == '7')
            sum += 7;
        
        else if (stringPtr[i] == '8')
            sum += 8;
        
        else if (stringPtr[i] == '9')
            sum += 9;
    }
    //return the sum
    return sum;
}
//function that counts the amount of consonants in the string
int consonantCount (string stringPtr)
{
    //defines consonant and set it equal to 0
    int consonant = 0;

    //for loop goes through every item in string and checks if it's a consonant
    for (int i = 0; i < stringPtr.size(); i++)
    {
        if (stringPtr[i] == 'b' || stringPtr[i] == 'B')
            consonant++;
        
        else if (stringPtr[i] == 'c' || stringPtr[i] == 'C')
            consonant++;
        
        else if (stringPtr[i] == 'd' || stringPtr[i] == 'D')
            consonant++;
        
        else if (stringPtr[i] == 'f' || stringPtr[i] == 'F')
            consonant++;
        
        else if (stringPtr[i] == 'g' || stringPtr[i] == 'G')
            consonant++;
        
        else if (stringPtr[i] == 'h' || stringPtr[i] == 'H')
            consonant++;
        
        else if (stringPtr[i] == 'j' || stringPtr[i] == 'J')
            consonant++;
        
        else if (stringPtr[i] == 'k' || stringPtr[i] == 'K')
            consonant++;
        
        else if (stringPtr[i] == 'l' || stringPtr[i] == 'L')
            consonant++;
        
        else if (stringPtr[i] == 'm' || stringPtr[i] == 'M')
            consonant++;
        
        else if (stringPtr[i] == 'n' || stringPtr[i] == 'N')
            consonant++;
        
        else if (stringPtr[i] == 'p' || stringPtr[i] == 'P')
            consonant++;
        
        else if (stringPtr[i] == 'q' || stringPtr[i] == 'Q')
            consonant++;
        
        else if (stringPtr[i] == 'r' || stringPtr[i] == 'R')
            consonant++;
        
        else if (stringPtr[i] == 's' || stringPtr[i] == 'S')
            consonant++;
        
        else if (stringPtr[i] == 't' || stringPtr[i] == 'T')
            consonant++;
        
        else if (stringPtr[i] == 'v' || stringPtr[i] == 'V')
            consonant++;
        
        else if (stringPtr[i] == 'w' || stringPtr[i] == 'W')
            consonant++;
        
        else if (stringPtr[i] == 'x' || stringPtr[i] == 'X')
            consonant++;
        
        else if (stringPtr[i] == 'z' || stringPtr[i] == 'Z')
            consonant++;
    }
    //returns the amount of consonants in the string
    return consonant;
}
//function that counts the amount of vowels in the string
int vowelCount (string stringPtr)
{
    //defines vowel and sets it equal to 0
    int vowel = 0;
    
    //for loop the goes through every item in string and checks if it is a vowel
    for (int i = 0; i < stringPtr.size(); i++)
    {
        if (stringPtr[i] == 'a' || stringPtr[i] == 'A')
            vowel++;
        
        else if (stringPtr[i] == 'e' || stringPtr[i] == 'E')
            vowel++;
        
        else if (stringPtr[i] == 'i' || stringPtr[i] == 'I')
            vowel++;
        
        else if (stringPtr[i] == 'o' || stringPtr[i] == 'O')
            vowel++;
        
        else if (stringPtr[i] == 'u' || stringPtr[i] == 'U')
            vowel++;
        
        else if (stringPtr[i] == 'y' || stringPtr[i] == 'Y')
            vowel++;
    }
    //returns the amount of vowels in the function
    return vowel;
}
//function that counts the amount of whitespaces in the string
int whitespaceCount (string stringPtr)
{
    //defines whitespaces and sets it equal to 0
    int whitespace = 0;
    
    //for loop that goes through every item in string and checks if there is a whitespace
    for (int i = 0; i < stringPtr.size(); i++)
    {
        if (stringPtr[i] == ' ')
            whitespace++;
    }
    //returns the amount of whitespaces
    return whitespace;
}

