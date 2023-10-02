/*
1. Approach
    We will try to build intuition for this approach using the following observations.
                        1
                    1       1
                1       2       1
            1       3       3       1
        1       4       6       4       1
    1       5       10      10      5       1 _ (5*4*3*2*1)/(1*2*3*4*5)
         /         /        |         \         
      5/1 (5*4)/(1*2)  (5*4*3)/(1*2*3)  (5*4*3*2)/(1*2*3*4)

    { 1*(6-1)/1 = 5 } ---> { 5*(6-2)/2 = 10 } ---> { 10*(6-3)/3 = 10 } ---> { 10*(6-4)/4 = 5 } ---> { 5*(6-5)/5 = 1}

    From the above observation we can conclude the below formula will be the following;
        { Current element = prevElement * (rowNumber - colIndex) / colIndex }

    The steps are as follows:
    1. First, we will print the 1st element i.e. 1 manually.
    2. After that, we will use a loop(say i) that runs from 1 to n-1. It will print the rest of the elements.
    3. Inside the loop, we will use the above-said formula to print the element. We will multiply the previous answer by (n-i)
        and then divide it by i itself.
    4. Thus, the entire row will be printed.

2. Complexity Analysis:
    Time Complexity: O(N) where N = given row number. Here we are using only a single loop.
    Space Complexity: O(1) as we not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Function to print row r of the pascal triangle.
 * 
 * @param r row number to print
 */
void printPascalRow(int r)
{
    int previousElement = 1;    // Manually entering the first element of any row in Pascal triangle.
    int currentElement;

    cout << previousElement << "\t";
    for(int i = 1; i < r; i++)
    {
        currentElement = (previousElement * (r - i)) / i;
        cout << currentElement << "\t";
        previousElement = currentElement;
    }
}

int main()
{
    int row;

    cout << "Enter the row number of Pascal triangle to be printed." << endl;
    cin >> row;

    printPascalRow(row);

    return 0;
}