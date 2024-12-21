/*
Intuition:
    ● A straightforward approach to reversing a singly linked list requires an additional data structure to temporarily store the values.
    ● We can use a stack for this. By pushing each node onto the stack as we move through the list, we effectively reverse the order of
      the nodes.
    ● Once all the nodes are stored in the stack, we rebuild the reversed linked list by popping nodes from the stack and assigning them
      to the nodes.
    ● The result is a new linked list with the elements in the opposite order of the original list.


Approach:
    1. Create an empty stack. This stack will be used to temporarily store the nodes from the original linked list as we traverse it.
    2. Traverse the linked list using a temporary variable `temp` till it reaches null. At each node, push the value at the current
       node onto the stack.
    3. Set variable `temp` back to the head of the linked list. While the stack is not empty, set the value at the temp node to the
       value at the top of the stack. Pop the stack and move temp to the next node till it reaches null.
    4. Return the new reversed linked list.


Complexity Analysis:
    1. Time Complexity: O(2N), This is because we traverse the linked list twice:
                        once to push the values onto the stack, and once to pop the values and update the linked list.
                        Both traversals take O(N) time, hence time complexity  O(2N) ~ O(N).

    2. Space Complexity: O(N), We are using a stack to store the values of the linked list, and in the worst case,
                         the stack will have all N values,  ie. storing the complete linked list. 

*/


#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class Node {
  public:
    int data;
    Node* next;

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1)
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


Node* reverseLinkedList(Node* head)
{
    // Create a temporary pointer to traverse the linked list
    Node* temp = head;

    // Create a stack to temporarily store the data values
    stack<int> st;

    // Step 1: Push the values of the linked list onto the stack
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    // Reset the temporary pointer to the head of the linked list
    temp = head;

    // Step 2: Pop values from the stack and update the linked list
    while (temp != nullptr)
    {
        // Set the current node's data to the value at the top of the stack
        temp->data = st.top();

        // Pop the top element from the stack
        st.pop();

        // Move to the next node in the linked list
        temp = temp->next;
    }

    // Return the new head of the reversed linked list
    return head;
}


void printLinkedList(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    // Create a linked list with values 1, 2, 3, 4 and 5.
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
