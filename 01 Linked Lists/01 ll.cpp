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
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    ~List()
    {
        // cout << "~list\n";
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
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
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printLL()
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
    void insert(int value, int pos)
    {
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position is invalid";
                return;
            }
            temp = temp->next;
        }
        // temp is now at pos-1 OR left Node
        newNode->next = temp->next;
        temp->next = newNode;
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
    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL; // temp = tail's previous
        delete tail;
        tail = temp;
    }
    int searchItr(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int helper(Node *headd, int key)
    {
        if (headd == NULL)
        {
            return -1;
        }
        if (headd->data == key)
        {
            return 0;
        }
        int idx = helper(headd->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }
    int searchRecursive(int key)
    {
        return helper(head, key);
    }
    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        tail = head;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;

            // UPDATIONS FOR NEXT ITERATIONS
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int getSize()
    {
        int sz = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n)
    {
        int size = getSize();
        Node *prev = head;

        for (int i = 1; i < (size - n); i++)
        {
            prev = prev->next;
        }
        Node *toDelete = prev->next;
        cout << "GOING TO DELETE: " << toDelete->data;
        prev->next = prev->next->next;
    }
};
int main()
{
    List ll; // Correct object instantiation

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printLL();
    cout << ll.searchItr(2) << endl;
    // ll.push_back(4);
    // ll.push_back(5);
    // ll.printLL(); // Output: 1->2->3->4->5->NULL

    // ll.insert(100, 2);
    // ll.printLL(); // Output: 1->2->100->3->4->5->NULL
    ll.reverse();
    ll.printLL();
    return 0;
}
/*
This program implements a singly linked list in C++ with a variety of operations, encapsulated within the `List` and `Node` classes.

- The `Node` class represents individual nodes of the linked list, each containing an integer `data` and a pointer `next` to the next node. It includes a constructor for initialization and a destructor to manage dynamic memory cleanup by recursively deleting nodes.

- The `List` class manages the linked list and provides multiple functionalities:
  - `push_front` and `push_back`: Add nodes to the front and back of the list, respectively.
  - `printLL`: Prints the entire list in a formatted way.
  - `insert`: Inserts a node with a given value at a specified position.
  - `pop_front` and `pop_back`: Remove nodes from the front and back of the list.
  - `searchItr` and `searchRecursive`: Search for a specific value iteratively and recursively.
  - `reverse`: Reverses the linked list.
  - `getSize`: Returns the size of the linked list.
  - `removeNth`: Removes the nth node from the end of the list.

The `main` function demonstrates some of these operations, including adding nodes, printing the list, searching, and reversing the list.
*/
