/*
Write C++ program for storing binary number using doubly linked lists. Write functions-
a) To compute 1‘s and 2‘s complement
b) Add two binary numbers

 */

#include <iostream>
using namespace std;

// class for Node defination
class Node
{

    Node *prev, *next;
    bool n; // for data

public:
    Node()
    {
        prev = NULL;
        next = NULL;
    }

    Node(bool b)
    {
        n = b;
        prev = NULL;
        next = NULL;
    }

    friend class Binary; // to perform operations
};

class Binary
{
    Node *start, *end;

    void prep(bool b)
    {
        if (start == NULL)
        {
            start = new Node(b);
            end = start;
        }
        else
        {
            Node *p = new Node(b);
            start->prev = p;
            p->next = start;
            start = p;
        }
    }

public:
    Binary()
    {
        start = NULL;
        end = NULL;
    }

    // decimal to binary
    void DtoB(int n)
    {

        // for first Element
        int rem = n % 2;
        Node *p;

        start = new Node(rem);
        end = start;
        n = n / 2;

        // After first element
        while (n != 0)
        {
            rem = n % 2;
            n = n / 2;
            p = new Node(rem);
            start->prev = p;
            p->next = start;
            start = p;
        }
    }

    // Binary to decimal
    int BtoD()
    {
        Node *temp = end;
        int i = 0, p = 1, s = 0;

        while (temp != NULL)
        {
            if (temp->n == 1)
            {
                p = 1;

                for (int j = 1; j <= i; j++)
                    p *= 2;
                s += p;
            }
            i += 1;
        }
        return s;
    }

    void onesComplement()
    {
        Node *temp = start;

        while (temp != NULL)
        {
            if (temp->n == 1)
                temp->n = 0;
            else
                temp->n = 1;
            temp = temp->next;
        }
    }
    void twosComplement()
    {
        Node *temp = end;
        onesComplement();
        int c = 1;

        // addition of binary number
        while (temp != NULL)
        {

            if (temp->n == 1 && c == 1)
            {
                temp->n = 0;
                c = 1;
            }

            else if (temp->n == 1 && c == 0)
                temp->n = 1;

            else if (temp->n == 0 && c == 1)
            {
                temp->n = 1;
                c = 0;
            }

            else
                temp->n = 0;
            temp = temp->prev;
        }
    }
    void display()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            cout << temp->n;
            temp = temp->next;
        }
    }

    // add binary values
    Binary operator+(Binary b)
    {
        Binary c;
        bool cry = 0;
        Node *temp1 = end, *temp2 = b.end;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->n == 1)
            {
                if (temp2->n == 1)
                {
                    if (cry == 1)
                        c.prep(1);
                    else
                    {
                        cry = 1;
                        c.prep(0);
                    }
                }
                else
                {
                    if (cry == 1)
                        c.prep(0);
                    else
                        c.prep(1);
                }
            }
            else
            {
                if (temp2->n == 1)
                {
                    if (cry == 1)
                        c.prep(0);
                    else
                        c.prep(1);
                }
                else
                {
                    if (cry == 1)
                    {
                        c.prep(1);
                        cry = 0;
                    }
                    else
                        c.prep(0);
                }
            }
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        if (temp1 == NULL)
            temp1 = temp2;
        while (temp1 != NULL)
        {
            if (cry == 1)
            {
                if (temp1->n == 1)
                    c.prep(0);
                else
                {
                    c.prep(1);
                    cry = 0;
                }
            }
            else
                c.prep(temp1->n);
            temp1 = temp1->prev;
        }
        if (cry == 1)
            c.prep(1);
        return c;
    }
};

int main()
{
    bool f = true;
    while (f)
    {
        int ch;
        int n;
        Binary b, d;
        cout << "\n\nEnter your choice : \n";
        cout << "1)Generate binary from decimal \n2)1's complement \n3)2's complement \n4)Add 2 binary numbers \n5)Exit " << endl;
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            cout << "Enter the decimal number to generate binary : ";
            cin >> n;
            b.DtoB(n);
            cout << "The binary equivalent of no is : ";
            b.display();
            break;
        case 2:
            cout << "Enter the decimal number to generate binary and display 1's complement : ";
            cin >> n;
            b.DtoB(n);
            cout << "Equivalent binary is : ";
            b.display();
            b.onesComplement();
            cout << "\nThe 1's complement of given binary number is : ";
            b.display();
            break;
        case 3:
            cout << "Enter the decimal number to generate binary and display 2's complement : ";
            cin >> n;
            b.DtoB(n);
            cout << "The binary equivalent is : ";
            b.display();
            b.twosComplement();
            cout << "\nThe 2's complement of given binary number is : ";
            b.display();
            break;
        case 4:
            cout << "Enter first decimal number : ";
            cin >> n;
            b.DtoB(n);
            cout << "The binary equivalent is : ";
            b.display();
            cout << "\nEnter second decimal number : ";
            cin >> n;
            d.DtoB(n);
            cout << "The binary equivalent is : ";
            d.display();
            b = b + d;
            cout << "\nThe addition of numbers is : ";
            b.display();
            cout << " (" << b.BtoD() << ")";
            break;
        case 5:
            f = false;
        }
    }
    return 0;
}