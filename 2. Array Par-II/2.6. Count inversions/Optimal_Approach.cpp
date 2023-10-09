/*
Algorithm / Intuition:
    Observation:
    Let’s build the intuition for this approach using a modified version of the given question.

    Assume two sorted arrays are given i.e. a1[] = {2, 3, 5, 6} and a2[] = {2, 2, 4, 4, 8}. Now, we have to count the pairs
    i.e. a1[i] and a2[j] such that a1[i] > a2[j].

    In order to solve this, we will keep two pointers i and j, where 'i' will point to the first index of a1[] and 'j' will point
    to the first index of a2[]. Now in each iteration, we will do the following:
        ● If a1[i] <= a2[j]: These two elements cannot be a pair and so we will move the pointer i to the next position.
          This case is illustrated below:
                     _________________                          _____________________
            A1[]  =  |_2_|_3_|_5_|_6_|                 A2[]  =  |_2_|_2_|_4_|_4_|_8_|
                       ▲                                          ▲
                       |                                          |
                       i                                          j
          Why we moved the 'i' pointer: We know, that the given arrays are sorted. So, all the elements after the pointer 'j',
          should be greater than a1[1]. Now, as a1[i] is smaller or equal to a2[j], it is obvious that a1[i] will be smaller
          or equal to all the elements after a2[j]. We need a bigger value of a1[i] to make a pair and so we move the 'i' pointer
          to the next position i.e. next bigger value.

        ● If a1[i] > a2[j]: These two elements can be a pair and so we will update the count of pairs. Now, here, we should observe
          that as a1[i] is greater than a2[j], all the elements after a1[i] will also be greater than a2[j] and so, those elements
          will also make pair with a2[j]. So, the number of pairs added will be n1-i (where n1 = size of a1[ ]). Now, we will move
          the j pointer to the next position. This case is also illustrated below:
                     _________________                          _____________________
            A1[]  =  |_2_|_3_|_5_|_6_|                 A2[]  =  |_2_|_2_|_4_|_4_|_8_|
                           ▲                                      ▲
                           |                                      |
                           i                                      j
    The above process will continue until at least one of the pointers reaches the end.

    Until now, we have figured out how to count the number of pairs in one go if two sorted arrays are given. But in our actual question,
    only a single unsorted array is given. So, how to break it into two sorted halves so that we can apply the above observation?

    We can think of the merge sort algorithm that works in a similar way we want. In the merge sort algorithm, at every step, we divide the
    given array into two halves and then sort them, and while doing that we can actually count the number of pairs.

    Basically, we will use the merge sort algorithm to use the observation in the correct way.


Approach:
    The steps of the merge() function were the following:
    1. In the merge function, we will use a temp array to store the elements of the two sorted arrays after merging.
       Here, the range of the left array is low to mid and the range for the right half is mid+1 to high.
    2. Now we will take two pointers left and right, where left starts from low and right starts from mid+1.
    3. Using a while loop( while(left <= mid && right <= high)), we will select two elements, one from each half, and
       will consider the smallest one among the two. Then, we will insert the smallest element in the temp array.
    4. After that, the left-out elements in both halves will be copied as it is into the temp array.
    5. Now, we will just transfer the elements of the temp array to the range low to high in the original array.

    Modifications in merge() and mergeSort():
    ● In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the merge().
    ● While comparing a[left] and a[right] in the 3rd step of merge(), if a[left] > a[right], we will simply add this line:
        cnt += mid-left+1 (mid+1 = size of the left half)
    ● Now, we will return this cnt from merge() to mergeSort().
    ● Inside mergeSort(), we will keep another counter variable that will store the final answer. With this cnt, we will add the
      answer returned from mergeSort() of the left half, mergeSort() of the right half, and merge().
    ● Finally, we will return this cnt, as our answer from mergeSort().


Complexity Analysis:
    1. Time Complexity: O(N*logN), where N = size of the given array.
        Reason: We are not changing the merge sort algorithm except by adding a variable to it.
                So, the time complexity is as same as the merge sort.

    2. Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
*/

#include <bits/stdc++.h>
using namespace std;


/**
 * @brief This function will merge the input array in a sorted order
 *        And when the right element is less than the left will be 
 *        perform our count operation, i.e; count += (mid - left + 1).
 * 
 * @param arr The input array from 'mergeSort' fuction.
 * @param low The lower index of the left array.
 * @param mid The higher index of the left array and 'mid+1' is the
 *            lower index of the right array.
 * @param high The higher index of the right array.
 * @return int The total count of the possible inversions for the
 *             input array.
 */
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}


/**
 * @brief This function will be called recursively to divide the array
 *        until size 1.
 * 
 * @param arr The input array
 * @param low The first index of the array
 * @param high The last index of the array
 * @return int The total number of inversions possible in the input array.
 */
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;

    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);    // merging sorted halves

    return cnt;
}


/**
 * @brief This function will call the mergeSort with the initial array
 *        and inversion count variable.
 * 
 * @param a The original input array
 * @param n The size of the input array
 * @return int The total number of inversions possible in the input array.
 */
int numberOfInversions(vector<int> &a, int n)
{
    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}


int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);

    cout << "The number of inversions are: "
         << cnt << endl;

    return 0;
}
