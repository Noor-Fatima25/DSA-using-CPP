#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};
class DoublyList
{
public:
    Node *head;
    Node *tail;
    DoublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void popFront()
    {
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main()
{
    DoublyList dbl;

    dbl.push_front(4);
    dbl.push_front(3);
    dbl.push_front(2);
    dbl.push_front(1);

    dbl.printList();

    dbl.popFront();
    dbl.printList();

    return 0;
}

/*
This program implements a doubly linked list in C++, which supports bidirectional traversal of nodes and allows insertion and deletion at both ends.

- The `Node` class represents each node in the doubly linked list. It contains an integer `data`, a pointer `next` to the next node, and a pointer `prev` to the previous node. The constructor initializes these pointers to `NULL`.

- The `DoublyList` class manages the doubly linked list and provides the following functionalities:
  - `push_front`: Adds a new node to the front of the list. If the list is empty, the new node becomes both `head` and `tail`. Otherwise, the new node is linked as the new `head`, and the previous head node's `prev` pointer is updated.
  - `popFront`: Removes the front node from the list and updates the `head` pointer. If the list becomes empty, it ensures proper pointer updates and memory cleanup.
  - `printList`: Prints the list from the head to the tail, displaying the nodes in a formatted way.

The `main` function demonstrates the use of `DoublyList` by adding nodes to the front, printing the list, removing the front node, and printing the list again.
*/
