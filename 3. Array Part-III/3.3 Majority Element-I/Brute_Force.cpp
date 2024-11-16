/*
Approach:
    The steps are as follows:
    1. We will run a loop that will select the elements of the array one by one.
    2. Now, for each element, we will run another loop and count its occurrence in the given array.
    3. If any element occurs more than the floor of (N/2), we will simply return it.

Complexity Analysis:
    1. Time Complexity - O(N^2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times.
                         And there are N elements in the array. So, the total time complexity is O(N^2).
    2. Space Complexity: O(1) as we use no extra space.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will return the majority element in the array.
 *
 * @param v The input vector
 * @return int The majority element
 */
int majorityElement(vector<int> v)
{
    // size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (v[j] == v[i])
            {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);

    cout << "The majority element is: " << ans << endl;

    return 0;
}