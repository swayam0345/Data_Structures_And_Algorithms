/*
Approach:
    1. Sort the input array.
    2. After that, if there is any duplicate number they will be adjacent.
    3. So we simply have to check if arr[i]==arr[i+1] and if it is true,arr[i] is the duplicate number.

Complexity Analysis:
    1. Time Complexity - O(Nlogn + N)
        Reason: NlogN for sorting the array and O(N) for traversing through the array and checking if adjacent elements are equal or not.
                But this will distort the array.

    2. Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will find the duplicate element in the input array.
 * 
 * @param arr The input array
 * @return int The duplicate element
 */
int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }

    return -1;
}
int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};

    if(findDuplicate(arr) != -1)
    {
        cout << "The duplicate element is " << findDuplicate(arr) << endl;
    }
    else
    {
        cout << "There isn't any duplicate element in the array.";
    }

    return 0;
}