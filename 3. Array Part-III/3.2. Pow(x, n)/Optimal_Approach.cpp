/*
Algorithm: Using Binary Exponentiation

Intuition:
    While calculating (n^k), binary exponentiation relies on whether n is even or odd.
        ● If k is even (n^k) can be written as  (n^2)^(k/2). As we can see that computation steps were reduced from k to k/2
          in just one step.
        ● If k is odd (n^k) can be written as n*(n)^(k-1), so now  (k-1) is even. And we can write it as above.
    
    So, if we want to find (2^10), then we can expand it as below;
    2^10 = (2 * 2)^5 = 4^5
    4^5 = 4*(4^4)
    4^4 = (4*4)^2 = 16^2
    16^2 = (16*16)^1 = 256^1
    256^1 = 256*(256^0) = 256

    Finally we can substitute the value of 16^2 as 256 and the multiply it with 4 to find the answer.
    So, from the above example we can conclude that;
        if(n%2 == 0) ---> (X = X * X) and k = k/2
        if(n%2 == 1) ---> (ans = ans * X) and k = k-1


Approach:
    1. Initialize ans as 1.0 and store a duplicate copy of n i.e 'exp' to avoid overflow.
    2. Check if 'exp' is a negative number, in that case, make it a positive number.
    3. Keep on iterating until 'exp' is greater than zero, now if 'exp' is an odd power then multiply x with ans ans reduce 'exp' by 1.
       Else multiply x with itself and divide 'exp' by two.
    4. Now after the entire binary exponentiation is complete and 'exp' becomes zero, check if n is a negative value we know the answer
       will be 1 by ans.

Complexity Analysis:
    1. Time Coplexity - O(n/2), where n is the value of the exponent
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
    long long exp = abs(n);

    while (exp)
    {
        /* Odd Power */
        if (exp % 2 == 1)
        {
            ans = ans * x;
            exp = exp - 1;
        }
        /* Even Power */
        else
        {
            x = x * x;
            exp = exp / 2;
        }
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

    cout << ((exponent > 0) ? pow : (1.0 / pow)) << endl;

    return 0;
}
