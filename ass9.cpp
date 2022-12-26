/*

A palindrome is a string of character that‘s the same forward and backward.
Typically, punctuation, capitalization, and spaces are ignored.
For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining
the characters “poor danisina droop” and observing that they are the same forward and backward.
One way to check for a palindrome is to reverse the characters in the string and then compare
with them the original-in a palindrome, the sequence will be identical.
Write C++ program with functions-
a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not

 */

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Stack Defination
class Stack
{
    char s[25];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(char val);
    char pop();
};

class Operation
{
    Stack obj;
    char inputStr[25], revStr[25];

public:
    void inputString();
    void reverseString();
    void convertString();
    void checkPalindrome();
};

// Stack operations
bool Stack::isEmpty()
{
    if (top <= -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top == 24)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::push(char val)
{
    if (isFull())
    {
        cout << "\nStack is already Full ! Stack Overflow";
    }
    else
    {
        top++;
        s[top] = val;
    }
}

char Stack::pop()
{
    char ele = '\0';
    if (isEmpty())
    {
        cout << "\nStack is already Empty ! Stack Underflow";
    }
    else
    {
        ele = s[top];
        top--;
    }
    return ele;
}

// Operation class definations
void Operation::inputString()
{
    cout << "\nEnter Input String : ";
    gets(inputStr);

    cout << "\nYou Entered: " << inputStr;
}

void Operation::convertString()
{
    int i, j = 0;
    char temp[25];

    for (i = 0; inputStr[i] != '\0'; i++)
    {
        if (inputStr[i] >= 97 && inputStr[i] <= 122)
        {
            temp[j] = inputStr[i];
            j++;
        }
        // convert uppercase letter to lower case
        else if (inputStr[i] >= 65 && inputStr[i] <= 190)
        {
            temp[j] = inputStr[i] + 32;
            j++;
        }
    }
    temp[j] = '\0'; // set last letter to null

    strcpy(inputStr, temp);

    cout << "\nYour Converted String : " << inputStr;
}

// Reverse the Given String
void Operation::reverseString()
{
    int i, j;

    // store the string in stack
    for (i = 0; inputStr[i] != '\0'; i++)
    {
        obj.push(inputStr[i]);
    }

    // now return/pop the string and store them to reverseStr

    i = 0;
    while (!obj.isEmpty())
    {
        revStr[i] = obj.pop();
        i++;
    }

    // display reverse string
    cout << "\nString after Reverse: " << revStr;
}

// check palindrome
void Operation::checkPalindrome()
{

    if (strcmp(inputStr, revStr) == 0)
        cout << "\n\nYour String is Palindrome !\n";
    else
        cout << "\n\nYour String is Not Palindrome !\n";
}

// main program
int main()
{
    Operation o1;
    o1.inputString();
    o1.convertString();
    o1.reverseString();
    o1.checkPalindrome();

    return 0;
}
