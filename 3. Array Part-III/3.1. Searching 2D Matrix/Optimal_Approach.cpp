/*
Intuition:
    ● If we flatten the given 2D matrix to a 1D array, the 1D array will also be sorted. By utilizing binary search on this sorted
    ● 1D array to locate the ‘target’ element, we can further decrease the time complexity. The flattening will be like the following:
        ------------------------
        | 3  |  4  |  7  |  9  |
        | 12 |  13 |  16 |  18 |
        | 20 |  21 |  23 |  29 |  __________  Flattening the 2D array to 1D
        ------------------------           |   ________________________________________________________
                                            ↪ ┃_3_┃_4_|_7_┃_9_┃_12_┃_13_┃_16_┃_18_┃_20_┃_21_┃_23_┃_29_┃

    ● But if we really try to flatten the 2D matrix, it will take O(N x M) time complexity and extra space to store the 1D array.
      In that case, it will not be the optimal solution anymore.

How to apply binary search on the 1D array without actually flattening the 2D matrix:
    ● If we can figure out how to convert the index of the 1D array into the corresponding cell number in the 2D matrix,
      our task will be complete.
    ● In this scenario, we will use the binary search with the indices of the imaginary 1D array, ranging from 0 to (NxM)-1
      (total no. of elements in the 1D array = NxM).
    ● When comparing elements, we will convert the index to the cell number and retrieve the element.
    ● Thus we can apply binary search in the imaginary 1D array.

How to convert 1D array index to the corresponding cell of the 2D matrix:
    ● If index = i, and no. of columns in the matrix = m, the index i corresponds to the cell with
        row = i/m and col = i%m. More formally, the cell is [(i/m), (i%m)] (0-based indexing).

        Ex; Index '5' in 1D array corresponds to cell(1, 1) in 2D matrix.
            row = (5 / 4) = 1 (Integer division)
            column = (5 % 4) = 1

    ● The range of the indices of the imaginary 1D array is [0, (NxM)-1] and in this range, we will apply binary search.

Approach:
    1. Place the 2 pointers i.e. low and high & the pointer low will point to 0 and the high will point to (NxM)-1.
    2. Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
        mid = (low+high) / 2
    3. Eliminate the halves based on the element at index mid: To get the element, we will convert index ‘mid’ to the
       corresponding cell using the above formula. Here no. of columns of the matrix = M.
        row = mid / M, col = mid % M.
            ● If matrix[row][col] == target: We should return true here, as we have found the ‘target’.
            ● If matrix[row][col] < target: In this case, we need bigger elements. So, we will eliminate the left half and
              consider the right half (low = mid+1).
            ● If matrix[row][col] > target: In this case, we need smaller elements. So, we will eliminate the right half and
              consider the left half (high = mid-1).
    4. Steps 2-3 will be inside a while loop and the loop will end once low crosses high
       (i.e. low > high). If we are out of the loop, we can say the target does not exist in the matrix. So, we will return false.

Complexity Analysis:
    1. Time Complexity - O(log(NxM)), where N = given row number, M = given column number.
        Reason: We are applying binary search on the imaginary 1D array of size NxM.

    2. Space Complexity - O(1), as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will search for the target element in the using binary search.
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
    int low = 0;
    int high = (n * m) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m, column = mid % m;        // row = index / no. of columns & column = index % no. of columns

        if (matrix[row][column] == target)
            return true;
        else if (target < matrix[row][column])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;

}


int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "True\n" : cout << "False\n";

    return 0;
}
