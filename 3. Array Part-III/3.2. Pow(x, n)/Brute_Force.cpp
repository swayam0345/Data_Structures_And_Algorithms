/*
Approach:
    Looping from 1 to n and keeping a ans(double) variable. Now every time your loop runs, multiply x with ans.
    At last, we will return the ans.

    We must check if n is negative, if it is negative divide 1 by the ans.

Complexity Analysis:
    1. Time Complexity - O(n), where n is the value of the exponent
    2. Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will calculate the pow(x, n)
 * 
 * @param x The base
 * @param n The exponent
 * @return double Value of pow(x, n)
 */
double myPow(double x, int n)
{
    double ans = 1.0;
    int exp = abs(n);

    for (int i = 0; i < exp; i++)
    {
        ans = ans * x;
    }

    return ans;
}

int main()
{
    double base;
    int exponent;

    cout << "Enter the value of Base and Exponent:" << endl;
    cin >> base >> exponent;
    double pow = myPow(base, exponent);

    cout << ( (exponent > 0) ? pow : (1.0/pow) )<< endl;

    return 0;
}