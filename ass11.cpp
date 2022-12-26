/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
 */

#include <iostream>
using namespace std;
const int MAX = 20;

class Queue
{
    int head, tail;
    int data[MAX];

public:
    Queue()
    {
        head = tail = -1;
    }
    bool isFull();
    bool isEmpty();
    void enQueue(int val);
    void deQueue();
    void display();
};

bool Queue::isEmpty()
{
    if (head == tail)
        return true;
    else
        return false;
}

bool Queue::isFull()
{
    if (tail == MAX - 1)
        return true;
    else
        return false;
}

void Queue::enQueue(int val)
{
    if (!isFull())
    {

        if (head == -1)
            head++;
        tail++;

        data[tail] = val;
    }
    else
        cout << "Queue Overflow !";
}

void Queue::deQueue()
{

    if (!isEmpty())
    {
        head++;
    }
    else
    {
        cout << "\nQueue Underflow !\n";
    }
}

void Queue::display()
{
    int i;

    if (!isEmpty())
    {

        cout << "\nJobs Remaining: \n";
        for (i = head; i <= tail; i++)
        {
            cout << data[i] << "\t";
        }
    }
    else
    {
        cout << " \nNo Job Remaining\n";
    }
}
int main()
{
    Queue q;

    int choice = 0;

    while (choice != 4)
    {
        cout << "\n1)Insert Job in Queue\n2)Delete Job\n3)Display Job\n4)Exit\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "\nEnter Job (int) : ";
            cin >> data;
            q.enQueue(data);
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            choice = 4;
            break;
        }
    }

    return 0;
}