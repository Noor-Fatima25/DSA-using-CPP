#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> deq;

    deq.push_front(2);
    deq.push_front(1);

    deq.push_back(3);
    deq.push_back(4);

    // deque state: 1 2 3 4
    deq.pop_front(); // removes 1
    deq.pop_back();  // removes 4

    cout << deq.front(); // Output: 2
    cout << deq.back();  // Output: 3

    return 0;
}
