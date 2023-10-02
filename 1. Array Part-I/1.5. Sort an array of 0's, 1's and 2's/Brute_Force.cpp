/*
Approach:
    Sorting ( even if it is not the expected solution here but it can be considered as one of the approaches).
    Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the array would arrange the elements in increasing order.

Complexity Analysis:
    Time Complexity - O(N*logN)
    Space Complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    // Create a vector of integers
    vector<int> myVector = {0, 2, 1, 2, 0, 1};

    // Using std::sort to sort the vector in ascending order
    sort(myVector.begin(), myVector.end());

    for (int element : myVector)
    {
        cout << element << " ";
    }
    cout << std::endl;

    return 0;
}
