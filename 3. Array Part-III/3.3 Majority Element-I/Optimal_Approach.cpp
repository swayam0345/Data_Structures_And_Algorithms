/*
Intuition: Moore’s Voting Algorithm
    If the array contains a majority element, its occurrence must be greater than the floor(N/2).
    Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array.
    So when we traverse through the array we try to keep track of the count of elements and the element itself for which we
    are tracking the count.

    After traversing the whole array, we will check the element stored in the variable. If the question states that the array
    must contain a majority element, the stored element will be that one but if the question does not state so, then we need
    to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.

Approach:
    1. Initialize 2 variables:
        Count –  for tracking the count of element
        Element – for which element we are counting
    2. Traverse through the given array.
        ● If Count is 0 then store the current element of the array as Element.
        ● If the current element and Element are the same increase the Count by 1.
        ● If they are different decrease the Count by 1.
    3. The integer present in Element should be the result we are expecting

Complexity Analysis:
    1. Time Complexity - O(N) + O(N), where N = size of the given array.
        Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected
                element is the majority one or not.
        Note: If the question states that the array must contain a majority element, in that case, we do not need the second check.
              Then the time complexity will boil down to O(N).

    2. Space Complexity - O(1), as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will return the majority element in the array.
 * 
 * @param v The input vector
 * @return int The majority element
 */
int majorityElement(vector<int> v)
{
    int n = v.size();
    int max_count = 0;
    int max_element;

    for(int i = 0; i < n; i++)
    {
        if(max_count == 0)
        {
            max_element = v[i];
            max_count = 1;
        }
        else if(v[i] == max_element)
        {
            max_count++;
        }
        else
        {
            max_count--;
        }
    }

    //checking if the stored element is the majority element.
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == max_element)
            cnt++;
    }

    if (cnt > (n / 2))
        return max_element;

    return -1;
}


int main()
{
    vector<int> arr = {2, 2, 1, 4, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;

    return 0;
}