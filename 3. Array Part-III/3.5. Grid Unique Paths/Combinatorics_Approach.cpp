/*
Intuition:
    • If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number
      of steps to reach the end.
    • From start(0, 0) to reach the end(m-1, n-1) we need a certain number of rightward directions and a certain number of downward
      directions. So we can figure out we need 'n-1' no. of rightward direction and 'm-1' no. of downward direction to reach the endpoint.
    • Since we need 'm+n-2' number of steps to reach the end, and for every step we need to move in 'n-1' rightward direction and 'm-1'
      downward direction.
    • We should calculate the combinatorics of either 'm-1' or 'n-1'. Because, we already know that taking one of the path(downward(m-1)
      or rightward(n-1)) will take us to the endpoing. Hence, we need to calculate the combination of any one of the path.
    • If we calculate both paths then there will be repetations which we need to handle. So, we should reduce the complexity and
      calculate one of the combinations (i.e; (m+n-2)C(n-1) or (m+n-2)C(m-1)) and we’ll get the total number of paths.

Note: The combinations formula, used to calculate the number of ways to select r items from a set of n items,
      where the order of the items does not matter. The formula is (nCr = n!/[(n-r)!*r!]), where 'n' is the
      total number of items and 'r' is the number of items being chosen.

Approach:
    1. Run a loop for the mXn matrix.
    2. THen calculate the value of (m+n-2)C(n-1) or (m+n-2)C(m-1).

Complexity Analysis:
    1. Time Complexity - The time complexity of this solution will be O(n-1) or  O(m-1) depending on the formula we are using.
    2. Space Complexity - As we are not using any extra space the space complexity of the solution will be  O(1).

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n)
    {
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
            
        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        
        return (int)res;
    }
};

int main()
{
    Solution obj;
    int totalCount = obj.uniquePaths(2, 3);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}