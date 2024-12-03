/*
Intuition:
    ● In this approach, we intend to get rid of two things i.e. the HashSet we were using for the look-up operation
      and the set data structure used to store the unique quadruplets.
    ● In this approach, we will fixed two pointer `i`, `j` and the rest 2 pointers (`k` & 'l`) will be moving until
      they cross over.
    ● Now, we need to first understand what the HashSet and the set were doing to make our algorithm work without them.
    ● So, the set data structure was basically storing the unique quadruplets in sorted order and the HashSet was
      used to search for the fourth element.
    ● To get the quadruplets in sorted order, we will sort the entire array in the first step and to get the unique quads,
      we will simply skip the duplicate numbers while moving the pointers.

    ⦿ How to skip duplicate numbers:
        ● As the entire array is sorted, the duplicate numbers will be in consecutive places.
        ● So, while moving a pointer, we will check the current element and the adjacent element.
          Until they become different, we will move the pointer by 1 place.
        ● We will follow this process for all 4 pointers. And easily skip the duplicate elements while moving the pointers.

    ● Now, we can also remove the HashSet as we have two moving pointers i.e. `k` and `l` that will find the appropriate value
      of nums[k] and nums[l]. So, we do not need the HashSet anymore.

Approach:
    1. First, we will sort the entire array.
    2. We will use a loop(say i) that will run from 0 to n-1. This `i` will represent one of the fixed pointers.
       In each iteration, this value will be fixed for all different values of the rest of the 3 pointers.
    3. Inside the loop, we will first check if the current and the previous element is the same and if it is we
       will do nothing and continue to the next value of i.
        if(nums[i] == nums[i-1]) continue;
    4. After checking inside the loop, we will introduce another fixed pointer `j` (runs from i+1 to n-1) using
       another loop. Inside this second loop, we will again check for duplicate elements and only perform any
       further operation if the elements are different.
    5. Inside the second loop, there will be 2 moving pointers i.e. `k` (starts from j+1) and `l` (starts from the last index).
       The pointer `k` will move forward and the pointer `l` will move backward until they cross each other while the value
       of `i` and `j` will be fixed.
    6. Now we will check the sum i.e. nums[i]+nums[j]+nums[k]+nums[l].
        ● If the sum is greater than the target, then we need lesser elements and so we will decrease the value of `l`.
        ● If the sum is lesser than the target, we need a bigger value and so we will increase the value of `k`. 
        ● If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l]
          into our answer and move the pointers.
    7. Once we find a resultant quad we need to move `k` and `l` by skipping the duplicate elements (i.e. by checking the
       adjacent elements while moving the pointers).
        while(k < l && nums[k] == nums[k-1]) k++;
        while(k < l && nums[l] == nums[l+1]) l--;
    8. Finally, we will have a list of unique quadruplets.


Dry Run:
    Let take the below as inputs to our program.
                _____________________________________________________________
    array --->  |_5_|_2_|_2_|_1_|_4_|_4_|_5_|_3_|_2_|_5_|_1_|_1_|_4_|_3_|_3_|           Target ---> 8


    Sort the input array:   _____________________________________________________________
                            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|

    Iteration-1: Keeping fixed pointers `i` at index 0 & `j` at index 1.
        ➤ Now we will move `k` to j+1 and `l` to n-1
            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           k = j+1 = 2;    l = n-1 = 14;
              ▲   ▲   ▲                                               ▲             sum = nums[i] + nums[j] + nums[k] + nums[l];
              |   |   |                                               |             sum = 1 + 1 + 1 + 5 = 8
              i   j   k                                               l             so, (sum == target)
                                                                                    ans = { {1, 1, 1, 5} }

            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           k++ = 3;     l-- = 13; but nums[l] == nums[l+1]
              ▲   ▲       ▲                               ▲   ▲   ▲                 l-- = 12; but nums[12] == nums[13]
              |   |       |                               |   |   |                 l-- = 11; and nums[11] != nums[12], so l=11
              i   j       k                               l   l-1 l-1               sum = 1 + 1 + 2 + 4 = 8
                                                          ✔   ✘   ✘                so, (sum == target)
                                                                                    ans = { {1, 1, 1, 5} {1, 1, 2, 4} }

            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           k++ = 4; but nums[4] == nums[3]
              ▲   ▲           ▲   ▲   ▲       ▲   ▲   ▲                             k++ = 5; but nums[5] == nums[4]
              |   |           |   |   |       |   |   |                             k++ = 6; and nums[6] != nums[5], so k=6
              i   j          k+1  k+1 k       l   l-1 l-1                           Similarly, l = 8
                             ✘   ✘   ✔      ✔   ✘   ✘                            sum = 1 + 1 + 3 + 3 = 8
                                                                                    so, (sum == target)
                                                                                    ans = { {1, 1, 1, 5} {1, 1, 2, 4} {1, 1, 3, 3} }

            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           k++ = 7; but nums[7] == nums[6]
              ▲       ▲   ▲               ▲                                         l-- = 7; but (k !< l)
              |       |   |               |                                         So, now we will increment `j`
              i      j+1  j              k,l                                        j++ = 2; but nums[j] == nums[j-1]
                      ✘  ✔               ✘                                         j++ = 3; and nums[3] != nums[2]

    Iteration-2: Keeping fixed pointers `i` at index 0 & `j` at index 3,
            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           i = 0 and j = 3
              ▲       ▲   ▲   ▲                                       ▲             now, k = j+1 = 4 and l = n-1 = 14
              |       |   |   |                                       |             sum  = 1 + 2 + 2 + 5 = 10
              i      j+1  j   k                                       l             now, (sum > target) So, we will decrement `l`
                      ✘  ✔                                                         ans = { {1, 1, 1, 5} {1, 1, 2, 4} {1, 1, 3, 3} }

            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           i = 0 and j = 3
              ▲           ▲   ▲                           ▲   ▲   ▲                 k = 4 and l = 11
              |           |   |                           |   |   |                 sum  = 1 + 2 + 2 + 4 = 9
              i           j   k                           l  l-1  l-1               now, (sum > target) So, we will decrement `l`
                                                          ✔   ✘   ✘                ans = { {1, 1, 1, 5} {1, 1, 2, 4} {1, 1, 3, 3} }

            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           i = 0 and j = 3
              ▲           ▲   ▲               ▲   ▲   ▲                             k = 4 and l = 8
              |           |   |               |   |   |                             sum  = 1 + 2 + 2 + 3 = 9
              i           j   k               l  l-1  l-1                           so, (sum == target)
                                              ✔   ✘   ✘                            ans = { {1, 1, 1, 5} {1, 1, 2, 4} {1, 1, 3, 3} {1, 2, 2, 3} }

            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           i = 0 and j = 3
              ▲           ▲       ▲   ▲                                             k = 6 and l = 5
              |           |       |   |                                             Since, k and l have overlapped we will increment `j` again.
              i           j       l   k
                                  ✘   ✘

        ➤ Now `j` will iterate until the end of array, and once j reaches end of the array we will increment `i`.

    Iteration-3: Final result after all the iteration of `j` are completed.
                 ans = { {1, 1, 1, 5} {1, 1, 2, 4} {1, 1, 3, 3} {1, 2, 2, 3} }

    Iteration-4: Now we will increment the fixed pointer `i`.
            _____________________________________________________________
            |_1_|_1_|_1_|_2_|_2_|_2_|_3_|_3_|_3_|_4_|_4_|_4_|_5_|_5_|_5_|           i++ = 1; but nums[i] == nums[i-1] i,e; nums[1] == nums[0]
                  ▲   ▲   ▲   ▲   ▲                                   ▲             i++ = 2; but nums[2] == nums[1]
                  |   |   |   |   |                                   |             i++ = 3; nums[3] != nums[2], So i = 3
                 i+1 i+1  i   j   k                                   l             j = i+1 = 4, k = j+1 = 5 and l = n-1 = 14
                 ✘   ✘   ✔                                                         sum = 2 + 2 + 2 + 5 = 11
                                                                                    now, (sum > target), so we will decrement `l`.

    Iteration-5: After all the iterations of `i` are done, we will have the below vector as our final answer.
                 ans = { {1, 1, 1, 5} {1, 1, 2, 4} {1, 1, 3, 3} {1, 2, 2, 3} }


Complexity Analysis:
    1. Time Complexity: O(N^3), where N = size of the array.
        Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run
                for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N^3).

    2. Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra
                         space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/


#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int n = nums.size();    //size of the array
    vector<vector<int>> ans;

    // sort the input array
    sort(nums.begin(), nums.end());

    //calculating the quadruplets
    for (int i = 0; i < n; i++)
    {
        // avoid the duplicates while moving `i`
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // avoid the duplicates while moving j
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // two moving pointers
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    //skip the duplicates
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }

    return ans;
}


int main()
{
    vector<int> nums = {4, 3, 3, 5, 4, 4, 2, 5, 1, 2, 2, 1, 1, 3, 5};
    int target = 8;

    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: ";
    for (auto it : ans)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
