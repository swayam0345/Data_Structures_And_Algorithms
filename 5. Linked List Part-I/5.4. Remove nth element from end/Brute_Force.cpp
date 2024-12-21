/*
Intuition:
    ● The simplest way to delete the Nth node from the end is to delete the (L-N+1)th node from the start of the linked list,
      where L is the total length of the linked list. 
    ● Therefore, this problem can be broken down into two sub-problems:
        (a) The first part involves the calculation of the length of the linked list.
        (b) The second part involves the deletion of the (L-N+1)th node from the start of the linked list.
    ● There are two edge cases to consider:
        (a) If N equals 1, this means we have to delete the tail of the linked list.
        (b) If N equals the length of the linked list, we have to delete the head of the linked list.


Algorithm
    1. Initialize a temp pointer that will be used to traverse the list.
    2. Create a cnt variable and initialize it to 0. Traverse the linked list, and at each node, increment cnt.
       Finally, when the pointer reaches NULL, return cnt, which contains the total length of the linked list.
    3. Now, after knowing the length of the linked list, the first sub-problem is solved. To solve the second sub-problem,
       we will follow the steps that we used to delete the Kth node of the linked list.
    4. To delete the (L-N+1)th node of the linked list, create a new temp pointer to the head. Initialize a variable res to L-N,
       and start iterating the linked list while decrementing res at each node. Once res equals 0, we know that temp will be
       pointing to the (L-N)th node, therefore, stop the traversal.
    5. To create a new link, point the (L-N)th node to the (L-N+2)th node of the linked list, effectively skipping the
       (L-N+1)th node.
    6. Finally, free up the memory being occupied by the (L-N+1)th node, thus deleting this node.


Complexity Analysis:
    1. Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the
                        (L-N)th node of the linked list, where L is the total length of the list.
    2. Space Complexity:  O(1), as we have not used any extra space.

*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor for Node with data and next node
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor for Node with
    // only data (next set to nullptr)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to delete the Nth node
// from the end of the linked list
Node *DeleteNthNodefromEnd(Node *head, int N)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of nodes, delete the head
    if (N == cnt)
    {
        Node *newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - N;  // We aren't adding 1 to res, because we are considering 0th indexing.
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}
