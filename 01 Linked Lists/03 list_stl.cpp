#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int> ll)
{
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << (*itr) << " -> ";
    }
    cout << "NULL" << endl;
}
int main()
{
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);

    printList(ll);

    cout << "size = " << ll.size() << endl;
    cout << "head = " << ll.front() << endl;
    cout << "back = " << ll.back() << endl;

    ll.pop_front();
    ll.pop_back();

    printList(ll);
    return 0;
}

/*
This program demonstrates the usage of the C++ Standard Library's `list` container, which provides a doubly linked list with various operations.

- The `printList` function iterates through the elements of the `list` container using an iterator and prints each element, followed by an arrow (`->`) to denote links between nodes, and ending with "NULL".

- In `main`, a `list<int>` is created, and several operations are performed on it:
  - `push_front` and `push_back` are used to add elements to the front and back of the list.
  - `printList` displays the current contents of the list.
  - The `size`, `front`, and `back` methods are used to retrieve and print the list's size, first element, and last element, respectively.
  - `pop_front` and `pop_back` remove elements from the front and back of the list.

This program showcases basic linked list operations using the C++ STL `list` container.
*/
