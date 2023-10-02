/*
Approach:
    1. Find all possible permutations of elements present and store them.
    2. Search input from all possible permutations.
    3. Print the next permutation present right after it.

Complexity Analysis:
    1. Time Complexity
        For finding, all possible permutations, it is taking N!xN. N represents the number of elements present in the input array.
        Also for searching input arrays from all possible permutations will take N!. Therefore, it has a Time complexity of O(N!xN).

    2. Space Complexity
        Since we are not using any extra spaces except stack spaces for recursion calls. So, it has a space complexity of O(1).
*/
