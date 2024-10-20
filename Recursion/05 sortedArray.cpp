// CHECK IF ARRAY IS SORTED
#include <iostream>
using namespace std;
bool isSorted(int arr[], int n, int i)
{
    if (i == n - 1)
    {
        // WHEN WE ARE ON THE LAST INDEX OF OUR ARRAY
        return true;
    }

    if (arr[i] > arr[i + 1])
    {
        return false;
    }
    return isSorted(arr, n, i + 1);
}
int main()
{
    int arr1[5] = {1, 2, 3, 4, 5}; // sorted: 1
    int arr2[5] = {1, 2, 4, 3, 5}; // unsorted: 0

    cout << isSorted(arr1, 5, 0) << endl;
    cout << isSorted(arr2, 5, 0) << endl;
    return 0;
}