/*
Approach:
    1. We will traverse the matrix for the cells with 0.
    2. When a cell with 0 is found we will mark it's related column and rows as '-1', but not the cell itself(containing 0).
    3. We are marking the the columns and rows with '-1' instead of '0', because if we mark them with 0 then while traversing
        the matrix iteratively we will mistakenly mark a cell as zero which was previously non-zero.
    4. Finally we will replace all the '-1' entries in the matrix with '0' and we have our output.

Complexity Analysis:
    Time Complexity: O((N*M)*(N + M)) + O(N*M) = O((N*M)*(N + M))
        where, N --> No. of rows and M --> No. of columns of the Matrix.
    Space Complexity: O(1) as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will mark the rows of the matrix -1 whose cells have 0 as an entry.
 *        Except for the cell with zero entry originally.
 * 
 * @param matrix The matrix to be marked -1
 * @param n number of rows of the matrix
 * @param m number of columns of the matrix
 * @param i row of the matrix that will be set to -1
 */
void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

/**
 * @brief This function will mark the columns of the matrix -1 whose cells have 0 as an entry.
 *        Except for the cell with zero entry originally.
 * 
 * @param matrix The matrix to be marked -1
 * @param n number of rows of the matrix
 * @param m number of columns of the matrix
 * @param j column of the matrix that will be set to -1
 */
void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

/**
 * @brief This function will iterate the matrix for cells with zero entry.
 *        And call the markRow and markCol functions to mark the columns and
 *        rows of the respective cell with -1.
 * 
 * @param matrix The original matrix
 * @param n 
 * @param m 
 * @return vector<vector<int>> 
 */
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
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