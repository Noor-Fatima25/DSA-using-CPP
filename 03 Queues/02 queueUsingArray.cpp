#include <iostream>
using namespace std;

class Queue
{
    int *arr; // a pointer to our array
    int capacity;
    int currSize; // how many elements are currently stored in our array
    int front, rear;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        front = 0;
        rear = -1;
    }

    void push(int data)
    {
        if (currSize == capacity)
        {
            cout << "Queue is full... :(\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty... :(\n";
            return;
        }
        front = (front + 1) % capacity;
        currSize--;
    }

    int getFront()
    {
        if (empty())
        {
            cout << "Queue is empty... :(\n";
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        return currSize == 0;
    }
    void printRear()
    {
        cout << arr[rear];
    }
};

int main()
{
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // will print "Queue is full... :("

    cout << q.getFront() << endl;
    q.pop();
    cout << q.getFront() << endl;
    q.push(5);
    q.printRear();
    return 0;
}
