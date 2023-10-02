/*
Approach:
    Formula to find out the element at row 'r' and column 'c' is; r-1Cc-1.
    Let’s try to analyze the formula to find the value of the combination assuming r-1 as n and c-1 as r:
        nCr = n! / (r! * (n-r)!)
        If we expand the above formula and optimize it, then it will boil down to;
        nCr = (n*(n-1)*(n-2)*.....*(n-r+1)) / (r*(r-1)*(r-2)*....1)

    We will use this optimized formula to calculate the value of nCr. But while implementing this into code we will
    take the denominator in the forward direction like: 
        (n / 1)*((n-1) / 2)*.....*((n-r+1) / r).

Complexity Analysis:
    Time Complexity: O(r) = O(c-1) = O(c)
        As we are running a loop for r times, where r is c-1.
    Space Complexity: O(1) as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Function to Calculate nCr
 * 
 * @param n row number
 * @param r column number
 * @return int 
 */
int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

/**
 * @brief Function to calculate the r-1Cc-1 
 * 
 * @param r row of the pascal triangle
 * @param c column of the pascal triangle
 * @return int 
 */
int pascalTriangle(int r, int c)
{
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: " << element;

    return 0;
}