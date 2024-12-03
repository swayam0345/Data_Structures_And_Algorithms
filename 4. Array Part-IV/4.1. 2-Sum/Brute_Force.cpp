/*
Intuition:
    ● For each element of the given array, we will try to search for another element such that its sum is equal to the target.
    ● If such two numbers exist, we will return the indices and “YES” accordingly, and if not then we will return (-1, -1) and "NO".

Approach:
    1. First, we will use a loop(say i) to select the indices of the array one by one.
    2. For every index `i`, we will traverse through the remaining array using another loop(say `j`) 
       to find the other number such that the sum is equal to the target (i.e. arr[i] + arr[j] = target).

Complexity Analysis:
    1. Time Complexity - O(N^2), as we are iterating through two loops (nested).
    2. Space Complexity - O(1), we are not using extra space anywhere.
*/

#include <bits/stdc++.h>
using namespace std;

string twoSumVariant1(int n, vector<int> &arr, int target)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }

    return "NO";
}


vector<int> twoSumVariant2(int n, vector<int> &arr, int target)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return {-1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    string ans1 = twoSumVariant1(n, arr, target);
    cout << "This is the answer for variant 1: " << ans1 << endl;

    vector<int> ans2 = twoSumVariant2(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans2[0] << ", " << ans2[1] << "]" << endl;

    return 0;
}
