/*
1. Approach:
    We will use the same formula used for Variation-2.
        { Current element = prevElement * (rowNumber - colIndex) / colIndex }
    In pascal triangle for every row the row number = the number of columns in that row.
        Ex; row 5 will have 5 elements and hence 5 columns.
            1       4       6       4       1

    The steps are as follows:
    1. First, we will print the 1st element i.e. 1 manually.
    2. After that, we will use a while loop to iterate the number of rows of the pascal triangle.
    3. Inside the loop we will use 'col'(initialized to 1) to iterate the columns. But instead of using a loop to iterate,
        we will use a if-else statement.
    4. Thus, the entire row will be printed.

2. Complexity Analysis:
    Time Complexity: O(N^2) where N = given row number. Here we are using only a single loop.
    Space Complexity: O(1) as we not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Function to print the pascal triangle until r rows.
 * 
 * @param r number of rows to be printed.
 */
void printPascalRows(int r)
{
    int previousElement = 1;    // Manually entering the first element of any row in Pascal triangle.
    int currentElement;
    int row = 1, col = 1;

    while(row <= r)
    {
        if(col <= row)
        {
            cout << previousElement << "\t";
            currentElement = (previousElement * (row-col)) / col;
            previousElement = currentElement;
            col++;
            continue;
        }
        else
        {
            cout << endl;
            previousElement = 1;
            col = 1;
            row++;
        }
    }
}


int main()
{
    int row;

    cout << "Enter the row number of Pascal triangle to be printed." << endl;
    cin >> row;

    printPascalRows(row);

    return 0;
}