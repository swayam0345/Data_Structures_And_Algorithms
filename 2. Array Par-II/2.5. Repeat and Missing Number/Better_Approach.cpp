/*
Intuition:
    Instead of counting the occurrences every time, using the hashing technique, we will store the frequency of each element between
    1 to N. Now, the element with frequency 2 will be the repeating number and the element with frequency 0 will be the missing number.
Approach:
    The steps are as follows:
    1. The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).
    2. We will iterate all the elements of the given array and update the hash array accordingly i.e. hash[a[i]] = hash[a[i]]+1.
    3. Now, we will iterate on the hash array and return the two elements with frequencies 2 and 0.

Complexity Analysis:
    Time Complexity - O(2N), where N = the size of the given array.
        Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).

    Space Complexity - O(N), as we are using a hash array to solve this problem.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will find the missing & repeating numbers using a hash to store the
 *        repeating and the missing number.
 * 
 * @param a The input array
 * @return vector<int> The element in 0th index is the repeating number & in index 1
 *                     is the missing number.
 */
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();      // size of the array
    int hash[n + 1] = {0}; // hash array

    // update the hash array:
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    // Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
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