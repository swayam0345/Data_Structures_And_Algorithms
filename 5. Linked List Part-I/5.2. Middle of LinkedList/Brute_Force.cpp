/*
Intuition:
    Using the brute force approach, we can find the middle node of a linked list by traversing the linked list and finding the total
    number of nodes as `count`. Then we reset the traversal pointer and traverse to the node at the [count/2 + 1]th position.


Approach:
    1. Initialise pointer temp to the head of the linked list and a variable to count to hold the number of nodes in the linked list.
       Using temp traverse the linked list, increasing the value of count by one at each node till temp becomes null.
       The final value of count will represent the length of the linked list.
    2. Calculate mid as count/2 + 1 where count is the length of the linked list. Mid represents the position of the middle node.
    3. Reset temp pointer back to the head and traverse the list by iteratively moving temp mid number of times. The node pointed to
       by current after this traversal is the middle node of the linked list.


Complexity Analysis:
    1. Time Complexity: O(N+N/2) The code traverses the entire linked list once and half times and then only half in the second iteration,
                        first to count the number of nodes then then again to get to the middle node. Therefore, the time complexity is
                        linear, O(N + N/2) ~ O(N).

    2. Space Complexity : O(1) There is constant space complexity because it uses a constant amount of extra space regardless of the
                          size of the linked list. We only use a few variables to keep track of the middle position and traverse the list,
                          and the memory required for these variables does not depend on the size of the list.

*/


#include <bits/stdc++.h>
using namespace std;


// Node class represents a node in a linked list
class Node
{
public:
    // Data stored in the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};


// Function to find the middle
// node of a linked list
Node *findMiddle(Node *head)
{
    // If the list is empty or has only
    // one element, return the head as
    // it's the middle.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int count = 0;

    // Count the number of nodes in the linked list.
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Calculate the position of the middle node.
    int mid = count / 2 + 1;
    temp = head;

    // Traverse to the middle node by moving
    // temp to the middle position.
    while (temp != NULL)
    {
        mid = mid - 1;

        // Check if the middle
        // position is reached.
        if (mid == 0)
        {
            // break out of the loop
            // to return temp
            break;
        }
        // Move temp ahead
        temp = temp->next;
    }

    // Return the middle node.
    return temp;
}


int main()
{
    // Creating a sample linked list:
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node *middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value of the i/p linked list is: " << middleNode->data << endl;

    return 0;
}
