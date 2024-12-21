/*
Intuition:
    ● The brute force approach would be to extract all the elements from both the lists into an additional array
      then sorting the array and creating a new combined linked list.

Approach:
1. Initialise an empty array and iterate through each node of the first and second linked list adding them to the array.
2. Sort the array in ascending order, using a sorting algorithm like quick sort, merge sort or the inbuilt library.
3. Create a new linked list from the sorted array and initialise a dummy node as the head of the merged linked list.
    ● Iterate through the sorted array and create a new linked list node for each array element and move to the next
      element in the sorted array.
    ● Return the next of the dummy nodes as the head of the merged sorted linked list.

Complexity Analysis:
    1. Time Complexity: O(N1 + N2) + O(N log N) + O(N), where N1 is the number of linked list nodes in the first list and
                        N2 is the number of linked list nodes in the second list and N is the total number of nodes (N1+N2).
                        Traversing both lists into the array owes O(N1 + N2), sorting the array takes O((N1+N2)*log(N1+N2))
                        and then traversing the sorted array and creating a list gives us another O(N1+N2).

    2. Space Complexity: O(N)+O(N), where N is the total number of nodes from both lists, N1 + N2. O(N) to store all the nodes
                         of both the lists in an external array and another O(N) to create a new combined list.

*/

#include <bits/stdc++.h>
using namespace std;

// Node class represents a
// node in a linked list
class Node
{
public:
    // Data stored in the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to convert a vector to a linked list
Node *convertArrToLinkedList(vector<int> &arr)
{
    // Create a dummy node to serve
    // as the head of the linked list
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for (int i = 0; i < arr.size(); i++)
    {
        // Create a new node with the vector element
        temp->next = new Node(arr[i]);
        // Move the temporary pointer
        // to the newly created node
        temp = temp->next;
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to merge two sorted linked lists
Node *sortTwoLinkedLists(Node *list1, Node *list2)
{
    vector<int> arr;
    Node *temp1 = list1;
    Node *temp2 = list2;

    // Storing elements of both lists into a vector

    // Add elements from list1 to the vector
    while (temp1 != NULL)
    {
        arr.push_back(temp1->data);
        // Move to the next node in list1
        temp1 = temp1->next;
    }

    // Add elements from list2 to the vector
    while (temp2 != NULL)
    {
        arr.push_back(temp2->data);
        // Move to the next node in list2
        temp2 = temp2->next;
    }

    // Sorting the vector in ascending order
    sort(arr.begin(), arr.end());

    // Converting the sorted vector
    // back to a linked list
    Node *head = convertArrToLinkedList(arr);

    // Return the head of the
    // merged sorted linked list
    return head;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Example Linked Lists
    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node *mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}