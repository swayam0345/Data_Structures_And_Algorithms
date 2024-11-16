/*
Algorithm/Intuition:
    We are going to use the Binary Search algorithm to optimize the approach.

    To make the time complexity even better, we won’t use binary search on every row. We’ll focus only on the particular row
    where the target might be located.

    How to check if a specific row is containing the target:
    1. If the target lies between the first and last element of the row, i (i.e. matrix[i][0] <= target && target <= matrix[i][m-1]),
       we can conclude that the target might be present in that specific row.
    2. Once we locate the potentially relevant row containing the ‘target’, we need to confirm its presence. To accomplish this, we
       will utilize the Binary search algorithm, effectively reducing the time complexity.

Approach:
    1. We will use a loop(say i) to select a particular row at a time.
    2. Next, for every row, i, we will check if it contains the target.
        ● If matrix[i][0] <= target && target <= matrix[i][m-1]: If this condition is met, we can conclude that row i has the possibility
          of containing the target.
        ● So, we will apply binary search on row i, and check if the ‘target’ is present. If it is present, we will return true from this
          step. Otherwise, we will return false.
    3. Otherwise, after completing the traversal, we will return false.

Complexity Analysis:
    1. Time Complexity - O(N + logM), where N = given row number, M = given column number.
        Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows,
        we are not applying binary search rather we are only applying it once for a particular row.
        That is why the time complexity is O(N + logM) instead of O(N*logM).

    2. Space Complexity - O(1), as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will search for the target element in the selected
 *        row of the matrix, using binary search.
 * 
 * @param nums The input array(row of the original matrix), in which the 
 *             target element might be present. 
 * @param target The target element to be searched.
 * @return true Return true if the target is found
 * @return false Return false if the target isn't found
 */
bool binarySearch(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return true;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}


/**
 * @brief This function will select the row of the input matrix in
 *        which the target element might lie.
 * 
 * @param matrix The input matrix
 * @param target The target element to be searched.
 * @return true Return true if the target is found
 * @return false Return false if the target isn't found
 */
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1])
        {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "True\n" : cout << "False\n";

    return 0;
}
