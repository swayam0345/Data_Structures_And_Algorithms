/*
Intuition:
    ● We will use the same sliding window approach to select the sub-string. But In this approach we will try to
      reduce the iterations taken by the `left` pointer to delete the duplicate character.
    ● Instead of incrementing left one by one if we know the last position of the duplicate element, then we can
      directly jump left pointer to that particular index.
    ● In order store the index of the character, we will take a map instead of a unordered_set.
    ● When we find a duplicate element in our sub-string we will look for that character in the map and update
      `left` with (index of duplicate character + 1).
    ● But here we need to note that, we will update the value of `left` pointer only if it is less than or equal to
      the index of the duplicate element.
        if((mpp.find(mpp[duplicate]) != mpp.end()) && (left <= mpp[duplicate])) {
            left = mpp[duplicate]+1
            mpp[duplicate] = current_index(i.e; duplicate);
        }


Approach:
    1. We will take a map ‘subStr’ to store the characters and their index.
    2. We will initialize two variables ‘left’ & ‘right’ with 0 and a variable ‘maxSubStrLen’ with INT_MIN.
    3. Now we will iterate the input array with the `right` pointer and for iteration we will do the following;
        ● If the current element (str[right]) is present in the map, this means it's a duplicate element of the
          current sub-string. We will update left with (str[right] + 1), only if (left <= str[right]).
        ● Then we will store or update the element (str[right]) in the map, and calculate the max string length
          and store it in `maxSubStrLen`.
    4. After the complete input array is traversed we will have our result in `maxSubStrLen`.


Dry Run:
                        _____________________________________
    Input String --->   |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|

    Iteration-1: left = 0, right = 0, maxStrLen = INT_MIN                                       |_______|_______|
                str[right] = c, and it's not present in the map.                                |_______|_______|
                So, we will insert `c` to the map with it's index `0` and calculate the         |_______|_______|
                maxStrLen = max(maxStrLen, right - left + 1) = max(INT_MIN, 0-0+1) = 1          |_______|_______|
                                                                                                |___c___|___0___|
                left=0
                __↓__________________________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                  ↑
                right=0               

    Iteration-2: left = 0, right = 1, maxStrLen = 1                                             |_______|_______|
                str[right] = a, and it's not present in the map.                                |_______|_______|
                So, we will insert `a` to the map with it's index `1` and calculate the         |_______|_______|
                maxStrLen = max(maxStrLen, right - left + 1) = max(1, 1-0+1) = 1                |___a___|___1___|
                                                                                                |___c___|___0___|
                left=0
                __↓__________________________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                      ↑
                    right=1

    Iteration-3: left = 0, right = 2, maxStrLen = 2                                             |_______|_______|
                str[right] = d, and it's not present in the map.                                |_______|_______|
                So, we will insert `d` to the map with it's index `2` and calculate the         |___d___|___2___|
                maxStrLen = max(maxStrLen, right - left + 1) = max(2, 2-0+1) = 3                |___a___|___1___|
                                                                                                |___c___|___0___|
                left=0
                __↓__________________________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                          ↑
                        right=2

    Iteration-4: left = 0, right = 3, maxStrLen = 3                                             |_______|_______|
                str[right] = b, and it's not present in the map.                                |___b___|___3___|
                So, we will insert `b` to the map with it's index `3` and calculate the         |___d___|___2___|
                maxStrLen = max(maxStrLen, right - left + 1) = max(3, 3-0+1) = 4                |___a___|___1___|
                                                                                                |___c___|___0___|
                left=0
                __↓__________________________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                              ↑
                            right=3

    Iteration-5: left = 0, right = 4, maxStrLen = 4                                             |___z___|___4___|
                str[right] = z, and it's not present in the map.                                |___b___|___3___|
                So, we will insert `z` to the map with it's index `4` and calculate the         |___d___|___2___|
                maxStrLen = max(maxStrLen, right - left + 1) = max(4, 4-0+1) = 5                |___a___|___1___|
                                                                                                |___c___|___0___|
                left=0
                __↓__________________________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                                  ↑
                                right=4

    Iteration-6: left = 0, right = 5, maxStrLen = 5                                             |___z___|___4___|
                str[right] = a, and it is present in the map.                                   |___b___|___3___|
                So, we will update the value of left as (left=0 <= mpp[right]=1)                |___d___|___2___|
                left = mpp[right]+1 = 1+1 = 2, and then update the value of mpp[right]=5        |___a___|__𝟷̶_5__|
                and now calculate the maxStrLen;                                                |___c___|___0___|
                maxStrLen = max(maxStrLen, right - left + 1) = max(5, 5-2+1) = 5

                𝗅̶𝖾̶𝖿̶𝗍̶________left=2
                __↓_______↓__________________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                                      ↑
                                    right=5

    Iteration-7: left = 2, right = 6, maxStrLen = 5                                             |___z___|___4___|
                str[right] = b, and it is present in the map.                                   |___b___|__𝟹̶_6__|
                So, we will update the value of left as (left=2 <= mpp[right]=3)                |___d___|___2___|
                left = mpp[right]+1 = 3+1 = 4, and then update the value of mpp[right]=6        |___a___|___5___|
                and now calculate the maxStrLen;                                                |___c___|___0___|
                maxStrLen = max(maxStrLen, right - left + 1) = max(5, 6-4+1) = 5

                        𝗅̶𝖾̶𝖿̶𝗍̶________left=4
                __________↓_______↓__________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                                          ↑
                                        right=6

    Iteration-8: left = 4, right = 7, maxStrLen = 5                                             |___z___|___4___|
                str[right] = c, and it is present in the map.                                   |___b___|___6___|
                But, we will not update the value of left as (left=4 !<= mpp[right]=0)          |___d___|___2___|
                So, left = 4, and just update the value of mpp[right]=7                         |___a___|___5___|
                and now calculate the maxStrLen;                                                |___c___|__𝟢̶_7__|
                maxStrLen = max(maxStrLen, right - left + 1) = max(5, 7-4+1) = 5

                                left=4
                __________________↓__________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                                              ↑
                                            right=7

    Iteration-9: left = 4, right = 8, maxStrLen = 5                                             |___z___|___4___|
                str[right] = d, and it is present in the map.                                   |___b___|___6___|
                But, we will not update the value of left as (left=4 !<= mpp[right]=2)          |___d___|__𝟤̶_8__|
                So, left = 4, and just update the value of mpp[right]=8                         |___a___|___5___|
                and now calculate the maxStrLen;                                                |___c___|___7___|
                maxStrLen = max(maxStrLen, right - left + 1) = max(5, 8-4+1) = 5

                                left=4
                __________________↓__________________
                |_c_|_a_|_d_|_b_|_z_|_a_|_b_|_c_|_d_|
                                                  ↑
                                                right=8

    ● So, the longest sub string without any repetition is, our final result in maxStrLen = 5.


Complexity Analysis:
    1. Time Complexity: O(N), we are not using a loop to iterate the `left` pointer.
    2. Space Complexity: O(N), where `N` represents the size of HashSet where we are storing our elements.

*/


#include <bits/stdc++.h>
using namespace std;


int lengthofLongestSubstring(string s)
{
    map<char, int> mpp;
    int left = 0;
    int n = s.size();
    int maxSubStrLen = 0;

    for(int right = 0; right < n; right++)      // outer loop for traversing the string
    {
        // Update left if duplicate element is found.
        if( (mpp.find(s[right]) != mpp.end()) && (left <= mpp[s[right]]) )
            left = mpp[s[right]] + 1;

        mpp[s[right]] = right;      // Insert/store the element into the map.

        maxSubStrLen = max(maxSubStrLen, (right - left + 1));   // Calculate max sub-string length for the current iteration.
    }

    return maxSubStrLen;
}

int main()
{
    string str = "cadbzabcd";
    int result = lengthofLongestSubstring(str);
    cout << "The length of the longest substring without repeating characters is " << result;

    return 0;
}
