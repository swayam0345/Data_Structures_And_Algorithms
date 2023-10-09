/*
Algorithm/Intuition:
    By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix,
    so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space
    complexity gets reduced to O(1).

    Approach:
    1. Transpose the matrix. (transposing means changing columns to rows and rows to columns)
    2. Reverse each row of the matrix.

Complexity Analysis:
    Time Complexity
        O(N*N) + O(N*N). One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
    Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // transposing the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reversing each row of the matrix
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);

    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
