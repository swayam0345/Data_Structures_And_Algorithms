/*
Approach:
    In this optimal approach, we need to get rid of the extra space we were using.
    The sizes of the given arrays are n(size of arr1[]) and m(size of arr2[]).

    The steps are as follows:
    1. We will declare two pointers i.e. left and right. The left pointer will point to the last index of the
        arr1[] (i.e. Basically the maximum element of the array). The right pointer will point to the first
        index of the arr2[](i.e. Basically the minimum element of the array).
    2. Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1.
        While moving the two pointers we will face 2 different cases like the following:
        (a) If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
        (b) If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
    3. Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements.
        Finally, we will sort the two arrays.

Intuition:
    If we merge the given array, one thing we can assure is that arr1[] will contain all the smaller elements and
    arr2[] will contain all the bigger elements. This is the logic we will use. Using the 2 pointers, we will swap
    the bigger elements of arr1[] with the smaller elements of arr2[] until the minimum of arr2[] becomes greater
    or equal to the maximum of arr1[].

Complexity Analysis:
    1. Time Complexity
        O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
        Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.

    2. Space Complexity
        O(1) as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will will merge the two input arrays into a single sorted array.
 *        Without using any extra space.
 * 
 * @param arr1 First input array
 * @param arr2 Second input array
 * @param n Size of first array
 * @param m Size of second array
 * @return void
 */
void merge(long long arr1[], long long arr2[], int n, int m)
{

    // Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    // Swap the elements until arr1[left] is
    //  smaller than arr2[right]:
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);   //arr1 will contain all the smaller element in sorted order
    sort(arr2, arr2 + m);   //arr1 will contain all the bigger element in sorted order


}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = size(arr1);
    int m = size(arr2);
    merge(arr1, arr2, n, m);
    
    cout << "The merged arrays are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
