/*
Intuition:
    ● The previous method requires the traversal of the linked list twice. To enhance efficiency, the "Tortoise and Hare Algorithm"
      is introduced as an optimization where the middle node can be found in just one traversal.
    ● The Tortoise and Hare algorithm leverages two pointers, 'slow' and 'fast', initiated at the beginning of the linked list.
    ● The 'slow' pointer advances one node at a time, while the 'fast' pointer moves two nodes at a time.
    ● The Tortoise and Hare algorithm works because the fast-moving hare reaches the end of the list in exactly the same time it
      takes for the slow-moving tortoise to reach the middle.
    ● When the hare reaches the end, the tortoise is guaranteed to be at the middle of the list.

          Hare_______________________________________Hare_____________________________________Hare
        ______↓_______      ______________      ______↓_______      ______________      ______↓_______
        |__1__|_next_| ---> |__2__|_next_| ---> |__3__|_next_| ---> |__2__|_next_| ---> |__3__|_next_| ---> NULL
           ↑___________________↑___________________↑
        Tortoise            Tortoise            Tortoise


Algorithm:
    1. Initialise two pointers, `slow` and `fast`, to the head of the linked list. `slow` will advance one step at a time,
       while `fast` will advance two steps at a time. These pointers will move simultaneously.
    2. Traverse the linked list with the `slow` and `fast` pointers. While traversing, repeatedly move `slow` one step and
       `fast` two steps at a time.
    3. Continue this traversal until fast reaches the end of the list (i.e., fast or fast.next is null), the slow pointer
       will be at the middle of the list.

    Note:
        ● When the linked list has an odd number of nodes, fast.next ensures that the fast pointer doesn't go past the end of
          the list. In this case, fast reaches the last node, and fast.next becomes null, signalling the end of the traversal.
        ● When the linked list has an even number of nodes, fast will reach the end of the list and be null, which still signifies
          the end of the traversal.


Complexity Analysis:
    1. Time Complexity: O(N/2), The algorithm requires the 'fast' pointer to reach the end of the list which it does after approximately
                        N/2 iterations (where N is the total number of nodes).
                        Therefore, the maximum number of iterations needed to find the middle node is proportional to the number of nodes
                        in the list, making the time complexity linear, or O(N/2) ~ O(N).

    2. Space Complexity: O(1), There is constant space complexity because it uses a constant amount of extra space regardless of the size
                         of the linked list. We only use a few variables to keep track of the middle position and traverse the list, and
                         the memory required for these variables does not depend on the size of the list.

*/


#include <bits/stdc++.h>
using namespace std;


// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


// Function to find the middle node of a linked list
Node *findMiddle(Node *head)
{
    // Initialize the slow pointer to the head.
    Node *slow = head;

    // Initialize the fast pointer to the head.
    Node *fast = head;

    // Traverse the linked list using the Tortoise and Hare algorithm.
    while (fast != NULL && fast->next != NULL)
    {
        // Move slow one step.
        slow = slow->next;
        // Move fast two steps.
        fast = fast->next->next;
    }

    // Return the slow pointer, which is now at the middle node.
    return slow;
}

int main()
{
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}