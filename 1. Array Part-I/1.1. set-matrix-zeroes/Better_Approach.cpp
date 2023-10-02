/*
Approach:
    1. First, we will declare two arrays: a row array of size N and a col array of size M and both are initialized with 0.
        Then, we will use two loops(nested loops) to traverse all the cells of the matrix.
    2. If any cell (i,j) contains the value 0, we will mark ith index of row array i.e. row[i] and jth index of col array col[j] as 1.
        It signifies that all the elements in the ith row and jth column will be 0 in the final matrix.
    3. Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for which either row[i] or col[j]
        is marked as 1.

Complexity Analysis:
    Time Complexity: O(2(N*M)) = O(N*M)
    Space Complexity: O(N) + O(M), as we are using two vectors of size N and M
        where, N --> No. of rows and M --> No. of columns of the Matrix.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will zero down the columns & rows of the matrix cells with entry 0
 * 
 * @param matrix The original input matrix
 * @param n number of rows of the matrix
 * @param m number of columns of the matrix
 * @return vector<vector<int>> the result matrix after zeroing the columns and rows
 */
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> rows(n, 0);
    vector<int> columns(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }

    // Marking the rows 0, if rows[i] = 0:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rows[i] || columns[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is:" << endl;
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}