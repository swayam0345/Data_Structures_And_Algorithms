/*
Youtube Reference: https://www.youtube.com/watch?v=tp8JIuCXBaU&t=1s

Algorithm/Intuition:
    This problem is a variation of the popular Dutch National flag algorithm. 

    This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules. The rules are the following:
    1. arr[0….low-1] contains 0. [Extreme left part]
    2. arr[low….mid-1] contains 1.
    3. arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
    
    The middle part i.e. arr[mid….high] is the unsorted segment. So, hypothetically the array with different markers will look like the following:

    index 0 to                           index mid
    (low-1)                              to high
    extreme left                         unsorted
    |           |                       |         |
    ▼           ▼                       ▼         ▼
    000.........000 111...........111 021.........1 222..........222
                    ▲               ▲               ▲               ▲
                    |               |               |               |
                    Index low to (mid-1)            Index (high+1) to
                                                    (n-1) extreme right
    
    In our case, we can assume that the entire given array is unsorted and so we will place the pointers accordingly.
    For example, if the given array is: [2,0,2,1,1,0], the array with the 3 pointers will look like the following:
    
        low
         |
        _▼_______________________
        |_2_|_0_|_2_|_1_|_1_|_0_|
         ▲                    ▲
         |                    |
        mid                  high
    
    Here, as the entire array is unsorted, we have placed the 'mid' pointer in the first index and the 'high' pointer in the last index.
    The 'low' is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’
    pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.
    

Approach:
    1. First, we will run a loop that will continue until mid <= high.
    2. There can be three different values of mid pointer i.e. arr[mid]
        (a) If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid.
            Now the subarray from index 0 to (low-1) only contains 0.
        (b) If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will
            point to 1 as it should according to the rules.
        (c) If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray
            from index high+1 to (n-1) only contains 2.

        In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to
        high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.
    3. Finally, our array should be sorted.

Complexity Analysis:
    1. Time Complexity
        O(N), where N = size of the given array.
        Reason: We are using a single loop that can run at most N times.

    2. Space Complexity
        O(1) as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will sort the array using a variation of the
 *        Dutch National Flag Algorithm. 
 * 
 * @param arr The input array
 * @param n Size of the input array
 */
void sortArray(vector<int>& arr, int n)
{
    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    int n = size(arr);

    sortArray(arr, n);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}