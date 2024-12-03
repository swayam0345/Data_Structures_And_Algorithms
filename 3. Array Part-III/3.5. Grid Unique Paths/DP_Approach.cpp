/*
Intuition:
    • The dynamic programming solution of this problem is an extension of the recursive solution.
    • In recursive solutions, there are many overlapping subproblems. In this solution instead of
      traversing all the possible paths, whenever we get the result we’ll store it in a matrix for future use.
    • Whenever we encounter the same subproblem we directly get the value from the matrix instead of recomputing it.
    • By this memorization technique, we can avoid the recomputation and the time complexity will be drastically reduced.
    • This is the main intuition behind this dynamic programming solution.

Approach: 
    1. Take a dummy matrix A[ ][ ]  of size m X n and initialize it with '-1'.
    2. At first, we are at the (0,0) index let’s assume this state as (i,j). From here we can move towards the bottom
       as well as towards the right and we recursively move until we hit the base case.
    3. At any point of time when the recursive call goes out of the boundary (example: let’s assume m = 2, n= 3, and the
       current position of i and j is (2,0) which is out of matrix boundary), we will return zero because from here there
       are no possible paths beyond and that is the first base case.
    4. Whenever the recursive call reaches the end we’ll return 1 because we have found one possible path to reach the end.
    5. The only change in the dynamic programming solution is whenever we are returning answers we store them in the matrix
       A[i][j] and wherever we are making a recursive call we simply check if that state is already visited or not in other
       words we’ll check if A[i][j] is `-1` or not, if it is not `-1` that means that there is a subproblem which is repeating.
       Now instead of recomputing the subproblem, we’ll return the value at A[i][j].

Complexity Analysis:
    1. Time Complexity - The time complexity of this solution will be O(n*m) because at max there can be n*m number of states.
    2. Space Complexity - As we are using extra space for the dummy matrix the space complexity will also be O(n*m).

*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Running countPaths manually will give a better understanding of it's recursvie nature. */
    int countPaths(int i, int j, int n, int m,vector<vector<int>> &dp)
    {
        if(i == (n-1) && j == (m-1))
            return 1;

        if(i >= n || j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        else
            return dp[i][j] = countPaths(i+1, j, n, m, dp) + countPaths(i, j+1, n, m, dp);
    }

    int uniquePaths(int m, int n)
    {
        //Initialize the storage vector with -1.
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
       
        //Recursive return value of matrix position [m]X[n].
        int num = countPaths(0, 0, m, n, dp);

        //For 1X1 matrix
        if(m == 1 && n == 1)
            return num;

        return dp[0][0];
    }
};

int main()
{
    Solution obj;
    int n, m;

    cout << "Enter the row(n) and column(m) dimensions of the matrix." << endl;
    cin >> n >> m;

    int totalCount = obj.uniquePaths(n, m);
    cout <<endl << "The total number of Unique Paths are " << totalCount << endl;
}