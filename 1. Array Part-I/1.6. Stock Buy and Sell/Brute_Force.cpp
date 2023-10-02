/*
Algorithm / Intuition:
    Intuition: We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.
    Approach:
        1. Use a for loop of ‘i’ from 0 to n.
        2. Use another for loop of j from ‘i+1’ to n.
        3. If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
        4. Return maxPro.

Complexity Analysis:
    Time complexity: O(n^2)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will return the maximum profit that can be earned
 *
 * @param arr The input array with the stock prices
 * @return int The maximum profit
 */
int maxProfit(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }

    return maxPro;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int maxPro = maxProfit(arr);

    cout << "Max profit is: " << maxPro << endl;

    return 0;
}