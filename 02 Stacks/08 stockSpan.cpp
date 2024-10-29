#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stockSpan(vector<int> stock, vector<int>& span) // pass span by reference
{
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for (int i = 1; i < stock.size(); i++)
    {
        int currPrice = stock[i];
        while (!s.empty() && currPrice >= stock[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            int previousHigh = s.top();
            span[i] = i - previousHigh;
        }
        s.push(i); // Push the current index onto the stack
    }
    for (int i = 0; i < span.size(); i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stock.size(), 0); // Initialize span vector with size equal to stock

    stockSpan(stock, span);

    return 0;
}
