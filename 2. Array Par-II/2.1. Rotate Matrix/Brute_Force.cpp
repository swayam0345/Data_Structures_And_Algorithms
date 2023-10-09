/*
Algorithm/Intuition:
    Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix,
    take the second row of the matrix, and put it in the second last column of the matrix and so.

Complexity Analysis:
    Time Complexity
        O(N*N) to linearly iterate and put it into some other matrix.
    Space Complexity
        O(N*N) to copy it into some other matrix.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will rotate the original matrix by 90°.
 * 
 * @param matrix The input matrix
 * @return vector<vector<int>> The rotated matrix
 */
vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }

    return rotated;
}

int main()
{
    vector<vector<int>> arr;
    arr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
          };
    vector<vector<int>> rotated = rotate(arr);

    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++)
    {
        for (int j = 0; j < rotated[0].size(); j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }
}