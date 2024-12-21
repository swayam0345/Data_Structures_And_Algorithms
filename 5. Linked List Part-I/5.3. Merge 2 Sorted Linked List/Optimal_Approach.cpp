/*
Intuition:
    ● A more optimized approach would be to merge the given sorted linked lists directly without using any additional space
      for an intermediate array.
    ● We can leverage the property that the given linked lists would be sorted. We employ a pointer based merging strategy
      where nodes from both linked lists are rearranged to form a single sorted linked list.
    ● Initializing pointers at the head of the two lists, compare the values of the nodes and the smaller value node becomes
      the next node in the merged list.
    ● The pointers are updated until one list is entirely merged, then attach the remaining nodes of the other list directly
      to the merged list as they are already sorted.


Approach:
    1. Initialise two pointers, `t1` and `t2` to the heads of the input linked lists. Create a `dummyNode` with value -1 that
       will serve as the starting point of the merged list. Use a `temp` pointer to traverse and build the combined merged list.
    2. While `t1` and `t2` are not null:
        ● Compare the values of t1 and t2, connect the node with smaller value to the temp pointer of the merged combined list.
        ● Move the temp pointer and the respective t1 and t2 pointer to their next nodes.
    3. Attach the remaining nodes of the non-empty list directly to the temp pointer as they are already sorted.
    4. Return the next of the dummyNode as the head of the merge sorted linked list.


Dry Run:
    Let's take the below as the input to our program.
            _________      _________      _________      __________
    List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
            _________      _________      _________      _________      __________      __________
    List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL


    Iteration-1: Initialize two pointers `t1` & `t2` to the start of List-1 and List-2 respectively.
                 And create a dummyNode to Store the combined sorted Linked List.
                 Initialize a pointer `temp` to progress the sorted linked list.
                
            t1 = List-1 = 2
            t2 = List-2 = 1
            dummyNode = -1
            temp = dummyNode = -1
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                   t1
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                   t2

                    _____________
        dummyNode   |_-1_|_next_| ---> NULL
                     temp

    Iteration-2: Compare the values of `t1` & `t2` connect the node with smaller value to the temp pointer.
                 Move the temp pointer and the respective t1 and t2 pointer to their next nodes.

            t1 = 2
            t2 = 1
            temp->next = min(t1, t2) = 1
            Since, t2 has smaller value we will only move `t2` pointer ahead.
            t2 = t2->next = 3
            temp = temp->next = 1
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                   t1
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                 t2 |______________↑

                    __________      _________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> NULL
                    temp |______________↑

    Iteration-3:
            t1 = 2
            t2 = 3
            temp->next = min(t1, t2) = 2
            Since, t1 has smaller value we will only move `t1` pointer ahead.
            t1 = t1->next = 4
            temp = temp->next = 2
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                  t1 |_____________↑
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                  t2

                    __________      _________      _________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> NULL
                                    temp|______________↑

    Iteration-4:
            t1 = 4
            t2 = 3
            temp->next = min(t1, t2) = 3
            Since, t2 has smaller value we will only move `t2` pointer ahead.
            t2 = t2->next = 3
            temp = temp->next = 3
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                  t1
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                t2 |______________↑

                    __________      _________      _________      _________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> NULL
                                                   temp|______________↑

    Iteration-5:
            t1 = 4
            t2 = 3
            temp->next = min(t1, t2) = 3
            Since, t2 has smaller value we will only move `t2` pointer ahead.
            t2 = t2->next = 3
            temp = temp->next = 3
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                  t1
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                               t2 |______________↑

                    __________      _________      _________      _________      _________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> NULL
                                                                  temp|______________↑

    Iteration-6:
            t1 = 4
            t2 = 6
            temp->next = min(t1, t2) = 4
            Since, t1 has smaller value we will only move `t1` pointer ahead.
            t1 = t1->next = 8
            temp = temp->next = 4
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                t1 |______________↑
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                                                t2

                    __________      _________      _________      _________      _________      _________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> NULL
                                                                                 temp|______________↑

    Iteration-7:
            t1 = 8
            t2 = 6
            temp->next = min(t1, t2) = 6
            Since, t2 has smaller value we will only move `t2` pointer ahead.
            t2 = t2->next = 11
            temp = temp->next = 6
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                                 t1
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                                              t2 |_______________↑

                    __________      _________      _________      _________      _________      _________      _________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_6_|_n_| ---> NULL
                                                                                                temp|______________↑

    Iteration-8:
            t1 = 8
            t2 = 11
            temp->next = min(t1, t2) = 8
            Since, t1 has smaller value we will only move `t1` pointer ahead.
            t1 = t1->next = 10
            temp = temp->next = 8
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                               t1 |_______________↑
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                                                                t2

                    __________      _________      _________      _________      _________      _________      _________      _________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_6_|_n_| ---> |_8_|_n_| ---> NULL
                                                                                                               temp|______________↑

    Iteration-9:
            t1 = 10
            t2 = 11
            temp->next = min(t1, t2) = 10
            Since, t1 has smaller value we will only move `t1` pointer ahead.
            t1 = t1->next = NULL
            temp = temp->next = 10
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                                               t1 |___________↑
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                                                                t2

                    __________      _________      _________      _________      _________      _________      _________      _________      __________
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_6_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                                                                                                              temp|______________↑

    Iteration-10: Now `t1` has reached end of the list. So, we will exit out of the loop and
                  append the remainder of `t2` to temp->next (combined sorted linked list).
            t1 = NULL
            t2 = 11           __________      __________
            temp->next = t2 = |_11_|_n_| ---> |_14_|_n_| ---> NULL
                _________      _________      _________      __________
        List-1  |_2_|_n_| ---> |_4_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> NULL
                                                               t1 |___________↑
                _________      _________      _________      _________      __________      __________
        List-2  |_1_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_6_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                                                                t2
                                                                                                                                                                  _____________t2______________
                    __________      _________      _________      _________      _________      _________      _________      _________      __________      _____↓____      __________       ↓
        dummyNode   |_-1_|_n_| ---> |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_6_|_n_| ---> |_8_|_n_| ---> |_10_|_n_| ---> |_11_|_n_| ---> |_14_|_n_| ---> NULL
                                                                                                                                             temp|______________↑

    ● Finally we will return dummyNode->next which will have the combined sorted linked list.


Complexity Analysis:
    1. Time Complexity: O(N1+N2), where N1 is the number of nodes in the first linked list and N1 in the second linked list
                        as we traverse both linked lists in a single pass for merging without any additional loops or nested
                        iterations.

    2. Space Complexity : O(1), as no additional data structures or space is allocated for storing data, only a constant space
                          for pointers to maintain for traversing the linked list.

*/


#include <bits/stdc++.h>
using namespace std;

// Node class represents a
// node in a linked list
class Node
{
public:
    // Data stored in the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node *sortTwoLinkedLists(Node *t1, Node *t2)
{
    // Create a dummy node to serve
    // as the head of the merged list
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Traverse both lists simultaneously
    while (t1 != nullptr && t2 != nullptr)
    {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (t1->data <= t2->data)
        {
            temp->next = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            t2 = t2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next;
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (t1 != nullptr)
    {
        temp->next = t1;
    }
    else
    {
        temp->next = t2;
    }
    // Return the merged list starting
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Input Linked Lists
    Node *list1 = new Node(2);
    list1->next = new Node(4);
    list1->next->next = new Node(8);
    list1->next->next->next = new Node(10);

    Node *list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(3);
    list1->next->next->next = new Node(6);
    list1->next->next->next->next = new Node(11);
    list1->next->next->next->next->next = new Node(14);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node *mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}
