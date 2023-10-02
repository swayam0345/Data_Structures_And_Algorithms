/*

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