/*
Intuition:
    ● To transform the given linked list into a single level sorted list ensuring that the nodes are arranged in an
      ascending order, we initialise an array to temporarily hold the extracted nodes during the traversal.

    ● We iterate over the array by first going over the top-level next pointers of the linked list then accessing each
      node within its child pointers adding all to the array.

    ● Then the array is sorted to arrange all values sequentially and a new linked list from that array is created and returned.


Approach:
    1. Initialise an empty array to store the data extracted during the traversal.

    2. Start traversing through the top-level ‘next’ pointers of the linked list and for each node accessed by the
       ‘next’ pointer, traverse its ‘child’ nodes. 
        ● Iterate all the nodes until reaching the end of the child pointer list appending each node’s value to the array.
        ● Move to the next primary node and repeat the process of traversing the child nodes.

    3. Sort the array to arrange its collected node data in ascending order.

    4. Create a new linked list from the sorted array and return the flattened linked list.


Complexity Analysis:
    1. Time Complexity: O(N*M) + O(N*M log(N*M)) + O(N*M), where N is the length of the linked list along the next pointer
                        and M is the length of the linked list along the child pointer.

        ● O(N*M) - as we traverse through all the elements, iterating through ‘N’ nodes along the next pointer and ‘M’ nodes
                   along the child pointer.
        ● O(N*M log(N*M)) - as we sort the array containing N*M (total) elements.
        ● O(N*M) - as we reconstruct the linked list from the sorted array by iterating over the N*M elements of the array.

    2. Space Complexity: O(N*M) + O(N*M), where N is the length of the linked list along the next pointer and M is the
                         length of the linked list along the child pointer.

        ● O(N*M) - for storing all the elements in an additional array for sorting.
        ● O(N*M) - to reconstruct the linked list from the array after sorting

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

// Function to convert a vector to a linked list
Node *convertArrToLinkedList(vector<int> &arr)
{
    // Create a dummy node to serve as
    // the head of the linked list
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for (int i = 0; i < arr.size(); i++)
    {
        // Create a new node
        // with the vector element
        temp->child = new Node(arr[i]);
        // Move the temporary pointer
        // to the newly created node
        temp = temp->child;
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->child;
}

// Function to flatten a linked list with child pointers
Node *flattenLinkedList(Node *head)
{
    vector<int> arr;

    // Traverse through the linked list
    while (head != nullptr)
    {
        // Traverse through the child
        // nodes of each head node
        Node *t2 = head;
        while (t2 != nullptr)
        {
            // Store each node's data in the array
            arr.push_back(t2->data);
            // Move to the next child node
            t2 = t2->child;
        }
        // Move to the next head node
        head = head->next;
    }

    // Sort the array containing
    // node values in ascending order
    sort(arr.begin(), arr.end());

    // Convert the sorted array
    // back to a linked list
    return convertArrToLinkedList(arr);
}

// Print the linked list by traversing through child pointers
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Print the linked list in a grid-like structure
void printOriginalLinkedList(Node *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->data;

        // If child exists, recursively
        // print it with indentation
        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars
        // for each level in the grid
        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
            {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main()
{
    // Create a linked list with child pointers
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node *flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
