/*
Algorithm/Intuition:
    We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array,
    if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

    Approach:
    1. Create a variable maxPro and store 0 initially.
    2. Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
    3. Run a for loop from 0 to n.
    4. Update the minPrice if it is greater than the current element of the array
    5. Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
    6. Return the maxPro.

Complexity Analysis:
    Time complexity - O(n)
    Space Complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;


/**
 * @brief This function will return the maximum profit that can be earned
 * 
 * @param arr The input vector with the stock prices
 * @param n Size of the input vector
 * @return int 
 */
int maxProfit(vector<int> &arr, int n)
{
    int maxPro = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    return maxPro;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int maxPro = maxProfit(arr, size(arr));

    cout << "Max profit is: " << maxPro << endl;

    return 0;
}