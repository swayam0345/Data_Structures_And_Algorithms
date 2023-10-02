/*
Approach:
    1. First, we will run a loop(say i) that will select every possible starting index of the subarray.
        The possible starting indices can vary from index 0 to index n-1(n = size of the array).
    2. Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray.
        For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
    3. After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate
        the sum of all the elements(of that particular subarray).

Complexity Analysis:
    1. Time Complexity
        O(N^3), where N = size of the array.
        Reason: We are using three nested loops, each running approximately N times.
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
        for (int j = i; j < n; j++)
        {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(maxi, sum);
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