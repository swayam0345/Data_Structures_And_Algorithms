/*
Approach:
    The problem states that we can either move rightward or downward direction. So we recursively try out all the possible combinations.
    1. At first, we are at the (0,0) index let’s assume this state as (i,j). From here we can move towards the bottom as well as towards
       the right and we recursively move until we hit the base case.

    2. At any point of time when the recursive call goes out of the matrix boundary (example: let’s assume m = 2, n= 2, and the current
       position of i and j is (2,0) which is out of matrix boundary), we’ll return zero because from here there are no possible paths
       beyond and that is the first base case.

    3. Whenever the recursive call reaches the end we’ll return 1 because we have found one possible path to reach the end.

    4. In the recursive tree what result we have got from the left transition and the right transition will sum it up and return the answer.


Note:

countPaths(0, 0)
  ├── countPaths(1, 0)
  │     ├── countPaths(2, 0)
  │     │    ├── countPaths(3, 0) → returns 0 (out of bounds)
  │     │    └── countPaths(2, 1)
  │     │          ├── ... (continues recursively)
  └── countPaths(0, 1)
        ├── countPaths(1, 1)
        │     ├── countPaths(2, 1)
        │     └── countPaths(1, 2)
        └── countPaths(0, 2)
              └── ...
At each level, the recursive calls keep branching, and the results are summed up until the base case is reached.


																					  countPaths(0, 0)
																							|
            -----------------------------------------------------------------------------------------------------------------------------------------------------------------
            |                                                                                                    															|
    countPaths(1, 0)                                                                                     															countPaths(0, 1)
            |                                                                                                    															|
    -------------------------------------------------------------                           								-------------------------------------------------------------
    |                        									|                        									|                                                			|
countPaths(2, 0)       									countPaths(1, 1)                      							countPaths(1,1)                         		  		countPaths(0, 2)
	|                        									|                                                           |                                                	 	|
----------------------                                        ----------------------                               	----------------------							  ----------------------
|                    |                                        |                    |                               	|                    |							  |					   |		
countPaths(3, 0)  countPaths(2, 1)    					countPaths(1, 2)      countPaths(2, 1)    	  countPaths(1, 2)       countPaths(1, 2)    		countPaths(1, 2)           countPaths(0, 3)
(Out of bounds)		|									|					   |						|						|						  |							  |
                    |                    				|                      |                    	|                       |                    	  |							  |
			--------------     					--------------        --------------     		--------------      	 --------------   			--------------				--------------
			|            |     					|            |        |            |     		|            |      	 |            |     		|            |				|			 |
		(3, 1)    	 (2, 2) 	 			(2, 2) 		 (1, 3)   (3, 1) 	 	(2, 2)       (2, 2) 	  (1, 3) 	  (2, 2) 		(1, 3)		(2, 2)		  (1, 3)		(1, 3)		  (0, 4)
	(Out of bounds)     |                 	 |            |        |             |           |            |            |            |			  |				|			   |			|
					--------		    --------	  ---------   (Out of	 --------	  --------		--------	--------	  --------	  --------		--------	   --------		--------
					|	   |		    |	   |	  |	      |   bounds)  	 |      |	  |		 |	    |	   |	|	   |	  |	     |	  |		 |	  	|	   |	   |	  |	    |      |
				  (3,2) (2,3)	      (3,2) (2,3)   (2,3)  (1,4) 		   (3,2) (2,3)  (3,2) (2,3)   (2,3) (1,4) (3,2) (2,3)   (2,3) (1,4)  (3,2) (2,3)  (2,3) (1,4)    (2,3) (1,4)   (1,4) (0,5)
                    .     .             .     .       .      .               .     .      .     .       .     .     .     .       .     .      .     .      .     .        .     .       .     .
                    .     .             .     .       .      .               .     .      .     .       .     .     .     .       .     .      .     .      .     .        .     .       .     .
                    .     .             .     .       .      .               .     .      .     .       .     .     .     .       .     .      .     .      .     .        .     .       .     .


Complexity Analysis:
    1. Time Complexity: The time complexity of this recursive solution is exponential.
    2. Space Complexity: As we are using stack space for recursion so the space complexity will also be exponential.

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Running countPaths manually will give a better understanding of it's recursvie nature. */
    int countPaths(int i, int j, int n, int m)
    {
        if((i == n-1) && (j == m-1))
            return 1;

        /* Array out of bounds. */
        if((i >= n) || (j >= m))
            return 0;

        /* Traversing both row-wise(i) and column-wise(j). */
        else
            return countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
    }

    int uniquePaths(int m, int n)
    {
       return countPaths(0, 0, m, n);
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
