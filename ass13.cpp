/*
Pizza parlor accepting maximum M orders. Orders are served in first come first served basis.
Order once placed cannot be cancelled.
Write C++ program to simulate the system using circular queue using array.

 */

#include <iostream>
using namespace std;
#define MAX 5

class PizzaParlour
{
    int orders[MAX];
    int front, rear;

public:
    PizzaParlour()
    {
        front = -1;
        rear = -1;
    }

    bool addOrder(int o)
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
            orders[front] = o;
            return true;
        }
        else
        {

            int pos = (rear + 1) % MAX; // circuler pointer
            if (pos == front)
            {
                cout << "\nOrders Not Accepting.. Order are full";
                return false;
            }
            else
            {
                rear = pos;
                orders[rear] = o;
                return true;
            }
        }
    }

    // serve orders
    void serveOrder()
    {
        if (front == -1)
        {
            cout << "\nNo orders !";
            return;
        }
        else
        {

            cout << "\nOrder No. " << orders[front] << " is Served\n";
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
        }
    }

    // display
    void Display()
    {
        if (front == -1)
            cout << "\nNo orders!\n";
        else
        {
            for (int i = front; i != rear; i = ((i + 1) % MAX))
            {
                cout << orders[i] << "\t";
            }
            cout << orders[rear] << endl;
        }
    }
};
int main()
{
    int id = 0, choice = 0;

    PizzaParlour obj;

    while (choice != 4)
    {
        cout << "\n1)Accept Order \n2)Serve Order \n3)Display Orders\n4)Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            id++;
            if (obj.addOrder(id))
            {
                cout << "Thank you for order.Order id is : " << id << endl;
            }
            else
            {
                id--;
            }
            break;

        case 2:
            obj.serveOrder();
            break;

        case 3:
            obj.Display();
            break;

        case 4:
            break;
        }
    }
    return 0;
}