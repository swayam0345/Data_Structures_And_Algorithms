/*
Algorithm / Intuition:
    Let’s understand the Question more deeply. We are required to give the total number of inversions and the inversions are:
    For i & j < size of an array if i < j then you have to find pair (a[i], a[j]) such that a[i] > a[j].

    The naive approach is pretty straightforward. We will use nested loops to solve this problem. We know index i must be smaller
    than index j. So, we will fix i at one index at a time through a loop, and with another loop, we will check(the condition
    a[i] > a[j]) the elements from index i+1 to N-1  if they can form a pair with a[i]. This is the first naive approach we can think of.

    For example, for the given array: [5, 3, 2, 1, 4], (5, 3) will be a valid pair as 5 > 3 and
    index 0 < index 1. But (1, 4) cannot be valid pair.

Approach:
    The steps are as follows:
    1. First, we will run a loop(say i) from 0 to N-1 to select the first element in the pair.
    2. As index j should be greater than index i, inside loop i, we will run another loop i.e. j from i+1 to N-1.
    3. Inside this second loop, we will check if a[i] > a[j] i.e. if a[i] and a[j] can be a pair. If they satisfy
       the condition, we will increase the count by 1.
    4. Finally, we will return the count i.e. the number of such pairs.

Complexity Analysis
    1. Time Complexity - O(N^2), where N = size of the given array.
        Reason: We are using nested loops here and those two loops roughly run for N times.

    2. Space Complexity - O(1), as we are not using any extra space to solve this problem.
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfInversions(vector<int> &a, int n)
{

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;

    return 0;
}
