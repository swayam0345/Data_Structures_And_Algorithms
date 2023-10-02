/*
Observation:
Let's understand the scenario using an example to create an observation.
arr[] = {2, 1, 5, 4, 3, 0, 0}   ---> We need to find the next lexicographical permutation of this array.

(A) We need to establish a break point, that will give us the "prefix match"
    We will start by matching from the right hand side of the array

    Iteration   Break Point		Prefix Match    Remarks
    1           0		    	0               We cannot rearrange '0' to get any new permutation
    2           0	    		0 0             We cannot rearrange '0 0' to get any new permutation
    3           3			    3 0 0           Rearranging '3 0 0' gives; 2154003, 2154030 & 2154300. But none of these are greater than 2154300.
    4           4			    4 3 0 0         By rearranging '4 3 0 0' we can not find any permutation that is greater than 2154300.
    5           5			    5 4 3 0 0       With '5 4 3 0 0' we can not find any permutation that is greater than 2154300.
    6           1			    1 5 4 3 0 0     With '1 5 4 3 0 0' we can get many permutation that is greater than 2154300. Like all the permutations
											    that start with '2 5', '2 4' and '2 3' will be greater than 2154300. But out of these permutations we
											    need the one that is just greater than 2154300. In other words we need to find the smallest among these
											    permutations. If we take '2 3' then we will be able to generate the desired permutation.
    
    Now we have the break point i.e; '1'. If we plot a graph we can observe,
      ▲
    B |       As soon as the peak falls we get the break point. Here, until iteration 5 we can
    r |       see the graph moving upwards, but for iteration 6 the graph moves downwards. This
    e |       Indicates the break point.
    a |
    k |
      |                   5
    P |               4 
    o |           3
    i |
    n |                       1
    t |---0---0-----------------------►
                  Iterations

    *********************************************************
    *	Algorithm for finding the break point:			    *
    *       int indx = -1;                                  *
    *	    for(int i = size(arr)-2; i >= 0; i--)		    *
    *	    {										        *
    *	        if(arr[i] < arr[i+1])				        *
    *           {                                           *
    *               indx = i-1;                             *
    *               break;                                  *
    *           }                                           *
    *	    }										        *
    *       if(indx == -1)                                  *
    *       {                                               *
    *           // Return the sorted(asscending) array or   *
    *           // the input array in reverse order.        *
    *           // Because the input array is the last      *
    *           // permutation. And hence we will circle    *
    *           // back to the first permutaion, i.e the    *
    *           // array in sorted order.                   *
    *       }                                               *
    *********************************************************

(B) Replacing the break point
    We have our break point, now we will find the entry that that is just greater than the break point, towards the right of the break point.
    2   1   5   4   3   0   0   Our break point is 1
    So, out of 5, 4, 3, 0, 0    {5, 4, 3} are greater than break point(i.e; 1)
    And out of 5, 4, 3 the smallest is '3'.

    Now we will replace break point '1' with '3'. And the new array will look like:
    2   3   _   _   _   _   _

    *********************************************************
    *	Algorithm for replacing the break point:			*
    *	    for(int i = size(arr)-1; i >= indx; i--)		*
    *	    {										        *
    *	        if(arr[i] > arr[indx])				        *
    *           {                                           *
    *               swap(arr[i], arr[indx]);                *
    *               break;                                  *
    *           }                                           *
    *	    }										        *
    *********************************************************

(C) Rearranging the remaining elements
    Now that we have the new array prefix, we need to arrange the remaining elements in such a way that it will give the next greatest permutation.
    2   3   _   _   _   _   _       {5, 4, 1, 0, 0}

    if we sort or reverse the remaining elements, we will get our desired permutation.
    2   3   0   0   1   4   5

    *****************************************************************
    *	Algorithm to reverse the remaining elements of the array    *
    *       int start = indx+1;                                     *
    *	    std::reverse(arr+start, arr+end);             		    *
    *****************************************************************

Complexity Analysis:
    1. Time Complexity
        O(3N), where N = size of the given array
        Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each,
        where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).

    2. Space Complexity
        Since no extra storage is required. Thus, its space complexity is O(1).
*/


#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function will find return the next lexicographical permutation.
 * 
 * @param A The input array
 * @return vector<int>
 */
vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size(); // size of the array.

    // Step 1: Finding the break point:
    int indx = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // index i is the break point
            indx = i;
            break;
        }
    }

    // If break point does not exist:
    if (indx == -1)
    {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > indx; i--)
    {
        if (A[i] > A[indx])
        {
            swap(A[i], A[indx]);
            break;
        }
    }

    // Step 3: reverse the right half:
    int start = indx + 1;
    reverse(A.begin() + start, A.end());

    return A;
}


int main()
{
    vector<int> A;
    std::string input;

    // Prompt the user for input
    cout << "Enter space-separated integers (e.g., 1 2 3): ";
    getline(std::cin, input);       // Read the entire line

    // Using stringstream to split the input into integers
    std::istringstream ss(input);
    int num;
    while (ss >> num)       // Extracting a value from the std::istringstream ss and storing it in the variable num.
    {
        A.push_back(num);
    }

    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [ ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "]";
    
    return 0;
}
