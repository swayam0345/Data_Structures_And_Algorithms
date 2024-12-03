/*
Intuition:
    ● A straightforward but basic solution is to examine consecutive sequences for each element in the given array.
    ● For every element x, we will try to find the consecutive elements, x+1, x+2, x+3, and so on using the linear
      search algorithm.
    ● Thus, we will check the length of the longest consecutive subsequence we can build for every element x.
    ● Among all the lengths we will consider the maximum one.


Approach:
    1. To begin, we will utilize a loop to iterate through each element one by one.
    2. Next, for every element x, we will try to find the consecutive elements like x+1, x+2, x+3, and so on
       using the linear search algorithm in the given array.
    3. Within a loop, our objective is to locate the next consecutive element x+1.
    4. If this element is found, we increment x by 1 and continue the search for x+2.
    5. Furthermore, we increment the length of the current sequence (cnt) by 1.
    6. This process repeats until step 4 occurs.
        ● If a specific consecutive element, for example, x+i, is not found, we will halt the search for subsequent consecutive
          elements such as x+i+1, x+i+2, and so on. Instead, we will take into account the length of the current sequence (cnt).
        ● Among all the lengths we get for all the given array elements, the maximum one will be the answer.


Complexity Analysis:
    1. Time Complexity: O(N^2), N = size of the given array.
        Reason: We are using nested loops each running for approximately N times.
    2. Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/


#include <bits/stdc++.h>
using namespace std;


bool linearSearch(vector<int>& a, int num)
{
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            return true;
    }

    return false;
}

int longestSuccessiveElements(vector<int>& a)
{
    int n = a.size(); //size of array
    int longest = 1;
    //pick an element and search for its consecutive numbers
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers using linear search
        while (linearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }

    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";

    return 0;
}