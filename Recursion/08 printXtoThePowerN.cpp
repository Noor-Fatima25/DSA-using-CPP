#include <iostream>
using namespace std;
double myPow(double x, int n)
{
    // Handle negative exponent
    long long N = n; // Use long long to avoid overflow
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    if (N == 0)
    {
        return 1;
    }

    double halfPower = myPow(x, N / 2);
    double halfPowerSquare = halfPower * halfPower;

    if (N % 2 != 0)
    {
        return x * halfPowerSquare;
    }
    return halfPowerSquare;
}
int main()
{
    cout << myPow(2, 10) << endl;
    return 0;
}