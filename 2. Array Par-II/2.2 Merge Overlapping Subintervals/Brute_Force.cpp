/*
Approach:
    The steps are as follows
    1. First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).

    2. After that, we will select one interval at a time using a loop(say i) and insert it into our answer list
        (if the answer list is empty or the current interval cannot be merged with the last interval of the answer list).
        While traversing and inserting we will skip the intervals that lie in the last inserted interval of our answer list.

    3. Now, for each interval arr[i], using another loop (say j) we are going to check the rest of the intervals
        (i.e. From index i+1 to n-1) if they can be merged with the selected interval.

    4. Inside loop j, we will continue to merge all the intervals that lie in the selected interval.
        How to check if the current interval can be merged with the selected interval:
            We will compare the current interval’s start with the end of the selected interval.
            If the start is smaller or equal to the end, we can conclude the current interval can
            be a part of the selected interval. So, we will update the selected interval’s end with
            the maximum(current interval’s end, selected interval’s end) in the answer list(not in the original array).

    5. We will break out of loop j, from the first element that cannot be a part of the selected interval.
        How to check if the current interval is not a part of the selected interval:
            We will compare the current interval’s start with the end of the selected interval.
            If the start is greater than the end, we can conclude the current interval cannot be
            a part of the selected interval.

    6. Finally, we will return the answer list.

Complexity Analysis:
    1. Time Complexity
        O(N*logN) + O(2*N), where N = the size of the given array.
        Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that,
                we are using 2 loops i and j. But while using loop i, we skip all the intervals
                that are merged with loop j. So, we can conclude that every interval is roughly
                visited twice(roughly, once for checking or skipping and once for merging). So,
                the time complexity will be 2*N instead of N^2.

    2. Space Complexity
        O(N), as we are using an answer list to store the merged intervals. Except for the answer
        array, we are not using any extra space.
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
        // select an interval:
        int start = arr[i][0];  // First element of the interval(L1)
        int end = arr[i][1];    // Second element of the interval(R1)

        // Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        // check the rest of the intervals:
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);

    cout << "The merged intervals are: " << endl;
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
