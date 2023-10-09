/*
Algorithm/Intuition:
    We will start traversing the given array with a single loop. At the first index, as our answer list is empty,
    we will insert the first element into the answer list. While traversing afterward we can find two different cases:
    Case 1: If the current interval can be merged with the last inserted interval of the answer list:
            In this case, we will update the end of the last inserted interval with the maximum(current
            interval’s end, last inserted interval’s end) and continue moving afterward. 

    Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
            In this case, we will insert the current interval in the answer array as it is. And after this
            insertion, the last inserted interval of the answer list will obviously be updated to the current interval.

Approach:
    The steps are as follows:
    1. First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
    2. After that, we will start traversing the array using a loop(say i) and insert the first element into our answer
        list(as the answer list is empty).
    3. Now, while traversing we will face two different cases:
        Case 1: If the current interval can be merged with the last inserted interval of the answer list:
                In this case, we will update the end of the last inserted interval with the maximum(current
                interval’s end, last inserted interval’s end) and continue moving afterward. 
        Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
                In this case, we will insert the current interval in the answer array as it is. And after this
                insertion, the last inserted interval of the answer list will obviously be updated to the current interval.
    4. Thus the answer list will be updated with the merged intervals and finally, we will return the answer list.

    Intuition:  Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging
                simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the
                element in our answer list.

Complexity Analysis:
    1. Time Complexity
        O(N*logN) + O(N), where N = the size of the given array.
        Reason: Sorting the given array takes  O(N*logN) time complexity.
                Now, after that, we are just using a single loop that runs
                for N times. So, the time complexity will be O(N).

    2. Space Complexity
        O(N), as we are using an answer list to store the merged intervals.
        Except for the answer array, we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will remove all the overlapping intervals and optimize the intervals
 * 
 * @param arr The input interval array
 * @return vector<vector<int>> Optimized intervals
 */
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size(); // size of the array

    // sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);

    cout << "The merged intervals are: "
         << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
