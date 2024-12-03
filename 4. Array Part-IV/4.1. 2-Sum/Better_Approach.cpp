/*
Intuition:
    ● Basically, in the previous approach we selected one element and then searched for the other one using a loop.
    ● Here instead of using a loop, we will use the HashMap to check if the other element i.e. target-(selected element) exists.
    ● Thus we can trim down the time complexity of the problem.
    ● And for the second variant, we will store the element along will its index in the HashMap.
    ● Thus we can easily retrieve the index of the other element i.e. target-(selected element) without iterating the array.

Approach:
    1. We will select the element of the array one by one using a loop(say i).
    2. Then we will check if the other required element(i.e. target-arr[i]) exists in the hashMap.
    3. If that element exists, then we will return “YES” for the first variant or we will return the current index i.e. i,
       and the index of the element found using map i.e. mp[target-arr[i]].
    4. If that element does not exist, then we will just store the current element in the hashMap along with its index.
       Because in the future, the current element might be a part of our resultwer.
    5. Finally, if we are out of the loop, that meresult there is no such pair whose sum is equal to the target. In this case,
       we will return either “NO” or {-1, -1} as per the variant of the question.

Complexity Analysis:
    1. Time Complexity - O(N), where N = size of the array.
       Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally.
               So the time complexity is O(N).
       Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element.
             In that case, the time complexity will be O(N2). If we use map instead of unordered_map,
             the time complexity will be "O(N* logN)" as the map data structure takes logN time to find an element.

    2. Space Complexity - O(N), as we are using the map data structure.
*/

#include <bits/stdc++.h>
using namespace std;


std::pair<string, vector<int>> twoSum(int n, vector<int> &arr, int target)
{
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int remainingTarget = target - num;
        if (umap.find(remainingTarget) != umap.end())
        {
            return {"YES", {umap[remainingTarget], i}};
        }
        umap[num] = i;
    }

    return {"NO", {-1, -1}};
}


int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    auto result = twoSum(n, arr, target);

    cout << "This is the answer for variant 1: " << result.first << endl;
    cout << "This is the answer for variant 2: [" << result.second[0] << ", "
         << result.second[1] << "]" << endl;

    return 0;
}
