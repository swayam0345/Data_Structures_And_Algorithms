/*
Algorithm/Intuition: Keeping count of values
    Since in this case there are only 3 distinct values in the array so it’s easy to maintain the count of all,
    Like the count of 0, 1, and 2. This can be followed by overwriting the array based on the frequency(count) of the values.

Approach:
    1. Take 3 variables to maintain the count of 0, 1 and 2.
    2. Travel the array once and increment the corresponding counting variables
        ( let’s consider count_0 = a, count_1 = b, count_2 = c )
    3. In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’,
        the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.

Complexity Analysis:
    1. Time Complexity
        O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and
        second O(N) for placing them correctly in the original array.
    2. Space Complexity
        O(1) as we are not using any extra space.
*/

#include<bits/stdc++.h>
using namespace std;


/**
 * @brief This function will count the occurance of 0's, 1's and 2's and then
 *        replace the original array with the number of 0's, 1's & 2's respectively.
 * 
 * @param arr The input array
 * @param n Size of the input array
 */
void sortArray(vector<int>& arr, int n)
{
    int count_0 = 0, count_1 = 0, count_2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count_0++;
        else if (arr[i] == 1)
            count_1++;
        else
            count_2++;
    }

    //Replace the places in the original array:
    for (int i = 0; i < count_0; i++)
        arr[i] = 0; // replacing 0's

    for (int i = count_0; i < count_0 + count_1; i++)
        arr[i] = 1; // replacing 1's

    for (int i = count_0 + count_1; i < n; i++)
        arr[i] = 2; // replacing 2's

}

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    int n = size(arr);

    sortArray(arr, n);
    
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
