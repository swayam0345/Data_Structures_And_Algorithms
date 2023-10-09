/*
Approach:
    The steps are as follows:
    1. We will first declare a third array, arr3[] of size n+m, and two pointers i.e. left and right,
        one pointing to the first index of arr1[] and the other pointing to the first index of arr2[].
    2. The two pointers will move like the following:
        (a) If arr1[left] < arr2[right]: We will insert the element arr1[left] into the array and increase the left pointer by 1.
        (b) If arr2[right] < arr1[left]: We will insert the element arr2[right] into the array and increase the right pointer by 1.
        (c) If arr1[left] == arr2[right]: Insert any of the elements and increase that particular pointer by 1.
        (d) If one of the pointers reaches the end, then we will only move the other pointer and insert the rest of the elements of
            that particular array into the third array i.e. arr3[].
    3. If we move the pointer like the above, we will get the third array in the sorted order.
    4. Now, from sorted array arr3[], we will copy first n(size of arr1[]) elements to arr1[], and the next m(size of arr2[]) elements to arr2[].

Complexity Analysis:
    1. Time Complexity
        O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
        Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[].
                And another O(n+m) is for filling back the two given arrays from arr3[].

    2. Space Complexity: O(n+m) as we use an extra array of size n+m.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will will merge the two input arrays into a single sorted array
 *
 * @param arr1 First input array
 * @param arr2 Second input array
 * @param n Size of first array
 * @param m Size of second array
 * @return void
 */
void merge(long long arr1[], long long arr2[], int n, int m)
{

    // Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    // Insert the elements from the 2 arrays
    //  into the 3rd array using left and right
    //  pointers:

    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else
        {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
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