#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node()
    {
        // cout << "~Node destructor for data: " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
class List
{
public:
    Node *head;
    Node *tail;

    List()
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
            head = newNode;
        }
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
};
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}
bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       //+1
        fast = fast->next->next; //+2
        if (slow == fast)
        {
            cout << "CYCLE EXISTS\n";
            return true;
        }
    }
    cout << "CYCLE DOESN'T EXISTS\n";
    return false;
}
void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       //+1
        fast = fast->next->next; //+2
        if (slow == fast)
        {
            cout << "CYCLE EXISTS\n";
            isCycle = true;
            break;
        }
    }
    if (!isCycle)
    {
        cout << "CYCLE DOESN'T EXIST\n";
    }
    slow = head;
    if (slow == fast) // special case: tail -> head
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        Node *prev = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // REMOVED THE CYCLE
    }
}
int main()
{
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.tail->next = ll.head;

    removeCycle(ll.head);
    printLL(ll.head);
}

/*
This program implements a singly linked list with cycle detection and removal functionality.

- The `Node` class represents a node in the linked list, with an integer `data` and a pointer `next` to the next node. It includes a destructor that handles recursive deletion when nodes are removed.

- The `List` class manages the linked list, offering the following:
  - `push_front`: Adds a new node to the front of the list.
  - `pop_front`: Removes the front node of the list.

- The `printLL` function prints the linked list from head to tail, indicating the end with "NULL".

- The `isCycle` function uses the Floyd’s Cycle-Finding Algorithm (fast and slow pointers) to check if a cycle exists in the linked list:
  - The `slow` pointer advances by one node, and the `fast` pointer by two.
  - If they meet, a cycle exists.

- The `removeCycle` function detects and removes a cycle, if present:
  - It checks for the cycle using the same fast-slow pointer approach.
  - If a cycle exists, it finds the start of the cycle and breaks it by setting the previous node’s `next` pointer to `NULL`.
  - It handles a special case where the cycle starts from the head, setting the `next` pointer of the last node to `NULL`.

- In `main`, nodes are added to the list, a cycle is created manually, then the cycle is detected and removed. The final list is printed.

This program demonstrates linked list manipulation, including detecting and removing cycles.
*/
