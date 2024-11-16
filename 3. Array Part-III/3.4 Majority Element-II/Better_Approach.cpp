/*
Intuition(Using Hashing):
    Using a better data structure to reduce the number of look-up operations and hence the time complexity.
    Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

Approach:
The steps are as follows:
    1. Use a hashmap and store the elements as <key, value> pairs. (Can also use frequency array based on the size of nums).
        Here the key will be the element of the array and the value will be the number of times it occurs.
    2. Traverse the whole array and update the occurrence of each element.
    3. After that, check the map if the value for any element is greater than the floor of N/3.
        (a) If yes, include it in the list.
        (b) Else iterate forward.
    4. Finally, return the list.

Complexity Analysis
    1. Time Complexity: O(N*logN), where N = size of the given array.
        Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements.
                So, it results in the first term O(N*logN).
        If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case,
        it will be O(N2).

    2. Space Complexity: O(N) as we are using a map data structure. We are also using a list that stores a maximum of 2 elements.
                        That space used is so small that it can be considered constant.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will return the majority element(⌊n/3⌋) in the array.
 * 
 * @param v The input vector
 * @return vector<int> The majority element(s)
 */
vector<int> majorityElement(vector<int> v)
{
    int n = v.size();
    vector<int> ls;

    map<int, int> mpp;  // Declaring an unordered map

    // least occurrence of the majority element
    int mini = int(n / 3) + 1;

    // storing the elements with its occurnce
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;

        // checking if v[i] is the majority element
        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2)
            break;
    }

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);

    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";

    return 0;
}
