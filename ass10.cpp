/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[].
Write C++ program using stack to check whether given expression is well parenthesized or not.
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
const int MAX = 25;
using namespace std;

// Stack Defination
class Stack
{
    char s[MAX];
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
    void checkParenthesis();
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
    if (top == MAX - 1)
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

void Stack::checkParenthesis()
{
    cout << "\nEnter # as a deliminator after expression(At the end)\n";
    cout << "\nEnter Expression: ";
    cin.getline(s, MAX, '#');

    int i, flag = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(s[i]);

        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {

            char ch = pop();
            if (s[i] == '(' && ch != ')' || s[i] == '{' && ch != '}' || s[i] == '{' && ch != '}')
            {
                cout << "Not parenthesized At " << i << " = " << s[i] << endl;
                flag = 1;
                break;
            }
        }
    }

    if (isEmpty() == 1 && flag == 0)
        cout << "\nExpresseion is Well Parenthesized.";
    else
        cout << "\nExpression is not Well Parenthesized.";
}

int main()
{
    int choice;
    do
    {
        Stack s;
        s.checkParenthesis();
        cout << "\nDO you want to continue?{1/0)";
        cin >> choice;
    } while (choice != 0);
    return 0;
}
