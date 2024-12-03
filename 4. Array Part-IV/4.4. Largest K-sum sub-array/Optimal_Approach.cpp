/*
Intuition: 
    ● Now let’s say we know that the sum of subarray(i, j) = S, and we also know that the sum of subarray(i, x) = S,
      where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.
    ● Let us understand the above statement clearly,
      So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have the same
      prefix sum, we can conclude that the 2nd part of this subarray sums to zero.
                
                              Sum = 0 (i=3, j=4)    i.e; i = x+1 = 2+1 = 3, and j = 4
                              ____↓___
                ______________|______|_______________________
                |_1_|_-1_|_3_|_2_|_-2_|_-8_|_1_|_7_|_10_|_21|
                 ||________|        |
                 |  Sum = 3         |
                 |  (i=0, x=2)      |
                 |__________________|
                    Sum = 3
                    (i=0, j=4)


Approach:
    1. First, let us initialize a variable say sum = 0 which stores the sum of elements traversed so far and another variable say
       maxLen = 0 which stores the length of the longest subarray with sum zero.
    2. Declare an unordered map<Integer, Integer> which stores the prefix sum of every element as a key and its index as a value.
    3. Now we traverse the array, and add the array element to our sum.
        (a) If sum = 0, then we can say that the subarray until the current index has a sum = 0,
            So we update maxLen with the maxLenimum value of (maxLen, current_index+1).
        (b) If sum != 0, then we check the map if we’ve come across a subarray with this sum before.
            ● if the map contains sum -> this is where the above-discussed case occurs (subarray with equal sum),
              so we update our maxLen.
            ● else -> Insert (sum, current_index) into map to store prefix sum until the current index.
    4. After traversing the entire array our maxLen variable has the length of the longest substring having a sum equal to zero,
       so return maxLen.


Dry Run:
    Let take the below as inputs to our program.
                              _______________________
        N = 5       array[] = |_1_|_2_|_-2_|_4_|_-4_|


        Iteration-1: i = 0, sum = 0 + arr[0] = 1
                    Search for the value of 'sum' in the map.                       ___Key_____Value__
                    Since, there's no match for '1', We will                        |_______||_______|
                    store it in the map along with it's index.                      |_______||_______|
                                                                                    |_______||_______|
                                                                                    |_______||_______|
                                                                                    |___0___||___1___|

        Iteration-2: i = 1, sum = 1 + arr[1] = 3
                    Search for the value of 'sum' in the map.                       ___Key_____Value__
                    Since, there's no match for '3', We will                        |_______||_______|
                    store it in the map along with it's index.                      |_______||_______|
                                                                                    |_______||_______|
                                                                                    |___1___||___3___|
                                                                                    |___0___||___1___|

        Iteration-3: i = 2, sum = 3 + arr[2] = 1
                    Search for the value of 'sum' in the map.                       ___Key_____Value__
                    Since, there's a match for '1', now we will                     |_______||_______|
                    calibrate the length of the subarray.                           |_______||_______|
                                                                                    |_______||_______|
                    (i, x) = (0, 0) // The subarray indices with sum = 1.           |___1___||___3___|
                    (i, j) = (0, 2) // The subarray with current sum = 1.           |___0___||___1___|

                    So, the subarray with the sum as 0 will be in b/n indices (x+1, j) = (1, 2).
                    Hence, we will also update the length of the `maxLen` variable.
                    maxLen = max(0, (2-1+1)) = 2

        Iteration-4: i = 3, sum = 1 + arr[3] = 5
                    Search for the value of 'sum' in the map.                       ___Key_____Value__
                    Since, there's no match for '4', We will                        |_______||_______|
                    store it in the map along with it's index.                      |_______||_______|
                                                                                    |___3___||___5___|
                                                                                    |___1___||___3___|
                                                                                    |___0___||___1___|

        Iteration-5: i = 4, sum = 5 + arr[2] = 1
                    Search for the value of 'sum' in the map.                       ___Key_____Value__
                    Since, there's a match for '1', now we will                     |_______||_______|
                    calibrate the length of the subarray.                           |_______||_______|
                                                                                    |___3___||___5___|
                    (i, x) = (0, 0) // The subarray indices with sum = 1.           |___1___||___3___|
                    (i, j) = (0, 4) // The subarray with current sum = 1.           |___0___||___1___|

                    So, the subarray with the sum as 0 will be in b/n indices (x+1, j) = (1, 4).
                    Hence, we will also update the length of the `maxLen` variable.
                    maxLen = max(2, (4-1+1)) = 4
    
    Since, all the iterations of the input array are exhausted, we will return the value of `maxLen`, i.e; 4.


Complexity Analysis:
    1. Time Complexity: O(N), as we are traversing the array only once
    2. Space Complexity: O(N), in the worst case we would have to insert prefix sum of all the array elements into our map.
*/


#include<bits/stdc++.h>
using namespace std;


int findSubArraySumZero(vector<int>& A, int n)
{
    // Your code here
    unordered_map<int,int> uMap;
    int maxLen = 0;
    int sum = 0; 

    for(int i = 0; i < n; i++)
    {
        sum += A[i];
        if(sum == 0)
        {
            maxLen = i + 1;
        }
        else
        {
            /* If current sum is present in the map */
            if(uMap.find(sum) != uMap.end())
            {
                /* uMap[sum] will give us the index of the array where the sum is equal to current sum. */
                /* We are not doing (i - uMap[sum] + 1) to find the length of the sub-array.
                Because we are inserting the indices in 0th-indexing order in the map.*/
                maxLen = max(maxLen, i - uMap[sum]);
            }
            else
            {
                uMap[sum] = i;
            }
        }
    }

    return maxLen;
}


int main()
{
    vector<int> Arr = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    int N = Arr.size();
    int result = findSubArraySumZero(Arr, N);

    cout << "The maxLenmum subarray length whose sum is zero is: " << result;
    return 0;
}
