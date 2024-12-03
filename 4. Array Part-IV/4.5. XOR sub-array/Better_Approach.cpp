/*
Intuition:
    ● If we carefully observe, we can notice that to get the XOR of the current subarray we just need to XOR the current element
      (i.e. arr[j]) to the XOR of the previous subarray i.e. arr[i….j-1].
    ● Let us understand the above point comprehensibly.
        Assume previous subarray = arr[i ... (j-1)]
        current subarray = arr[i ... j]
        XOR of arr[i….j] = (XOR of arr[i….j-1]) ⊕ arr[j]
        XOR of arr[i….j] = (XOR of arr[i….j-1]) ^ arr[j]    //Programatically 

    ● This is how we can remove the third loop and while moving `j` pointer, we can calculate the XOR.


Approach:
    1. Generate Subarrays
        ● First, we will run a loop(say i) that will select every possible starting index of the subarray.
          The possible starting indices can vary from index 0 to index n-1(n = array size).
        ● Inside the loop, we will run another loop(say j) that will signify the ending index as well as the
          current element of the subarray. For every subarray starting from the index i, the possible ending
          index can vary from index i to n-1(n = size of the array).

    2. Calculate XOR of the subarray
        ● Inside loop `j`, we will XOR the current element to the XOR of the previous subarray,
          i.e. xorr = XOR(a[i….j-1]) ^ arr[j].

    4. Check the XOR and modify the count
        ● After calculating the XOR, we will check if the sum is equal to the given k. If it is,
          we will increase the value of the count.


Complexity Analysis:
    1. Time Complexity: O(N^2), where N = size of the array.
        Reason: We are using two nested loops here. As each of them is running for N times,
                the time complexity will be approximately O(N^2).

    2. Space Complexity: O(1), as we are not using any extra space.
*/


#include <bits/stdc++.h>
using namespace std;


int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size();   //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays
    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for (int j = i; j < n; j++)
        {
            //step 2:calculate XOR of all elements
            xorr = xorr ^ a[j];

            // step 3:check XOR and count
            if (xorr == k)
                cnt++;
        }
    }

    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: " << ans << "\n";

    return 0;
}