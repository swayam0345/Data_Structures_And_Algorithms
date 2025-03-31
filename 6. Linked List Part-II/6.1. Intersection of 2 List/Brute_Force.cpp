/*
Intuition:
    ● We know intersection means a common attribute present between two entities. Here, we have linked lists as given entities. 

    ➤ What should be the common attribute for two linked lists? 
        ● If you believe a common attribute is a node's value, then think properly!
        ● If we take our example 1, there we can see both lists have nodes of value 3. But it is not the first intersection node.

    ➤ So what’s the common attribute?
        ● It is the node itself that is the common attribute. So, the process is as follows;
            (a) Keep any one of the list to check if its node is present in the other list. Here, we are choosing
                the second list for this task.
            (b) Iterate through the other list. Here, it is the first one. 
            (c) Check if both the nodes are the same. If yes, we got our first intersection node.
            (d) If not, continue iteration.
            (e) If we did not find an intersection node and completed the entire iteration of the second list,
                then there is no intersection between the provided lists. Hence, return null.

Complexity Analysis:
    1. Time Complexity: O(m*n), For each node in list 2 entire lists 1 are iterated. 
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
    return;
}

// utility function to check presence of intersection
node *intersectionPresent(node *head1, node *head2)
{
    node *temp2 = head2;
    while (temp2 != NULL)
    {
        node *temp1 = head1;
        while (temp1 != NULL)
        {
            // if both nodes are same
            if (temp1 == temp2)
                return temp2;

            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }

    // intersection is not present between the lists return null
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
