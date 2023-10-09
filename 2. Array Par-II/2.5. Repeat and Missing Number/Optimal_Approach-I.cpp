/*
Intuition:
    The idea is to convert the given problem into mathematical equations. Since we have two variables i.e. missing and repeating,
    we will try to form two linear equations. And then we will find the values of two variables using those equations.

    Assume the repeating number to be X and the missing number to be Y.
    In the array, the numbers are between 1 to N, and in that range, one number is missing and one number is occurring twice.

    (A) Equation-1
        1. Sum of 'N' natural number is;
            Sn = (N*(N+1))/2
        2. Let’s say, S = the summation of all the elements in the given array.
            Therefore, S - Sn = X - Y   ……………………………………… equation-1
    (B) Equation-2
        1. The summation of squares of the first N numbers is:
            S2n = (N*(N+1)*(2N+1))/6
        2. Let’s say, S2 = the summation of squares of all the elements in the given array.
            Therefore,
            S2-S2n = X^2 - Y^2   ……………………………………… equation-2
            S2-S2n = (X-Y)(X+Y), from equation-1 we can substitute (X-Y)
            S2-S2n = (S-Sn)(X+y)
            (S2 - S2n)/(S - Sn) = X + Y     ……………………………………… equation-3

    From equation-1 and equation-3, we can easily find the value of X and Y. And this is what we want.
    equation-1 + equation-3
    (S - Sn) + (S2 - S2n)/(S - Sn) = (X - Y) + (X + Y)
        _______________________________________
        | 2X = (S - Sn) + (S2 - S2n)/(S - Sn) |
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
    After finding 'X' we can easily find 'Y' from either 'equation-1' or 'equation-3'
        ____________________
        | Y = X - (S - Sn) |
        ⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯

Approach:
    Assume the repeating number to be X and the missing number to be Y.

    The steps are as follows:
    1. First, find out the values of S and Sn and then calculate S – Sn (Using the above formulas).
    2. Then, find out the values of S2 and S2n and then calculate S2 – S2n.
    3. After performing steps 1 and 2, we will be having the values of X + Y and X – Y.
        Now, by substitution of values, we can easily find the values of X and Y.

Complexity Analysis:
    1. Time Complexity - O(N), where N = the size of the given array.
        Reason: We are using only one loop running for N times. So, the time complexity will be O(N).

    2. Space Complexity - O(1), as we are not using any extra space to solve this problem.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will find the missing & repeating numbers using mathematical equation.
 * 
 * @param a The input array
 * @return vector<int> The element in 0th index is the repeating number & in index 1
 *                     is the missing number.
 */
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    // Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    // Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    //  Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}