/*
Intuition:
    ● In order to solve this problem we will use the merge sort algorithm like we used in the problem count inversion(2.6)
      with a slight modification of the merge() function.
    ● But in this case, the same logic will not work. In order to understand this, we need to deep dive into the merge() function.

Why the same logic of count inversion will not work?
    ● The merge function works by comparing two elements from two halves i.e. arr[left] and arr[right].
    ● Now, the condition in the question was arr[i] > arr[j]. That is why we merged the logic. While
      comparing the elements, we counted the number of pairs.
    ● But in this case, the condition is arr[i] > 2*arr[j]. And, we cannot change the condition of comparing
      the elements in the merge() function.
    ● If we change the condition, the merge() function will fail to merge the elements. So, we need to check
      this condition and count the number of pairs separately.

Dry Run:
    ● Here, our approach will be to check, for every element in the sorted left half(sorted), how many elements in the
      right half(also sorted) can make a pair. Let’s try to understand, using the following example:

        *************************************************
        *                                               *
        *   Condition - arrLeft[i] > (2 * arrRight[j])  *
        *                                               *
        *************************************************
                      ____________________                                _______________________________________
        arrLeft[]  =  |_6_|_13_|_21_|_25_|                 arrRight[]  =  |_1_|_2_|_3_|_4_|_4_|_5_|_9_|_11_|_13_|

            ➤                ____________________                                _______________________________________
                arrLeft[]  =  |_6_|_13_|_21_|_25_|                 arrRight[]  =  |_1_|_2_|_3_|_4_|_4_|_5_|_9_|_11_|_13_|
                                ▲                                                   ▲   ▲
                                |                                                   |   |
                                i                                                   j   j+1
                arrLeft[i] = 6 the condition will be true for j = (0, 1) i.e; arrRight[] = { 1, 2 }.
                [ 6 > (2*1) and 6 > (2*2) ]

                So, 6 will make the following pairs; { (6, 1) and (6, 2) }.

            ➤                ____________________                                _______________________________________
                arrLeft[]  =  |_6_|_13_|_21_|_25_|                 arrRight[]  =  |_1_|_2_|_3_|_4_|_4_|_5_|_9_|_11_|_13_|
                                    ▲                                               ▲   ▲   ▲   ▲   ▲   ▲
                                    |                                               |   |   |   |   |   |
                                    i                                               j   j+1 j+2 j+3 j+4 j+5
                arrLeft[i] = 23 the condition will be true for j = (0, 1, 2, 3, 4, 5) i.e; arrRight[] = { 1, 2, 3, 4, 4, 5 }.
                [ 13 > (2*1), 13 > (2*2), 13 > (3*2), 13 > (4*2), 13 > (4*2) and 13 > (5*2) ]

                So, 13 will make the following pairs; { (13, 1), (13, 2), (13, 3), (13, 4), (13, 4), and (13, 5) }.

            ➤                ____________________                                _______________________________________
                arrLeft[]  =  |_6_|_13_|_21_|_25_|                 arrRight[]  =  |_1_|_2_|_3_|_4_|_4_|_5_|_9_|_11_|_13_|
                                         ▲                                          ▲   ▲   ▲   ▲   ▲   ▲   ▲
                                         |                                          |   |   |   |   |   |   |
                                         i                                          j   j+1 j+2 j+3 j+4 j+5 j+6
                arrLeft[i] = 23 the condition will be true for j = (0, 1, 2, 3, 4, 5, 6) i.e; arrRight[] = { 1, 2, 3, 4, 4, 5, 9 }.
                [ 21 > (2*1), 21 > (2*2), 21 > (3*2), 21 > (4*2), 21 > (4*2), 21 > (5*2) and 21 > (2*9) ]

                So, 21 will make the following pairs; { (21, 1), (21, 2), (21, 3), (21, 4), (21, 4), (21, 5), and (21, 9) }.

            ➤                ____________________                                _______________________________________
                arrLeft[]  =  |_6_|_13_|_21_|_25_|                 arrRight[]  =  |_1_|_2_|_3_|_4_|_4_|_5_|_9_|_11_|_13_|
                                              ▲                                     ▲   ▲   ▲   ▲   ▲   ▲   ▲    ▲
                                              |                                     |   |   |   |   |   |   |    |
                                              i                                     j   j+1 j+2 j+3 j+4 j+5 j+6 j+7
                arrLeft[i] = 23 the condition will be true for j = (0, 1, 2, 3, 4, 5, 6, 7) i.e; arrRight[] = { 1, 2, 3, 4, 4, 5, 9, 11 }.
                [ 25 > (2*1), 25 > (2*2), 25 > (3*2), 25 > (4*2), 25 > (4*2), 25 > (5*2), 25 > (2*9) and 25 > (2*11) ]

                So, 25 will make the following pairs; { (25, 1), (25, 2), (25, 3), (25, 4), (25, 4), (25, 5), (25, 9), and (25, 11) }.

    If we list down all the pairs as below, we can notice a pattern which is;
        ⦿ For every (i < i+1) all the pair(s) of 'i' will form a pair with 'i+1'

        arrLeft[]       Pairs
            6           (6, 1), (6, 2)
            13          (13, 1), (13, 2), (13, 3), (13, 4), (13, 4), (13, 5)
            21          (21, 1), (21, 2), (21, 3), (21, 4), (21, 4), (21, 5), (21, 9)
            25          (25, 1), (25, 2), (25, 3), (25, 4), (25, 4), (25, 5), (25, 9), (25, 11)
 
        Note: This is true because arrLeft[1] will always be greater than arrLeft[0] which concludes
              if arrRight[0] and arrRight[1] are making a pair with arrLeft[0], they will obviously
              make pairs with a number greater than arrLeft[0] i.e. arrLeft[1].
        
    ⦿ Thus before the `merge` step in the merge sort algorithm, we will calculate the total number of pairs each time.

Approach:
    The steps are basically the same as they are in the case of the "merge sort" algorithm. The change will be just in the
    mergeSort() function.

    1. In order to count the number of pairs, we will keep a count variable, `cnt` initialized to 0 beforehand inside the mergeSort().
    2. We will add the numbers returned by the previous mergeSort() calls to `cnt`.
    3. Before the merge step, we will count the number of pairs using a function, named `countPairs()`.
    4. We need to remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.
    
        ➤ The steps of the countPairs() function will be as follows:
            (a) We will declare a variable, `cnt`, initialized with 0.
            (b) We will run a loop from low to mid, to select an element at a time from the left half.
            (c) Inside that loop, we will use another loop to check how many elements from the right half can make a pair.
            (d) Lastly, we will add the total number of elements i.e. "(right-(mid+1))" (where right = current index),
                to the `cnt` and return it.

Complexity Analysis:
    1. Time Complexity - O(2N*logN), where N = size of the given array.
       Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself.
               Now, inside the function countPairs(), though we are running a nested loop, we are actually
               iterating the left half once and the right half once in total. That is why, the time complexity
               is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity.
               Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

    2. Space Complexity - O(N), as in the merge sort We use a temporary array to store elements in sorted order.
*/



#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

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
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
    
        cnt += (right - (mid + 1));     // Add previous pairs to the current element.
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;

    if (low >= high)
        return cnt;
    
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);        // left half
    cnt += mergeSort(arr, mid + 1, high);   // right half
    cnt += countPairs(arr, low, mid, high); // Modification
    merge(arr, low, mid, high);             // merging sorted halves

    return cnt;
}


int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = mergeSort(a, 0, n - 1);
    cout << "The number of reverse pair is: " << cnt << endl;

    return 0;
}

