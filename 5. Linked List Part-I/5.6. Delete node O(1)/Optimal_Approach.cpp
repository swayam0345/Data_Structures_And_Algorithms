/*
Intuition:
    ● We are given access to Nodes that we have to delete from the linked list. So, whatever operation we want to do in the
      linked list, we can operate in the right part of the linked list from the Node to be deleted.
    ● The approach is to copy the next Node’s value in the deleted Node. Then, link Node to next of next Node.
    ● This does not delete that Node but indirectly it removes that Node from the linked list.


Algorithm Explanation:
    1. Create a linked list with nodes containing the given data.
    2. Print the linked list before performing the deletion operation.
    3. Find the node to delete by traversing the list using the getNode function.
        ● This function finds the first node matching the given value.
    4. Delete the target node using the deleteNode function:
        ● Copy the data from the next node to the target node.
        ● Bypass the next node by updating the "next" pointer of the target node.
        ● This approach works because we cannot directly delete a node without knowing its previous node in a singly linked list.
    5. Print the modified linked list to verify the deletion.


Complexity Analysis:
    1. Time Complexity: O(1)
        Reason: It is a two-step process that can be obtained in constant time.

    2. Space Complexity: O(1)
        Reason: No extra data structure is used.

*/

#include <iostream>
using namespace std;

class Node
{
public:
    // Data stored in the Node
    int data;

    // Pointer to the next Node in the list
    Node *next;

    // Constructor with both data and next Node as parameters
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};


// Function to get a reference to the node to delete
Node* getNode(Node* delNode, int val)
{
    // Traverse the list until we find the node with the specified value
    while (delNode->data != val)
        delNode = delNode->next;
    
    return delNode;
}

// Function to delete a node from the linked list
void deleteNode(Node *t)
{
    t->data = t->next->data;    // Copy the data of the next node into the current node
    t->next = t->next->next;    // Update the current node's next pointer to skip the next node
}

// Function to print the linked list
void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data << "\n";
}


int main()
{
    // Creating a linked list with nodes containing data 1, 4, 2, 3
    Node *list = new Node(1);
    list->next = new Node(4);
    list->next->next = new Node(2);
    list->next->next->next = new Node(3);

    // Printing the initial linked list
    cout << "Given Linked List: ";
    printList(list);

    // Finding the node to delete (node with value 2)
    Node* removeNode = getNode(list, 2);

    // Deleting the node using the deleteNode function
    deleteNode(removeNode);

    // Printing the linked list after deletion
    cout << "Linked List after deletion: ";
    printList(list);

    return 0;
}
