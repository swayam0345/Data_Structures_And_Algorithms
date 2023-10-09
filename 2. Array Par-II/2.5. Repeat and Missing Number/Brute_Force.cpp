/*
Intuition:
    For each number between 1 to N, we will try to count the occurrence in the given array using linear search.
    And the element with occurrence as 2 will be the repeating number and the number with 0 occurrences will be the missing number.
Approach:
    The steps are as follows:
    1. We will run a loop(say i) from 1 to N.
    2. For each integer, i, we will count its occurrence in the given array using linear search.
    3. We will store those two elements that have the occurrence of 2 and 0.
    4. Finally, we will return the elements.

Complexity Analysis:
    1. Time Complexity - O(N^2), where N = size of the given array.
        Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.

    2. Space Complexity - O(1) as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will find the missing & repeating numbers using linear search.
 * 
 * @param a The input array
 * @return vector<int> The element in 0th index is the repeating number & in index 1
 *                     is the missing number.
 */
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size(); // size of the array
    int repeating = -1, missing = -1;

    // Find the repeating and missing number:
    for (int i = 1; i <= n; i++)
    {
        // Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
                cnt++;
        }

        if (cnt == 2)
            repeating = i;
        else if (cnt == 0)
            missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }

    return {repeating, missing};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);

    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";

    return 0;
}
