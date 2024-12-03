/*
Intuition:
    ● In this approach, we will first sort the array and will try to choose the numbers in a greedy way.
    ● We will keep a left pointer at the first index and a right pointer at the last index. Now until
       "left < right", we will check the sum of "arr[left]" and "arr[right]".
    ● Now if the "sum < target", we need bigger numbers and so we will increment the left pointer.
    ● But if "sum > target", we need to consider lesser numbers and so we will decrement the right pointer. 
    ● If "sum == target" we will return “YES” and the indices as per the question.
    ● But if the left crosses the right pointer, we will return “NO” and {-1, -1}.

Approach:
    1. We will sort the given array first.
    2. Now, we will take two pointers i.e. left, which points to the first index, and right, which points to the last index.
    3. Now using a loop we will check the sum of arr[left] and arr[right] until left < right.
    4. If arr[left] + arr[right] > sum, we will decrement the right pointer.
    5. If arr[left] + arr[right] < sum, we will increment the left pointer.
    6. If arr[left] + arr[right] == sum, we will return the result along with “Yes”.
    7. Finally, if no results are found we will return “No” and {-1, -1}.

Dry Run:
    Input Data:     Array ---> {2, 1, 3, 4}    Target ---> 4
    
    step-1: Sort the input array ---> {1, 2, 3, 4}
    step-2: Take two pointers left (pointing to the beginning of the array) and right (pointing to the end of the array).
    step-3: Iterate the sorted array until left < right. 
            ➤ _________________
               |_1_|_2_|_3_|_4_|        arr[left] + arr[right] = (1 + 4) > target (4) 
                 ▲           ▲          So, we will decrement the value of right.
                 |           |
               left        right

            ➤ _________________
               |_1_|_2_|_3_|_4_|        arr[left] + arr[right] = (1 + 3) = target (4) 
                 ▲       ▲              So, we will return the value of {left, right} along with "YES".
                 |       |
               left    right

Complexity Analysis:
    1. Time Complexity: O(N) + O(N*logN), where N = size of the array.
       Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.

    2. Space Complexity: O(1), as we are not using any extra space.
       Note: Here we are distorting the given array. So, if we need save a copy of the original array, the space complexity will be O(N).
*/

#include <bits/stdc++.h>
using namespace std;


std::pair<string, vector<int>> twoSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            return {"YES", {left, right}};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {"NO", {-1, -1}};
}


int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    auto result = twoSum(n, arr, target);

    cout << "This is the answer for variant 1: " << result.first << endl;
    cout << "This is the answer for variant 2: [" << result.second[0] << ", "
         << result.second[1] << "]" << endl;

    return 0;
}
