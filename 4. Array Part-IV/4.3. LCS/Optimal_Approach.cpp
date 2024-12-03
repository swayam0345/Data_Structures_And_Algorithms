/*
Intuition:
    ● We will adopt a similar approach to the brute-force method but with optimizations in the search process.
    ● Instead of searching sequences for every array element as in the brute-force approach, we will focus solely
      on finding sequences only for those numbers that can be the starting numbers of the sequences.
    ● This targeted approach narrows down our search and improves efficiency.
    ● This will also reduce the overhead of sorting the array(like in the better approach), and keep the array intact.
    ● We will do this with the help of the Set (unordered) data structure.

How to identify if a number can be the starting number for a sequence:
    ● First, we will put all the array elements into the set data structure.
    ● If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, `x` in the set,
      we will check if x-1 exists inside the set.
        (a) If x-1 exists: This means `x` cannot be a starting number and we will move on to the next element in the set.
        (b) If x-1 does not exist: This means `x` is a starting number of a sequence. So, for number, x, we will start
            finding the consecutive elements.

How to search for consecutive elements for a number, x:
    ● Instead of using linear search, we will use the set data structure itself to search for the elements x+1, x+2, x+3, and so on.
    ● Thus, using this method we can narrow down the search and optimize the approach.


Approach:
    1. We will declare 2 variables;
        (a) ‘count’ → (to store the length of the current sequence), 
        (b) ‘lcs’ → (to store the maximum length).
    2. First, we will put all the array elements into the unordered set data structure.
    3. For every element, `x` that can be a starting number (i.e. x-1 does not exist in the set) we will do the following;
        (a) We will set the length of the current sequence(count) to 1.
        (b) Then, again using the set, we will search for the consecutive elements such as x+1, x+2, and so on, and find
            the maximum possible length of the current sequence. This length will be stored in the variable ‘count’.
        (c) After that, we will compare ‘count’ and ‘lcs’ and update the variable ‘lcs’ with the maximum value
            (i.e. lcs = max(count, lcs)).
    4. Finally, we will have the answer i.e. ‘lcs’.


Dry Run:
    Let take the below as inputs to our program.
                ___________________________________________ set Insertion
    array --->  |_102_|_4_|_100_|_1_|_101_|_3_|_2_|_1_|_1_| -------------
                                                                        |
    Step-1: Insert the input array into an unordered set                |
                        _________                                       |
                        |__102__|   ◄------------------------------------
                        |___4___|
                        |__100__|
                        |___1___|
                        |__101__|
                        |___3___|
                        |___2___|
                        |___1___|
                        |___1___|

    Step-2: Iterate throught the set.
            ➤ set[0] = 102; So we will search for `101` in the set. Since, 101 is present in the set hence 102 can't be the initiation.
            ➤ set[1] = 4; So we will search for `3` in the set. Since, 3 is present in the set hence 4 can't be the initiation.
            ➤ set[2] = 100; So we will search for `99` in the set. Since, 99 isn't present in the set hence 100 can be an initiation.
                ● Now we will search for set[i]+1, set[i]+2, ... until there's no set[i]+n present in the set.
                    100+1 = 101 is present, increment count
                    101+1 = 102 is present, increment count
                    102+1 = 103 is not present, break loop
                ● And everytime we find an consecutive element we will increment the value of count.
                    So, our final count will be 3.
                ● Once all the consecutive elements are found we will store max(count, lcs).
                    lcs = max(3, 1) = 3
                
            ➤ set[3] = 1; So we will search for `0` in the set. Since, 0 isn't present in the set hence 1 can be an initiation.
                ● Now we will search for set[i]+1, set[i]+2, ... until there's no set[i]+n present in the set.
                    1+1 = 2 is present, increment count
                    2+1 = 3 is present, increment count
                    3+1 = 4 is present, increment count
                    4+1 = 5 is not present, break loop
                ● And everytime we find an consecutive element we will increment the value of count.
                    So, out final count will be 4.
                ● Once all the consecutive elements are found we will store max(count, lcs).
                    lcs = max(4, 3) = 4

            ➤ set[4] = 101; So we will search for `100` in the set. Since, 100 is present in the set hence 101 can't be the initiation.
            ➤ set[5] = 3; So we will search for `2` in the set. Since, 2 is present in the set hence 3 can't be the initiation.
            ➤ set[6] = 2; So we will search for `1` in the set. Since, 1 is present in the set hence 2 can't be the initiation.
            ➤ set[7] = 1; We have already iterated the sceario for `1`, this will also follow the same.
            ➤ set[8] = 1; We have already iterated the sceario for `1`, this will also follow the same.

    Step-3: return lcs.
            The final value of lcs in our example was 4.


Complexity Analysis:
    1. Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
        Reason: O(N) for putting all the elements into the set data structure.
                After that for every starting element, we are finding the consecutive elements.
                Though we are using nested loops, the set will be traversed at most twice in the worst case.
                So, the time complexity is O(2*N) instead of O(N^2).

    2. Space Complexity: O(N), as we are using the set data structure to solve this problem.

    Note:
        ● The time complexity is computed assuming that we are using "unordered set" and it is taking O(1) for the set operations.
        ● If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be 
        approximately O(N^2). 
        ● And if we use the set instead of unordered set, the time complexity for the set operations will be O(logN) and the total
        time complexity will be O(NlogN).

*/


#include <bits/stdc++.h>
using namespace std;


int longestSuccessiveElements(vector<int>& nums)
{
    int n = nums.size();
    int lcs = 1;
    unordered_set<int> st;

    /* Boundary case with empty input array */
    if (n == 0)
        return 0;

    //put all the array elements into set
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    //Find the Longest Consecutive Sequence
    for (auto it : st)
    {
        //if 'it' can be an initiation point
        if (st.find(it - 1) == st.end())
        {
            //find consecutive numbers
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                count = count + 1;
            }
            lcs = max(lcs, count);
        }
    }

    return lcs;
}


int main()
{
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    int result = longestSuccessiveElements(arr);
    cout << "The longest consecutive sequence is " << result << endl;

    return 0;
}