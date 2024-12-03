/*
Intuition:
    ● In this approach, we are going to use the concept of the prefix XOR to solve this problem.
    ● Here, the prefix XOR of a subarray ending at index `i`, simply means the XOR of all the elements of that subarray.

    ➤ Observation:
        ● Assume, the prefix XOR of a subarray ending at index `i` is xr.
        ● In that subarray, we will search for another subarray ending at index `i`, whose XOR is equal to k.
        ● Here, we need to observe that if there exists another subarray ending at index `i`, with XOR `k`,
        then the prefix XOR of the rest of the subarray will be "(xr) ⊕ k".

                        XOR = XR
                       _____↓______                             In this scenario we can say that,
                    __|___________|______________               x ^ k = XR
                    |_4_|_2_|_2_|_6_|_4_|_3_|_1_|               XOR with `k` on both sides.
                      |  |_____|                                ⇒ (x ^ k) ^ k = (XR) ^ k
                      ▼  XOR = k                                ⇒ x = (XR) ^ k
                  XOR = x

    ● Using this formula we can calculate the XOR of a sub-array.
         ________________________________________________________________________________________________________________
        | x = (XR) ^ k                                                                                                   |
        | XOR of a sub-array = (prefix XOR till index `i`) ⊕ (sub-array with XOR `k`, that we will search in the map)   |
        |________________________________________________________________________________________________________________|

    ● Now, for a subarray ending at index `i` with the prefix XOR `xr`, if we remove the part with the prefix XOR (xr^k),
      we will be left with the part whose XOR is equal to `k`.
    ● Now, there may exist multiple sub-arrays with the prefix XOR xr^k. So, the number of subarrays with XOR `k` that we
      can generate from the entire subarray ending at index `i`, is exactly equal to the number of sub-arrays with the prefix
      XOR xr^k, present in that subarray.
    ● So, for a subarray ending at index `i`, instead of counting the subarrays with XOR `k`, we can count the subarrays with
      the prefix XOR `xr^k` present in it.
    ● That is why, instead of searching the subarrays with XOR `k`, we will keep the occurrence of the prefix XOR of the subarrays
      using a map data structure. 
    ● In the map, we will store every prefix XOR calculated, with its occurrence in a <XOR, Count> pair. Now, at index `i`, we just
      need to check the map data structure to get the number of times that the subarrays with the prefix XOR `xr^k` occured. Then we
      will simply add that number to our count.
    ● We will apply the above process for all possible indices of the given array. The possible values of the index `i` can be from
      0 to n-1(where n = size of the array).


Dry Run:
  Let take the below as inputs to our program.
                  _____________________
        array[] = |_4_|_2_|_2_|_6_|_4_|     and    K = 6

      
    Iteration-0: First we need to initialize our map with (0, 1).
                ____XR_____Count__
                |_______||_______|
                |_______||_______|
                |_______||_______|
                |_______||_______|
                |___0___||___1___|

    Iteration-1: i = 0, XR = 4 ^ 0 = 4                                        ___Key_____Value__
                x = XR ^ k = 4 ^ 6 = 2                                        |_______||_______|
                Since, there's no match for '2', We will                      |_______||_______|
                store 4(i.e, XR) in the map with count 1.                     |_______||_______|
                cnt = 0 + map[4] = 0 + 0 = 0                                  |___4___||___1___|
                                                                              |___0___||___1___|

    Iteration-2: i = 1, XR = 4 ^ 2 = 6                                        ___Key_____Value__
                x = XR ^ k = 6 ^ 6 = 0                                        |_______||_______|
                Since, there's a match for '0', We will                       |_______||_______|
                increment the count of our result.                            |___6___||___1___|
                And then we will store 6(i.e, XR) with count 1.               |___4___||___1___|
                cnt = 0 + map[0] = 0 + 1 = 1                                  |___0___||___1___|

    Iteration-3: i = 2, XR = 6 ^ 2 = 4                                        ___Key_____Value__
                x = XR ^ k = 4 ^ 6 = 2                                        |_______||_______|
                Since, there's no match for '2', We will                      |_______||_______|
                We will only increment map entry of 4(i.e, XR).               |___6___||___1___|
                cnt = 1 + map[2] = 1 + 0 = 1                                  |___4___||___2___|
                                                                              |___0___||___1___|

    Iteration-4: i = 3, XR = 4 ^ 6 = 2                                        ___Key_____Value__
                x = XR ^ k = 2 ^ 6 = 4                                        |_______||_______|
                Since, there's a match for '4', We will                       |___2___||___1___|
                increment the count of our result.                            |___6___||___1___|
                And then we will store 2(i.e, XR) with count 1.               |___4___||___2___|
                cnt = 1 + map[4] = 1 + 2 = 3                                  |___0___||___1___|

    Iteration-5: i = 4, XR = 2 ^ 4 = 6                                        ___Key_____Value__
                x = XR ^ k = 6 ^ 6 = 0                                        |_______||_______|
                Since, there's a match for '0', We will                       |___2___||___1___|
                increment the count of our result.                            |___6___||___2___|
                And then increment map entry of 6(i.e, XR).                   |___4___||___2___|
                cnt = 3 + map[0] = 3 + 1 = 4                                  |___0___||___1___|

  So, the final output will be `4`. The sub-arrays with XOR as `6` are: { [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6] }.


Approach:
    1. First, we will declare a map to store the prefix XORs and their counts.
    2. Then, we will set the value of 0 as 1 on the map.
    3. Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
    4. For each index i, we will do the following:
        ● We will XOR the current element i.e. arr[i] to the existing prefix XOR.
        ● Then we will calculate the prefix XOR i.e. xr^k, for which we need the occurrence.
        ● We will add the occurrence of the prefix XOR xr^k i.e. mpp[xr^k] to our answer.
        ● Then we will store the current prefix XOR, xr in the map increasing its occurrence by 1.


Why do we need to set the value of 0 beforehand?
    ● Let’s understand this using an example. Assume the given array is [3, 3, 1, 1, 1] and k is 3.
    ● Now, for index 0, we get the total prefix XOR as 3, and k is also 3.
    ● So, the prefix XOR xr^k will be = 3^3 = 0. Now, if the value is not previously set for the key 0 in the map,
      we will get the default value 0 and we will add 0 to our answer.
    ● This will mean that we have not found any subarray with XOR 3 till now. But this should not be the case as
      index 0 itself is a subarray with XOR k i.e. 3.
    ● So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.


Complexity Analysis:
  1. Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
    Reason: For example, if we are using an unordered map data structure the time complexity will be O(N) but if we are
            using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are
            using a loop to traverse the array. Point to remember for unordered map in the worst case, the searching time
            increases to O(N), and hence the overall time complexity increases to O(N^2). 

  2. Space Complexity: O(N), as we are using a map data structure.

*/


#include <bits/stdc++.h>
using namespace std;


int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size();   //size of the given array.
    int xr = 0;
    map<int, int> mpp;  //declaring the map.
    mpp[xr]++;          //setting the value of 0 with count 1 in the map.
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i
        xr = xr ^ a[i];

        //By formula: x = xr^k
        int x = xr ^ k;

        // add the occurrence of xr^k to the count
        cnt += mpp[x];

        // Insert and increment the count of the prefix xor till index i into the map
        mpp[xr]++;
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
