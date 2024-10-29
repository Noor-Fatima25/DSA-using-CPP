#include <iostream>
using namespace std;
const int MAX = 100;
int stack[MAX];
int top = -1;
void push(int el)
{
    if (top >= MAX - 1)
    {
        cout << "Stack overflow! Cannot push more elements.\n";
    }
    else
    {
        stack[++top] = el;
        cout << el << " pushed onto the stack.\n";
    }
}
void pop()
{
    if (top < 0)
    {
        cout << "Stack underflow! No elements to pop.\n";
    }
    else
    {
        cout << stack[top--] << " popped from the stack.\n";
    }
}
void display()
{
    if (top < 0)
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Stack elements(top to bottom):\n";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
}
int main()
{
    int choice, element;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push in the stack\n";
        cout << "2. Pop from the stack\n";
        cout << "3. Display stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to push: ";
            cin >> element;
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please choose a valid option.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
