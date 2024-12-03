/*
Approach:
    1. This approach consists of taking the two loops one for traversing the string and another loop - nested loop for finding
       different substrings.
    2. After that, we will check for all substrings one by one and check for each and every element if the element is not found
       then we will store that element in HashSet otherwise we will break from the loop and count it.


Time Complexity:
    1. Time Complexity: O(N^2)
    2. Space Complexity: O(N), where N is the size of HashSet taken for storing the elements

*/


#include <bits/stdc++.h>
using namespace std;

int longestSubStringNoRepeat(string str)
{
    if (str.size() == 0)
        return 0;

    int maxans = INT_MIN;
    int n = str.length();

    for (int i = 0; i < n; i++)                 // outer loop for traversing the string
    {
        unordered_set<int> set;
        for (int j = i; j < n; j++)             // nested loop for getting different string starting with str[i]
        {
            if (set.find(str[j]) != set.end())  // if element if found so mark it as ans and break from the loop
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
        }
    }

    return maxans;
}

int main()
{
    string str = "abcaabcdba";
    cout << "The length of the longest substring without repeating characters is " << longestSubStringNoRepeat(str);

    return 0;
}
