/*
Intuition:
    ● We are required to find the longest subarray that sums to zero.
    ● So our initial approach could be to consider all possible subarrays of the given array and
      check for the subarrays that sum to zero.
    ● Among these valid subarrays (a sum equal to zero) we’ll return the length of the largest
      subarray by maintaining a variable.

Approach:
    1. Initialize a variable sum = 0 which stores sum of the subarray, and maxLen = 0, which stores
       the length of the longest subarray with a sum of 0.
    2. Traverse the array from the start and initialize variable sum = 0 and add it up with the element
       present in the current index `i`.
    3. Using a nested loop traverse from the next element of current index up to the end of the array,
       each time add the element to the sum and check if it is equal to 0.
    4. If sum = 0, check if the length of the subarray so far is > max and if yes update max.
        maxLen = max(maxLen, (j-i+1))
    5. Now keep adding elements and repeat step 4.
    6. After the outer loop traverses all elements return max.

Complexity Analysis:
    1. Time Complexity: O(N^2), as we have two loops for traversal
    2. Space Complexity: O(1), as we aren’t using any extra space.
*/


#include<bits/stdc++.h>
using namespace std;


int findSubArraySumZero(vector<int>& arr, int n)
{
    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        sum += arr[i];
        for(int j = i+1; j < n; j++)
        {
            sum += arr[j];
            if(sum == 0)
                maxLen = max(maxLen, (j-i+1));
        }
    }

    return maxLen;
}

int main()
{
    vector<int> Arr = {9, -3, 3, -1, 6, -5};
    int N = Arr.size();
    int result = findSubArraySumZero(Arr, N);

    cout << "The maximum subarray length whose sum is zero is: " << result;
    return 0;
}
