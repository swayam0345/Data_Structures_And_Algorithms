/*
Intuition:
    ● We will use the sliding window approach to select the sub-string and update the window when we meet a condition.
    ● We will have two pointers ‘left’ and ‘right’ to select our sub-string (sliding window). Pointer ‘left’ is used for
      maintaining the starting point of the substring while ‘right’ will maintain the endpoint of the substring.
    ● ‘right’ pointer will move forward and check for the duplicate occurrence of the current element if found then the ‘left’
      pointer will be shifted ahead so as to delete the duplicate elements.
    ● We will use an ‘unordered_set’ to store and delete the characters of the input strings.


Approach:
    1. Take two variables ‘left’ & ‘right’, and initialize them with the start of the string, i.e 0.
    2. We will initialize a variable ‘maxSubStrLen’ with INT_MIN to store the max length of the longest sub-string here.
    2. Now we will move the `right` pointer using a for loop until the end of the string.
    3. For every character (index `right`) we will do the following;
        ● If the character (str[right]) is present in the set, this means it's a duplicate element of the current sub-string.
          Hence, we will delete the entry of str[left] from the set & increment `left`, until the duplicate element is removed.
            while (left < right && set.find(str[right]) != set.end()) {
                set.erase(str[left]);
                left++;
            }
        ● After this we will store the character (str[right]) in the map and calculate the max string length
          and store it in `maxSubStrLen`.
    4. After the complete input array is traversed we will have our result in `maxSubStrLen`.
 

Dry Run:
                          _________________________________________
    Input String --->     |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|

    Iteration-1: left = 0, right = 0, maxStrLen = INT_MIN                                       |_______|
                str[right] = a, and it's not present in the set.                                |_______|
                So, we will insert `a` to the set and calculate the                             |_______|
                maxStrLen = max(maxStrLen, right - left + 1) = max(INT_MIN, 0-0+1) = 1          |_______|
                                                                                                |___a___|
               left=0
                __↓______________________________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                  ↑
               right=0

    Iteration-2: left = 0, right = 1, maxStrLen = 1                                             |_______|
                str[right] = b, and it's not present in the set.                                |_______|
                So, we will insert `b` to the set and calculate the                             |_______|
                maxStrLen = max(1, right - left + 1) = max(1, 1-0+1) = 2                        |___b___|
                                                                                                |___a___|
               left=0
                __↓______________________________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                      ↑
                    right=1

    Iteration-3: left = 0, right = 2, maxStrLen = 2                                             |_______|
                str[right] = c, and it's not present in the set.                                |_______|
                So, we will insert `c` to the set and calculate the                             |___c___|
                maxStrLen = max(2, right - left + 1) = max(2, 2-0+1) = 3                        |___b___|
                                                                                                |___a___|
               left=0
                __↓______________________________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                          ↑
                        right=2

    Iteration-4: left = 0, right = 3, maxStrLen = 3                                             |_______|
                str[right] = a, and it's present in the set.                                    |___a___|
                So, we will delete the str[left] from the set and increment left                |___c___|
                until `a` is removed from the set.                                              |___b___|
                remove str[left] = a from set, left = left++ = 1                                |___𝖺̷___|
                insert str[right] = a into the set and calculate the maxStrLen.
                maxStrLen = max(3, right - left + 1) = max(3, 3-1+1) = 3

                𝗅̶𝖾̶𝖿̶𝗍̶____left=1
                __↓___↓__________________________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                              ↑
                            right

    Iteration-5: left = 1, right = 4, maxStrLen = 3                                             |_______|
                str[right] = a, and it's present in the set.                                    |___a___|
                So, we will delete the str[left] from the set and increment left                |___𝖺̷___|
                until `a` is removed from the set.                                              |___𝖼̷___|
                remove str[left] = b from set, left ++ = 2, a is still present. So,             |___𝖻̷___|
                remove str[left] = c from set, left ++ = 3, a is still present. So,
                remove str[left] = a from set, a is removed. left = left ++ = 4
                insert str[right] = a into the set and calculate the maxStrLen.
                maxStrLen = max(3, right - left + 1) = max(3, 4-4+1) = 3

                    𝗅̶𝖾̶𝖿̶𝗍̶____________left=4
                ______↓___________↓______________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                                  ↑
                                right=4

    Iteration-6: left = 4, right = 5, maxStrLen = 3                                             |_______|
                str[right] = b, and it's not present in the set.                                |_______|
                So, we will insert `b` to the set and calculate the                             |_______|
                maxStrLen = max(3, right - left + 1) = max(3, 5-4+1) = 3                        |___b___|
                                                                                                |___a___|
                                left=4
                __________________↓______________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                                      ↑
                                    right=5

    Iteration-7: left = 4, right = 6, maxStrLen = 3                                             |_______|
                str[right] = c, and it's not present in the set.                                |_______|
                So, we will insert `c` to the set and calculate the                             |___c___|
                maxStrLen = max(3, right - left + 1) = max(3, 6-4+1) = 3                        |___b___|
                                                                                                |___a___|
                                left=4
                __________________↓______________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                                          ↑
                                        right=6

    Iteration-8: left = 4, right = 7, maxStrLen = 3                                             |_______|
                str[right] = d, and it's not present in the set.                                |___d___|
                So, we will insert `d` to the set and calculate the                             |___c___|
                maxStrLen = max(3, right - left + 1) = max(3, 7-4+1) = 4                        |___b___|
                                                                                                |___a___|
                                left=4
                __________________↓______________________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                                              ↑
                                            right=7

    Iteration-9: left = 4, right = 8, maxStrLen = 4                                             |___b___|
                str[right] = b, and it's present in the set.                                    |___d___|
                So, we will delete the str[left] from the set and increment left                |___c___|
                until `b` is removed from the set.                                              |___𝖻̷___|
                remove str[left] = a from set, left ++ = 5, b is still present. So,             |___𝖺̷___|
                remove str[left] = b from set, `b` is removed. left = left ++ = 6
                insert str[right] = b into the set and calculate the maxStrLen.
                maxStrLen = max(3, right - left + 1) = max(4, 8-6+1) = 4

                                𝗅̶𝖾̶𝖿̶𝗍̶________left=6
                __________________↓_______↓______________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                                                  ↑
                                                right=8

    Iteration-10: left = 6, right = 9, maxStrLen = 4                                            |_______|
                str[right] = a, and it's not present in the set.                                |___a___|
                So, we will insert `a` to the set and calculate the                             |___b___|
                maxStrLen = max(4, right - left + 1) = max(4, 9-6+1) = 4                        |___d___|
                                                                                                |___c___|
                                        left=6
                __________________________↓______________
                |_a_|_b_|_c_|_a_|_a_|_b_|_c_|_d_|_b_|_a_|
                                                      ↑
                                                    right=9

    ● So, the longest sub string without any repetition is, our final result in maxStrLen = 4.


Complexity Analysis:
    1. Time Complexity: O(2*N), because sometimes left and right both have to travel the complete array.
                        Ex; "abcdefghzz", here when right pointer reaches to 9 (2nd `z') left will have to move 9 (N) steps to
                            1st `z` and delete it. So, here right pointer takes O(N) and left pointer takes O(N), i.e; O(2*N).

    2. Space Complexity: O(N), where `N` is the size of external HashSet taken for storing the elements.

*/


#include <bits/stdc++.h>
using namespace std;


int longestSubStringNoRepeat(string str)
{
    if (str.size() == 0)
        return 0;

    unordered_set<int> set;
    int maxSubStrLen = INT_MIN;
    int left = 0;

    for (int right = 0; right < str.length(); right++)  // outer loop for traversing the string
    {
        if (set.find(str[right]) != set.end())          // if duplicate element is found
        {
            // loop for deletion of duplicate element from set and increment left.
            while (left < right && set.find(str[right]) != set.end())
            {
                set.erase(str[left]);
                left++;
            }
        }
        set.insert(str[right]);     // Insert character into the set.
        maxSubStrLen = max(maxSubStrLen, right - left + 1);     // Calculate max sub-string length for the current iteration.
    }

    return maxSubStrLen;
}

int main()
{
    string str = "abcaabcdba";
    cout << "The length of the longest substring without repeating characters is " << longestSubStringNoRepeat(str);

    return 0;
}
