/*
Approach:
    We will be using the "Linked List cycle method".

      0   1   2   3   4   5   6   7   8   9
      |   |   |   |   |   |   |   |   |   |
    __▼___▼___▼___▼___▼___▼___▼___▼___▼___▼__
    |_2_|_5_|_9_|_6_|_9_|_3_|_8_|_9_|_7_|_1_|

    Initially, we have 2, then we got to the second index, we have 9, then we go to the 9th index, we have 1,
    then we go to the 1st index, we again have 5, then we go to the 5th index, we have 3, then we go to the
    3rd index, we get 6, then we go to the 6th index, we get 8, then we go to the 8th index, we get 7, then we
    go to the 7th index and we get 9 and here cycle is formed.

    Steps to follow:
    1. We initialize two pointers 'slow' and 'fast'.
    2. Now initially, the slow and fast pointer is at the start, the slow pointer moves by one step, and the fast pointer moves by 2 steps.
    3. The 'slow' and 'fast' pointers meet at 7. Now take the 'fast' pointer and place it at the first element i.e 2 and move the 'fast' and
        'slow' pointer both by 1 step. The point where they collide will be the duplicate number.

    slow = 0, fast = 0;
    _________________________________________________________
    | Iteration  |  slow=arr[slow]  |  fast=arr[arr[fast]]  |
    ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
    | 1 		 |       2          |         2			    |
    | 2		     |		 9			|		  1				|
    | 3          |       1          |         3             |
    | 4          |       5          |         8             |
    | 5          |       3          |         9             |
    | 6          |       6          |         5             |
    | 7          |       8          |         6             |
    | 8          |       7          |         7             |   Now the 'slow' & 'fast' pointers are in the same index. Move 'fast' to iteration 1.
    | 9          |       9          |         9             |   So, first = 2 and moving it by 1 index.
    ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯

Index   0      2      9      1      5      3      6      8
        2 ---> 9 ---> 1 ---> 5 ---> 3 ---> 6 ---> 8 ---> 7
               ▲                                         ▲
               |               Index - 7                 |
               ╰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯╯

Complexity Analysis:
    1. Time Complexity - O(N), Since we traversed through the array only once.
    2. Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will find the duplicate element in the input array.
 * 
 * @param nums The input array
 * @return int The duplicate element
 */
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];     // When slow = fast, then we will move the 'fast' pointer to 0th index.

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 3};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;

    return 0;
}
