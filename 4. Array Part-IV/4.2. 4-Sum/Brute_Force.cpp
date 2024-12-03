/*
Intuition:
    This approach is pretty straightforward. Here, we will check all possible quadruplets using 4 loops
    (as we did in the 2-sum problem) and among them, we will consider the ones whose sum is equal to the
    given target. And before considering them as our answer we need to sort the quadruplets in ascending order.

Approach:
    1. First, we will declare a set data structure as we want unique quadruplets.
    2. Then we will use the first loop(say i) that will run from 0 to n-1.
    3. Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
    4. Then there will be the third loop(say k) that runs from j+1 to n-1.
    5. Inside loop k, the fourth loop(say l) will run from k+1 to n-1.
    6. Now, inside these four nested loops, we will check the sum i.e. arr[i]+arr[j]+arr[k]+arr[l], and
       if it is equal to the target we will sort this quadruplet and insert it in the set data structure.
    7. Finally, we will return a list of stored quadruplets.

Complexity Analysis
    1. Time Complexity - O(N^4), where N = size of the array.
        Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we
                are just sorting 4 elements every time.

    2. Space Complexity - O(2 * no. of the quadruplets), as we are using a set data structure and a list to store the quads.
*/


#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int n = nums.size();    //size of the array
    set<vector<int>> st;    //we are using set data structure, because each element in a set has to be unique.

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // taking bigger data type to avoid integer overflow.
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);

    cout << "The quadruplets are: \n";
    for (auto it : ans)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
