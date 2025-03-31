/*
Intuition:
    ● The difference of length method requires various steps to work on it.
    ● Using the same concept of difference of length, a different approach can be implemented.
    ● The process is as follows:-
        ➤ Take two dummy nodes for each list. Point each to the head of the lists & iterate over them.
        ➤ If anyone becomes null, point them to the head of the opposite list and continue iterating until they collide.


Approach:
    1. Define two dummy pointers.
        ● d1: head of the first linked list.
        ● d2: head of the second linked list.
    2. Two pointers (d1 and d2) start at `head1` and `head2`, respectively.
    3. When a pointer reaches the end of its list, it starts at the head of the other list.
        ● If `d1` reaches end of list1 then we will reset d1 to the head of list2.
        ● If `d2` reaches end of list2 then we will reset d2 to the head of list1.
    4. Once the pointers meet at the intersection node, we will stop iterating both the pointers.
       If both become NULL, it means there's no intersection between the two list.


Dry Run:
    Let take the below linked lists as input to our program
            ______________      ______________      ______________      ______________      ______________
    list1:  |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ---> |__2__|_next_| ---> |__4__|_next_| ---> NULL

            ______________      ______________      ______________
    list2:  |__3__|_next_| ---> |__2__|_next_| ---> |__4__|_next_| ---> NULL


    ➤ Initially:
        ● `d1` starts at head1 (first node of List1), i.e., `d1` points to 1.
        ● `d2` starts at head2 (first node of List2), i.e., `d2` points to 3.

    ➤ Iteration 1:
        d1 points to 1, and d2 points to 3.
        Since d1 != d2, we move both pointers;
            ● d1 moves to 3 (next node of List1)
            ● d2 moves to 2 (next node of List2)
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                    d1                                                      |
                                                                        ____↓_________      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑
        list2:-                                         |__3__|_next_|------|
                                                            d2

    ➤ Iteration 2:
        d1 points to 3, and d2 points to 2.
        Since d1 != d2, we move both pointers;
            ● d1 moves to 1 (next node of List1)
            ● d2 moves to 4 (next node of List2)
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                                        d1                                  |
                                                                        ____↓_________      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑ d2
        list2:-                                         |__3__|_next_| -----|

    ➤ Iteration 3:
        d1 points to 1, and d2 points to 4.
        Since d1 != d2, we move both pointers;
            ● d1 moves to 2 (next node of List1)
            ● d2 moves to 3 (next node of List2)
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                                                            d1              |
                                                                        ____↓_________      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑                   d2
        list2:-                                         |__3__|_next_| -----|

    ➤ Iteration 4:
        d1 points to 2, and d2 points to NULL.
        As d2 reached NULL, we reset d2 to head1 (start of List1).
            ● So now, d1 moves to 4 and d2 moves to 1.
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                                                                            |
                                                                        ____↓_________      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑ d1                                 d2
        list2:-                                         |__3__|_next_| -----|

    ➤ Iteration 5:
        d1 points to 4, and d2 points to 1.
        Since d1 != d2, we move both pointers:
            ● d1 moves to NULL (end of List1)
            ● d2 moves to 3 (next node of List2)
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                    d2                                                      |
                                                                        ____↓_________      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑                     d1
        list2:-                                         |__3__|_next_| -----|

    ➤ Iteration 6:
        d1 points to NULL and d2 points to 3.
        As d1 reaches NULL, we reset d1 to head2 (start of List2).
            ● So now, d1 moves to 3 and d2 moves to 1.
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                                          d2                                |
                                                                        ____↓_________      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑                                    d1
        list2:-                                         |__3__|_next_| -----|

    ➤ Iteration 7:
        d1 points to 3, and d2 points to 1.
        Since d1 != d2, we move both pointers:
            ● d1 moves to 2 (next node of List2)
            ● d2 moves to 3 (next node of List1)
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                                                             d2             |
                                                                        ____↓_________      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑
        list2:-                                         |__3__|_next_| -----|
                                                              d1

    ➤ Iteration 8:
        d1 points to 2, and d2 points to 2.
        Since d1 = d2, we will stop iterating the pointers:
            ● They meet at node 2, which is the intersection point.
                ______________      ______________      ______________
        list1:- |__1__|_next_| ---> |__3__|_next_| ---> |__1__|_next_| ------
                                                                            |
                                                                        ____↓_d2______      ______________
                                                                        |__2__|_next_| ---> |__4__|_next_| ---> NULL
                                                        ______________      ↑ d1
        list2:-                                         |__3__|_next_| -----|

    ● So, the intersection point for the two list is at node 2.


Complexity Analysis:
    1. Time Complexity: O(2 * max(len(list1), len(list2))), as we are using the concept of difference of lengths of two lists.
    2. Space Complexity: O(1), No extra data structure is used.

*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int num;
    node *next;

    node(int val)
    {
        num = val;
        next = NULL;
    }
};

// utility function to insert node at the end of the linked list
void insertNode(node *&head, int val)
{
    node *newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// utility function to check presence of intersection
node *intersectionPresent(node *head1, node *head2)
{
    node *d1 = head1;
    node *d2 = head2;

    while (d1 != d2)
    {
        d1 = (d1 == NULL) ? head2 : d1->next;
        d2 = (d2 == NULL) ? head1 : d2->next;
    }

    return d1;
}

// utility function to print linked list created
void printList(node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << " -> ";
        head = head->next;
    }
    cout << head->num << endl;
}

int main()
{
    // creation of both lists
    node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);

    /* List 1: 1 -> 3 -> 1 -> 2 -> 4 */
    node *head1 = head;

    head = head->next->next->next;
    node *headSec = NULL;
    insertNode(headSec, 3);

    /* List 2: 3 -> 2 -> 4 */
    node *head2 = headSec;
    headSec->next = head;

    // printing the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);

    // checking if intersection is present
    node *answerNode = intersectionPresent(head1, head2);
    if (answerNode == NULL)
        cout << "There's no intersection point between the two list" << endl;
    else
        cout << "The intersection point between the two list is " << answerNode->num << endl;

    return 0;
}
