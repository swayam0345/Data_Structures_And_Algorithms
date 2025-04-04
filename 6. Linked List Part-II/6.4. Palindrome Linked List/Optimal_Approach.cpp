/*
Intuition;
    ● The previous approach uses O(N) additional space, which can be avoided by reversing only half of the linked list
      and comparing the first and second halves.

    ● If they match, reverse the portion that was originally reversed, and then return true else return false.

    ● To implement this in-order reversal of the second half and its comparison with the first half has to be done in phases.

    ● The first step is dividing the first and second half of the linked list by recognizing the middle node using the
      "Tortoise and Hare Algorithm".


Approach:
    1. Check if the linked list is empty or has only one node. If that’s the case, it is a palindrome by definition,
       so return true.

    2. Initialise two pointers, ‘slow’ and ‘fast’, to find the middle of the linked list using the Tortoise and Hare Algorithm.
       The ‘slow’ pointer advances by one step at a time, while the ‘fast’ pointer advances by two steps at a time.
       Continue this until the ‘fast’ pointer reaches the end of the list or is the second last on the list.
       The ‘slow’ pointer will now be in the middle of the linked list.

    3. Reverse the second half of the linked list starting from the middle (the ‘slow->next’ node). This is done by calling
       the reverse linked list function and returning the head of the new reversed linked list. Learn more about reversing
       the linked list.

    4. Create two pointers, ‘first’ and ‘second’, where ‘first’ points to the head of the linked list, and ‘second’ points
       to the new head of the reversed second half.

    5. Compare data values of nodes from both halves. If the values do not match, it means the list is not a palindrome.
       In this case, return ‘false’. Continue moving both ‘first’ and ‘second’ pointers through their respective halves,
       comparing the data values until one of them reaches the end of the list.

    6. After the comparison, reverse the second half back to its original state using the reverse linked list function and
       join back the linked list to its original state. Since all the values matched in the first half and reversed in the
       second half, return true. In case it does not match, return false.


Complexity Analysis:
    1. Time Complexity: O (N), The algorithm traverses the linked list twice, dividing it into halves. During the first traversal,
                        it reverses one-half of the list, and during the second traversal, it compares the elements of both halves.
                        As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which
                        simplifies to O(2N), ultimately representing O(N).

    2. Space Complexity: O(1), The approach uses a constant amount of additional space regardless of the size of the input linked list.
                         It doesn't allocate any new data structures that depend on the input size, resulting in a space complexity of O(1).

*/

#include <iostream>
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

// Function to reverse a linked list using the recursive approach.
// We can also use the 3-pointers approach here.
Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseLinkedList(head->next);

    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

bool isPalindrome(Node *head)
{
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL)
    {
        // It's a palindrome by definition
        return true;
    }

    // Initialize two pointers, slow and fast,
    // to find the middle of the linked list
    Node *slow = head;
    Node *fast = head;

    // Traverse the linked list to find the
    // middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL)
    {
        // Move slow pointer one step at a time
        slow = slow->next;

        // Move fast pointer two steps at a time
        fast = fast->next->next;
    }

    // Reverse the second half of the
    // linked list starting from the middle
    Node *newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    Node *first = head;

    // Pointer to the reversed second half
    Node *second = newHead;
    while (second != NULL)
    {
        // Compare data values of nodes from both halves

        // If values do not match, the list is not a palindrome
        if (first->data != second->data)
        {
            // Reverse the second half back to its original state
            reverseLinkedList(newHead);

            // Not a palindrome
            return false;
        }

        // Move the first pointer
        first = first->next;

        // Move the second pointer
        second = second->next;
    }

    // Reverse the second half
    // back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}