// WAF TO FIND LAST OCCURRENCE OF AN ELEMENT IN A VECTOR
#include <iostream>
#include <vector>
using namespace std;
int lastOccurrence(vector<int> arr, int target, int i)
{
    if (i == arr.size())
    {
        return -1;
    }
    int idxFound = lastOccurrence(arr, target, i + 1);
    if (idxFound == -1 && arr[i] == target)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return idxFound;
}
int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};
    cout << lastOccurrence(arr, 3, 0);

    return 0;
}