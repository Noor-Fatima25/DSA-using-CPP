// WAF TO FIND FIRST OCCURRENCE OF AN ELEMENT IN A VECTOR
#include <iostream>
#include <vector>
using namespace std;
int firstOccurrence(vector<int> arr, int i, int target)
{
    if(i==arr.size()){
        return -1;
    }
    if (arr[i] == target)
    {
        return i;
    }
    return firstOccurrence(arr, i + 1, target);
}
int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};

    cout << firstOccurrence(arr, 0, 3);
    return 0;
}