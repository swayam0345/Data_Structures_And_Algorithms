/*
Intuition:
    ● Here, in this approach, we are going to generate all possible subarrays to solve this problem.
    ● We will check the XOR of every possible subarray and count how many of them are equal to k.
    ● To get every possible subarray sum, we will be using three nested loops.
        ➤ The first two loops(say i and j) will iterate over every possible starting index and ending index of a subarray.
           Basically, in each iteration, the subarray range will be from index i to index j.
        ➤ Using another loop we will get the XOR of the elements of the subarray [i…..j].
    ● Among all values of the XOR calculated, we will only consider those that are equal to `K`.

How to generate all possible subarrays?
    ● We will select all possible starting indices(say i) and all possible ending indices(say j) to generate all possible subarrays.
    ● The possible starting indices i.e. i can vary from index 0 to index n-1(i.e. The last index).
    ● For every index i, the possible ending index j can vary from i to n-1. So, the nested loops to generate all possible subarrays
      will be like the following:
        for(i = 0; i < n; i++)  // Starting index
        {
            for(j = i; j < n; j++)  // Ending index
            {
                // sub-array = arr[i...j]
            }
        }

Approach:
    1. Generate Subarrays
        ● First, we will run a loop(say i) that will select every possible starting index of the subarray.
          The possible starting indices can vary from index 0 to index n-1(n = size of the array).
        ● Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray.
          For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
    2. Calculate XOR of the subarray: After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]),
       we will run another loop to calculate the XOR of all the elements(of that particular subarray).
    3. Check the XOR and modify the count: If the XOR is equal to k, we will increase the count by 1.


Complexity Analysis:
    1. Time Complexity: O(N^3) approx., where N = size of the array.
        Reason: We are using three nested loops, each running approximately `N` times.
    2. Space Complexity: O(1) as we are not using any extra space.

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
        for (int j = i; j < n; j++)
        {
            //step 2: calculate XOR of all elements
            int xorr = 0;
            for (int K = i; K <= j; K++)
            {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count
            if (xorr == k)
                cnt++;
        }
    }

    return cnt;
}


int main()
{
    vector<int> A = {4, 2, 2, 6, 4};
    int K = 6;
    int ans = subarraysWithXorK(A, K);
    cout << "The number of subarrays with XOR K is: " << ans << "\n";

    return 0;
}