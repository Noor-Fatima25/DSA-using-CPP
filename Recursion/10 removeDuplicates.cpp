#include <iostream>
#include <string>
using namespace std;

// WITH USING 'i'
void removeDuplicates(string str, string ans, int i, int map[26])
{
    if (i == str.size())
    {
        cout << "ans: " << ans << endl;
        return;
    }
    int mapIdx = (int)(str[i] - 'a');

    if (map[mapIdx]) // duplicate
    {
        removeDuplicates(str, ans, i + 1, map);
    }
    else // not duplicate
    {
        map[mapIdx] = true;
        removeDuplicates(str, ans + str[i], i + 1, map);
    }
}

// WITHOUT USING 'i'
void removeDuplicates(string str, string ans, int map[26])
{
    if (str.size() == 0)
    {
        cout << "ans : " << ans << endl;
        return;
    }

    int n = str.size();

    char ch = str[n - 1];

    int mapIdx = (int)(str[n - 1] - 'a');
    str = str.substr(0, n - 1);

    if (map[mapIdx])
    { // duplicate
        removeDuplicates(str, ans, map);
    }
    else
    { // not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ch + ans, map);
    }
}

int main()
{
    string str = "meowwoowmeowowwo";
    string ans = "";
    int map[26] = {0}; // Initialize with 0

    removeDuplicates(str, ans, 0, map);
    
    // Reset the map for the next call
    fill(begin(map), end(map), 0);

    removeDuplicates(str, ans, map);
    return 0;
}
