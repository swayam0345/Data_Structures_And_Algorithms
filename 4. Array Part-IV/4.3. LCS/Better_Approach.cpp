/*
Intuition:
    ● We can sort the input array and then find consecutive elements.
    ● Now we will run a loop to iterate the entire array and check the consecutive elements.
        arr[i] = arr[i-1] + 1
    ● Here we need to consider boundary case, where the array is empty. In that case we will have to return 0;


Approach:
    1. We will consider 2 variables, 
        ● ‘lcs’     → to store the maximum length
        ● ‘count’   → to store the length of the current sequence 
    2. Initialize ‘lcs’ with 0, and ‘count’ with 1.
    3. First, we will sort the entire array.
    4. To begin, we will utilize a loop(say i) to iterate through each element one by one.
    5. For every element, we will check if this can be a part of the current sequence like the following:
        (a) if (nums[i + 1] == nums[i])
            This means the next element is a duplicate of the previous element. So, we will skip it.
        (b) else if (nums[i + 1] == nums[i] + 1)
            This means the next element is a consecutive element and hence we will increment the count and
            update the value of ‘lcs’ by choosing max of ‘lcs’ and ‘count’.
        (c) If above two conditions aren't satisfied
            This means the end of a consecutive sequence. So, we will reset the value of ‘count’ to 1.
    6. Finally, once the iteration is complete, we will have the answer stored in the variable ‘lcs’.


Complexity Analysis:
    1. Time Complexity: O(NlogN) + O(N), N = size of the given array.
        Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).
    2. Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/


#include<bits/stdc++.h>
using namespace std;


int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    int lcs = 1;
    int count = 1;

    /* Boundary case with empty input array */
    if (n == 0)
        return 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i + 1] == nums[i])
        {
            continue;
        }
        else if (nums[i + 1] == nums[i] + 1)
        {
            count++;
            lcs = max(count, lcs);
        }
        else
            count = 1;
    }

    return lcs;
}

int main()
{
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    int lcs = longestConsecutive(arr);
    cout << "Longest Consecutive Sequence in the Array is of length " << lcs << endl;

    return 0;
}