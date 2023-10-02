/*
The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0.
A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of 
the subarray with maximum sum.

Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable.
Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray
with a negative sum. Among all the sums calculated, we will consider the maximum one.

Thus we can solve this problem with a single loop.

Approach:
    1. We will run a loop(say i) to iterate the given array.
    2. Now, while iterating we will add the elements to the sum variable and consider the maximum one.
    3. If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

Complexity Analysis
    1. Time Complexity
        O(N), where N = size of the array.
        Reason: We are using a single loop running N times.
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
 * @return long long 
 */
long long maxSubarraySum(int arr[], int n) 
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}