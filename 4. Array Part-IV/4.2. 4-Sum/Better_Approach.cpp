/*
Intuition:
    ● In the previous approach, we were using 4 loops but in this, we want to reduce that to 3 loops.
    ● We have to somehow manage to calculate nums[l] as we are planning to remove the fourth loop(i.e. l).
    ● In order to calculate nums[l], we can derive a formula like the following:
        nums[l] = target - (nums[i]+nums[j]+nums[k])
    ● So, we will first calculate the triplets nums[i], nums[j], and nums[k] using 3 loops and for the fourth one i.e.
      nums[l] we will not use another loop and instead we will look up the value target-(nums[i]+nums[j]+nums[k]) in
      the array. Thus we can remove the fourth loop from the algorithm.
    ● For implementing the search operation of the fourth element, we will use a similar technique as we used in the
      case of the 3-sum problem.
    ● We will store all the elements between the indices j and k in a HashSet and then we will search for the fourth
      element in the HashSet.

Why are we not inserting all the array elements in the HashSet and then searching for the fourth element?
    Let’s understand this intuition using an example.
    Ex; input array ---> {1, 2, -1, -2, 2, 0, -1} and target = 0
        Now, we will notice a situation like the following:
        ________________________________
        |_1_|_2_|_-1_|_-2_|_2_|_0_|_-1_|
          ▲        ▲            ▲
          |        |            |
          i        j            k
        
        ● Now, the fourth element should be target-(nums[i]+nums[j]+nums[k]) = 0 - (1-1+0) = 0.
        ● And if all the array elements are stored in the HashSet and we search for 0, we will
          end up taking the 0 at index k again.
        ● The quadruplets will be {nums[i], nums[j], nums[k], nums[k]} but this is absolutely incorrect.
        ● That is why we need to only consider the elements that are in between the indices j and k.


Approach:
    1. First, we will declare a set data structure as we want unique quadruplets.
    2. Then we will use the first loop(say i) that will run from 0 to n-1.
    3. Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
    4. Before the third loop, we will declare a HashSet to store the specific array elements
       as we intend to search the fourth element in that HashSet.
    5. Then there will be the third loop(say k) that runs from j+1 to n-1.
    6. Inside the third loop, we will calculate the value of the fourth element i.e. target - (nums[i]+nums[j]+nums[k]).
    7. If the fourth element exists in the HashSet, we will sort these four values i.e. nums[i], nums[j], nums[k], and
       the fourth element, and insert it in the set data structure declared in step 1.
    8. After that, we will insert the k-th element i.e. nums[k] in the HashSet as we only want to insert those array
       elements that are in between indices j and k.
    9. Finally, we will return a list of stored quadruplets stored in the set data structure.

Complexity Analysis:
    1. Time Complexity - O(N^3*log(M)), where N = size of the array, M = no. of elements in the set.
        Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some
                operations on the set data structure which take log(M) time complexity.

    2. Space Complexity - O(2 * no. of the quadruplets) + O(N)
        Reason: we are using a set data structure and a list to store the quads. This results in the first term.
                And the second space is taken by the set data structure we are using to store the array elements.
                At most, the set can contain approximately all the array elements and so the space complexity is O(N).
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int n = nums.size();    //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                // taking bigger data type to avoid integer overflow.
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
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
