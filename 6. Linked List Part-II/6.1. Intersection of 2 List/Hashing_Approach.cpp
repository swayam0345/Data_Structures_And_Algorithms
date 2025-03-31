/*
Intuition:
    ● In brute force, we are basically performing “searching”. We can also perform searches by Hashing.
    ● Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:
        ➤ Iterate through list 1 and hash its node address, as we are searching for a common attribute.
        ➤ Iterate through list 2 and search the hashed value in the hash table. If found, return node.


Complexity Analysis:
    1. Time Complexity: O(n+m), Iterating through list1 first takes O(n), then iterating through list2 takes O(m).
    2. Space Complexity: O(n), Storing list 1 node addresses in unordered_set.
*/

#include<bits/stdc++.h>
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
    unordered_set<node*> st;

    /* Insert list1 into the unordered set. */
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;

        head2 = head2->next;
    }

    return NULL;
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
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->num << endl;

    return 0;
}