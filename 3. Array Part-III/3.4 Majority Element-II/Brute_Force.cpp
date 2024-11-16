/*
Observation: How many integers can occur more than floor(N/3) times in the given array:
    If we closely observe, in the given array, there can be a maximum of two integers that can occur more than floor(N/3) times.
    Let’s understand it using the following scenario:
        Assume there are 8 elements in the given array. Now, if there is any majority element,
        it should occur more than floor(8/3) = 2 times. So, the majority of elements should occur
        at least 3 times. Now, if we imagine there are 3 majority elements, then the total occurrence
        of them will be 3X3 = 9 i.e. greater than the size of the array. But this should not happen.
        That is why there can be a maximum of 2 majority elements.

Approach:
    1. We will run a loop that will select the elements of the array one by one.
    2. Now, for each unique element, we will run another loop and count its occurrence in the given array.
    3. If any element occurs more than the floor of (N/3), we will include it in our answer. 
    4. While traversing if we find any element that is already included in our answer, we will just skip it.

Complexity Analysis
    1. Time Complexity: O(N^2), where N = size of the given array.
        Reason: For every element of the array the inner loop runs for N times.
                And there are N elements in the array. So, the total time complexity is O(N2).

    2. Space Complexity: O(1) as we are using a list that stores a maximum of 2 elements.
                        The space used is so small that it can be considered constant.
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
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++)
    {
        // Checking if v[i] is not already a part of the answer.
        if (ls.size() == 0 || ls[0] != v[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                // counting the frequency of v[i]
                if (v[j] == v[i])
                {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
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

