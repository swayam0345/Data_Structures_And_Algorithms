/*
Algorithm/Intuition:
    The extremely naive approach is to get the answer by checking all the elements of the given matrix.
    So, we will traverse the matrix and check every element if it is equal to the given ‘target’.

Algorithm:
    1. We will use a loop(say i) to select a particular row at a time.
    2. Next, for every row, we will use another loop(say j) to traverse each column.
    3. Inside the loops, we will check if the element i.e. matrix[i][j] is equal to the ‘target’.
       If we find any matching element, we will return true.
    4. Otherwise, after completing the traversal, we will return false.

Complexity Analysis:
    1. Time Complexity: O(N X M), where N = given row number, M = given column number.
        Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively.

    2. Space Complexity: O(1), as we are not using any extra space.
*/

#include<bits/stdc++.h>
using namespace std;


/**
 * @brief This function will search for the target element in the input matrix.
 * 
 * @param inputMatrix The input matrix
 * @param row The number of rows of the matrix
 * @param column The number of columns of the matrix
 * @param target The element to be searched in the matrix
 * @return true Return true if the target is found
 * @return false Return false if the target isn't found
 */
bool searchTargetInMatrix(vector<vector<int>> inputMatrix, int row, int column, int target)
{
    bool searchFlag = false;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(inputMatrix[i][j] == target)
            {
                searchFlag = true;
                break;
            }
        }
    }

    return searchFlag;
}

int main()
{
    vector<vector<int>> searchMatrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
    int target = 3;
    bool isTargetPresent = false;
    int n = searchMatrix.size();
    int m = searchMatrix[0].size();

    isTargetPresent = searchTargetInMatrix(searchMatrix, n, m, target);
    cout << ((isTargetPresent == 1) ? "True" : "False");

    return 0;
}
