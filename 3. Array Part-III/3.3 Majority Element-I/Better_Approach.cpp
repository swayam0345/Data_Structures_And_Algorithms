/*
Intuition:
    Use a better data structure to reduce the number of look-up operations and hence the time complexity.
    Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

Approach:
    1. Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums)
    2. Here the key will be the element of the array and the value will be the number of times it occurs.
    3. Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2.
        ● If yes, return the key
        ● Else iterate forward

Complexity Analysis
    1. Time Complexity - O(N*logN) + O(N), where N = size of the given array.
        Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements.
                So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times.
                If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be
                O(N^2).

    2. Space Complexity - O(N), as we are using a map data structure.
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

    // declaring a map:
    map<int, int> mpp;

    // storing the elements with its occurnce:
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }

    // searching for the majority element:
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
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
