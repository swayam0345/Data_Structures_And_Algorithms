/*
Approach:
    We will reduce the search length. This can be done by searching the length of the shorter linked list.
    1. Find the length of both the list.
    2. Find the positive difference between these lengths.
    3. Move the dummy pointer of the larger list by the difference achieved. This makes our search length
       reduced to a smaller list length.
    4. Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.


Complexity Analysis:
    1. Time Complexity: O(2 * max(len(list1), len(list2))) + O(abs(len(list1) - len(list2))) + O(min(len(list1), len(list2)))
        Reason: Finding the length of both lists takes max(length of list1, length of list2),
                because it is found simultaneously for both of them. Moving the head pointer
                ahead by a difference of the length will take O(abs(list1 - list2)).
                The next one is for searching the intersection, as we will search until either
                of list1 or list2 reaches NULL.

    2. Space Complexity: O(1), No extra space is used.

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

int getDifference(node *head1, node *head2)
{
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            len1++;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            len2++;
            head2 = head2->next;
        }
    }

    return len1 - len2; // if difference is neg-> length of list2 > length of list1 else vice-versa
}

// utility function to check presence of intersection
node *intersectionPresent(node *head1, node *head2)
{
    int diff = getDifference(head1, head2);

    if (diff < 0)
    {
        /* Moving `head2` as difference in lenght is negative, which means list2 is longer than list1. */
        while (diff++ != 0)
            head2 = head2->next;
    }
    else
    {
        /* Moving `head1` as difference in lenght is negative, which means list1 is longer than list2. */
        while (diff-- != 0)
            head1 = head1->next;
    }
    
    while (head1 != NULL)
    {
        if (head1 == head2)
            return head1;
        head2 = head2->next;
        head1 = head1->next;
    }

    return head1;
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
    insertNode(head, 4);
    insertNode(head, 1);
    insertNode(head, 8);
    insertNode(head, 4);
    insertNode(head, 5);

    /* List 1: 4 -> 1 -> 8 -> 4 -> 5 */
    node *head1 = head;

    head = head->next->next;
    node *headSec = NULL;
    insertNode(headSec, 5);
    insertNode(headSec, 6);
    insertNode(headSec, 1);

    /* List 2: 5 -> 6 -> 1 -> 8 -> 4 -> 5 */
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
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->num << endl;

    return 0;
}
