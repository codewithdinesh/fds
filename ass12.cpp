/*

A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end.
Obtain a data representation mapping a deque into a one-dimensional array.
Write C++ program to simulate deque with functions to add and delete elements from either end of the deque

 */

#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
    int items[MAX], front, rear;

public:
    // create queue
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // push item from back
    void push_back(int value)
    {

        if (front == 0 && rear == MAX - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            items[rear] = value;
            cout << value << " Inserted into Queue" << endl;
        }
    }

    // push element from front
    void push_front(int value)
    {

        if (front == -1)
            front = rear = 0;

        if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            // decrease top and assign value
            front--;
        }
        items[front] = value;
    }

    // pop front item
    void pop_front()
    {
        int delete_element;
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            delete_element = items[front];

            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            cout << delete_element << " deleted from Queue" << endl;
        }
    }

    // pop back item - last item
    void pop_back()
    {

        if (rear > -1)
        {

            cout << items[rear] << " Deleted from Queue\n";

            rear--;
        }
        else
        {
            cout << "Queue is Underflow";
        }
    }

    void print()
    {
        cout << "Queue : " << endl;

        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            // cout << "\nHead = " << front << " \t Rear=" << rear << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << items[i] << endl;
            }
        }
    }
};

int main()
{

    Queue queue;
    queue.push_back(5);
    queue.push_back(10);
    queue.push_back(15);
    queue.print();

    cout << "\n";

    queue.pop_front();
    queue.print();

    cout << "\n";

    queue.pop_front();
    queue.push_front(20);
    queue.push_front(30);
    queue.print();

    cout << "\n";
    queue.pop_back();
    queue.print();
    return 0;
}