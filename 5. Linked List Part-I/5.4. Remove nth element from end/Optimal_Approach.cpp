/*
Intuition:
    ● The brute force, in the worst case, has a time complexity of O(2*L), where L is the length of the linked list.
    ● Therefore, it is not the most efficient algorithm, as we are traversing the entire list twice.
    ● To enhance efficiency, we will involve two pointers, a fast pointer and a slow pointer.
    ● The fast-moving pointer will initially be exactly N nodes ahead of the slow-moving pointer.
    ● After which, both of them will move one step at a time. When the fast pointer reaches the last node, i.e.; the L-th node,
      the slow is guaranteed to be at the (L-N)th node, where L is the total length of the linked list.


Approach:
    1. Initialize two pointers, `slow` and `fast`, to the head of the linked list. Initially, only fast will move till it
       crosses N nodes, after which both of the pointers will move simultaneously.
    2. Traverse the linked list till the fast pointer reaches the last node, that is, the Lth Node, at this stage, the slow
       pointer is guaranteed to be at the (L-N)th node.
    3. Point this slow pointer to the (L-N+2)th node, effectively skipping the Nth node from the end or the (L-N+1)th node
       from the start.
    4. Finally, free up the space occupied by this to delete it.


Dry Run:
    Let's take the below as the input to our program.
            _________      _________      _________      _________      _________
    List -  |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_5_|_n_| ---> NULL
    N = 3

    ➤ Initially:
            fast = head;
            slow = head;
        _________      _________      _________      _________      _________
        |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_5_|_n_| ---> NULL
         ↑     ↑
        slow   fast
      pointer pointer

    ➤ Iterating fast pointer till 3 nodes:
        Traverse fast pointer till it crosses `N` (i.e. 3) nodes.
            for(i = 0; i < N; i++)
                fast = fast->next;
            _________      _________      _________      _________      _________
            |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_5_|_n_| ---> NULL
             ↑     |________________________________________↑
           slow   fast

    ➤ Iterating both slow & fast pointer:
        Traverse both slow & fast pointer till fast->next reaches NULL.
            while(fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            _________      _________      _________      _________      _________
            |_1_|_n_| ---> |_2_|_n_| ---> |_3_|_n_| ---> |_4_|_n_| ---> |_5_|_n_| ---> NULL
                |______________↑                             |______________↑
              slow                                          fast
        
        The slow pointer will now be positioned one step before the Nth element from the end.

    ➤ Deleting the Nth node from end:
        delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
                                        ________________
            _________      _________    ↑ _________    ↓  _________      _________
            |_1_|_n_| ---> |_2_|_n_| ---- |_3_|_n_| ----> |_4_|_n_| ---> |_5_|_n_| ---> NULL
                               ↑              |                              ↑
                             slow             ↓                             fast
                                        Delete Nth node
                                          from the end
 
    ➤ Return the `head`, with the updated linked list.
        return head;
            _________      _________      _________      _________
            |_1_|_n_| ---> |_2_|_n_| ---> |_4_|_n_| ---> |_5_|_n_| ---> NULL


Complexity Analysis:
    1. Time Complexity: O(N), since the fast pointer will traverse the entire linked list,
                        where N is the length of the linked list.

    2, Space Complexity: O(1), as we have not used any extra space.

*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

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
    // Create two pointers, fastp and slowp
    Node *fastp = head;
    Node *slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL, the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL)
    {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node *delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
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

    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}
