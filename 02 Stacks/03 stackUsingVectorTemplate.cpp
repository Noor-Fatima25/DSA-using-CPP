#include <iostream>
#include <vector>
using namespace std;

// CREATE STACK USING VECTOR
template <class T>
class Stack
{
private:
    vector<T> vec;

public:
    void push(T val)
    { // O(1)
        vec.push_back(val);
    }
    void pop()
    { // O(1)
        if (isEmpty())
        {
            cout << "Stack is empty";
            return;
        }
        vec.pop_back();
    }
    T top()
    { // O(1)
        // if (isEmpty())
        // {
        //     cout << "Stack is empty";
        //     return -1;
        // }
        int lastIndex = vec.size() - 1;
        return vec[lastIndex];
    }
    bool isEmpty()
    {
        return vec.size() == 0;
    }
};

int main()
{
    Stack<char> s;
    s.push('c');
    s.push('b');
    s.push('a');

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}