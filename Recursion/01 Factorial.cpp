// Program to calculate the factorial of a number using recursion
#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int main()
{
    int ans = factorial(5);
    cout << ans << endl;
    return 0;
}