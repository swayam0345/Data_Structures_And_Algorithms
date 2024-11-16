/*
Intuition:
    ● If the array contains the majority of elements, their occurrence must be greater than the floor(N/3).
      And for array of any size there will be only 2 such elements.
    ● Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array.
    ● So when we traverse through the array we try to keep track of the counts of elements and the elements themselves for
      which we are tracking the counts.
    ● After traversing the whole array, we will check the elements stored in the variables. Then we need to check if the stored
      elements are the majority elements or not by manually checking their counts.

Approach(Extended Boyer Moore’s Voting Algorithm):
    1. Initialize 4 variables:
        cnt1 & cnt2 –  for tracking the counts of elements
        el1 & el2 – for storing the majority of elements.
    2. Traverse through the given array:
        (a) If cnt1 is 0 and the current element is not el2 then store the current element of the array
            as el1 along with increasing the cnt1 value by 1.
        (b) If cnt2 is 0 and the current element is not el1 then store the current element of the array
            as el2 along with increasing the cnt2 value by 1.
        (c) If the current element and el1 are the same increase the cnt1 by 1.
        (d) If the current element and el2 are the same increase the cnt2 by 1.
        (e) Other than all the above cases: decrease cnt1 and cnt2 by 1.
    3. The integers present in el1 & el2 should be the result we are expecting. So, using another loop,
        we will manually check their counts if they are greater than the floor(N/3).

Edge Case: Why we are adding extra checks like el2 != v[i] and el1 != v[i] in the first if statements?
    Let’s understand it using an example:
    Assume the given array is: {2, 1, 1, 1, 3, 1, 4, 5, 6}. Now apply the algorithm without the checks;
    ● Iteration-1: el1 = 2, cnt1 = 1, el2 = INT_MIN, cnt2 = 0
        _____________________________________
        ┃ 2 ┃ 1 ┃ 1 ┃ 1 ┃ 3 ┃ 1 ┃ 4 ┃ 5 ┃ 6 ┃
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
    ● Iteration-2: el1 = 2, cnt1 = 1, el2 = 1, cnt2 = 1
        _____________________________________
        ┃ 2 ┃ 1 ┃ 1 ┃ 1 ┃ 3 ┃ 1 ┃ 4 ┃ 5 ┃ 6 ┃
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
    ● Iteration-3: el1 = 2, cnt1 = 1, el2 = 1, cnt2 = 2
        _____________________________________
        ┃ 2 ┃ 1 ┃ 1 ┃ 1 ┃ 3 ┃ 1 ┃ 4 ┃ 5 ┃ 6 ┃
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
    ● Iteration-4: el1 = 2, cnt1 = 0, el2 = 1, cnt2 = 3
        _____________________________________
        ┃ 2 ┃ 1 ┃ 1 ┃ 1 ┃ 3 ┃ 1 ┃ 4 ┃ 5 ┃ 6 ┃
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
    ● Iteration-5: el1 = 2, cnt1 = 0, el2 = 1, cnt2 = 2
        _____________________________________
        ┃ 2 ┃ 1 ┃ 1 ┃ 1 ┃ 3 ┃ 1 ┃ 4 ┃ 5 ┃ 6 ┃
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
    ● Iteration-6: el1 = 1, cnt1 = 1, el2 = 1, cnt2 = 3
        _____________________________________
        ┃ 2 ┃ 1 ┃ 1 ┃ 1 ┃ 3 ┃ 1 ┃ 4 ┃ 5 ┃ 6 ┃
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯

    We can clearly notice that in iteration-6, el1 and el2 both are set to 1 as cnt1 becomes 0 in iteration-5. But this is incorrect,
    as '1' should not have two different counts(1 & 3). So, to avoid this edge case, we are checking if the current element is already
    included in our elements, and if it is, we will not again include it in another variable.


Complexity Analysis:
    1. Time Complexity: O(N) + O(N) + O(1), where N = size of the given array.
        Reason: The first O(N) is to calculate the counts and find the expected majority elements.
                The second one is to check if the calculated elements are the majority ones or not.

    2. Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will return the elements that appear more than ⌊ n/3 ⌋ times.
 * 
 * @param v The input vector
 * @return vector<int> The output elements
 */
vector<int> majorityElement(vector<int> v)
{
    int n = v.size(); // size of the array

    int cnt1 = 0, cnt2 = 0;     // counts
    int el1 = INT_MIN;          // element 1
    int el2 = INT_MIN;          // element 2

    // Applying the Extended Boyer Moore's Voting Algorithm
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls;     // List of answers

    // Manually check if the stored elements in el1 and el2 are the majority elements
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el1)
            cnt1++;
        if (v[i] == el2)
            cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    // Sorting the answer array:
    sort(ls.begin(), ls.end());     //TC --> O(2*log2) ~ O(1);

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";

    return 0;
}