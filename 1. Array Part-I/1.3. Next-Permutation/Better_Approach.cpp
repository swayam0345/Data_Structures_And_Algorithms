/*
Using in-built function of C++ STL.
    C++ provides an in-built function called "next_permutation()" which directly returns the lexicographically
    next greater permutation of the input.
    Similar to the above API we also have "prev_permutation()".

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, 2};
    int n = size(arr);

    next_permutation(arr, arr+n);    //using in-built function of C++
    cout << arr[0] << " " << arr[1] << " " << arr[2];
    
    return 0;
}