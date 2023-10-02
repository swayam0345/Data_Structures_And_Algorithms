/*
Approach:
    1. First, we will run a loop(say i) that will select every possible starting index of the subarray.
        The possible starting indices can vary from index 0 to index n-1(n = array size).
    2. Inside the loop, we will run another loop(say j) that will signify the ending index as well as the
        current element of the subarray. For every subarray starting from index i, the possible ending index
        can vary from index i to n-1(n = size of the array).
    3. Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j].
        Among all the sums the maximum one will be the answer.

Complexity Analysis:
    1. Time Complexity
        O(N^2), where N = size of the array.
        Reason: We are using two nested loops, each running approximately N times.
    2. Space Complexity
        O(1) as we are not using any extra space.
*/


#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will return the maximum subarray sum of the input array
 * 
 * @param arr The input array
 * @param n Size of the input array
 * @return int 
 */
int maxSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN;     // maximum sum

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            // current subarray = arr[i.....j]

            // Add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum);  // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = size(arr);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}