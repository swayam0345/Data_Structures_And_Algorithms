/*
Intuition:
    ● The previous approach uses O(N) addition space which can be avoided by interchanging the connecting links of the
      nodes of the linked list in place.
    ● The main idea is to flip the order of connections in the linked list, which changes the direction of the arrows.
      When this happens, the last element becomes the new first element of the list.
    ● This in-place reversal allows us to efficiently transform the original list without using extra space.


Approach:
    1. Initialise a ‘temp’ pointer at the head of the linked list. This pointer will be used to traverse the linked list.
       And initialize the pointer ‘prev’ to ‘NULL’ to keep track of the previous node. This will be used to reverse the
       direction of the ‘next’ pointers.

        ______________      ______________      ______________      ______________
        |__1__|_next_| ---> |__3__|_next_| ---> |__2__|_next_| ---> |__5__|_next_| ---> NULL
   𝐍𝐔𝐋𝐋     𝐇𝐞𝐚𝐝
   𝘱𝘳𝘦𝘷      𝘵𝘦𝘮𝘱

    2. We will have a ‘front’ pointer which will keep track of the next element (temp->next) and move `temp` forward in the linked list.
        front = temp->next

    3. Traverse the entire linked list by moving through each node using the 'temp' pointer until it reaches the end (marked as 'NULL').
        ➤ At each iteration within the traversal;
            (a) Save the reference to the next node that 'temp' is pointing to in a variable called 'front'.
                This helps retain the link to the subsequent node before altering the 'next' pointer.
                ______________      ______________      ______________
                |__1__|_next_| ---> |__3__|_next_| ---> |__2__|_next_| --->
                    𝘱𝘳𝘦𝘷                𝘵𝘦𝘮𝘱                𝘧𝘳𝘰𝘯𝘵

            (b) Reverse the direction of the ‘next’ pointer of the current node (pointed to by ‘temp’) to
                point to the ‘prev’ node. This effectively reversed the direction of the linked list, making
                the current node point to the previous node.
                ______________   <---    ______________      ______________
                |__1__|_next_|   --->    |__3__|_next_| ---> |__2__|_next_| --->
                    𝘱𝘳𝘦𝘷                      𝘵𝘦𝘮𝘱                𝘧𝘳𝘰𝘯𝘵

            (c) Move the ‘prev’ pointer to the current node. This sets up the ‘prev’ pointer for the next iteration of the loop.
            (d) Move the ‘temp’ pointer to the ‘front’ node. This advances the traversal to the next node in the original order.
                ______________      ______________      ______________
                |__1__|_next_| <--- |__3__|_next_| ---> |__2__|_next_| --->
                                        𝘱𝘳𝘦𝘷                    𝘵𝘦𝘮𝘱

    4. Keep traversing through the linked list using the 'temp' pointer until it reaches the end, thereby reversing the entire list.
       Once the 'temp' pointer reaches the end, return the new head of the reversed linked list, which is now indicated by the 'prev'
       pointer. This 'prev' pointer becomes the first node in the newly reversed list.


Dry Run:
  Let take the below linked list as input to our program.
        ______________      ______________      ______________      ______________
        |__1__|_next_| ---> |__3__|_next_| ---> |__2__|_next_| ---> |__5__|_next_| ---> NULL

    Iteration-0:
        temp = head
        prev = NULL
                ______________      ______________      ______________      ______________
        NULL    |__1__|_next_| ---> |__3__|_next_| ---> |__2__|_next_| ---> |__5__|_next_| ---> NULL
        𝘱𝘳𝘦𝘷        𝘵𝘦𝘮𝘱

    Iteration-1:
        front = temp->next = 3
        temp->next = prev = NULL
        prev = temp = 1
        temp = front = 3
                  ______________    ______________      ______________      ______________
        NULL <--- |_next_|__1__|    |__3__|_next_| ---> |__2__|_next_| ---> |__5__|_next_| ---> NULL
        𝘱𝘳𝘦𝘷           𝘵𝘦𝘮𝘱             𝘧𝘳𝘰𝘯𝘵
         |_____________↑  |______________↑

    Iteration-2:
        front = temp->next = 2
        temp->next = prev = 1
        prev = temp = 3
        temp = front = 2
                  ______________      ______________      ______________      ______________
        NULL <--- |_next_|__1__| <--- |_next_|__3__|      |__2__|_next_| ---> |__5__|_next_| ---> NULL
                       𝘱𝘳𝘦𝘷               𝘵𝘦𝘮𝘱                 𝘧𝘳𝘰𝘯𝘵
                        |_________________↑  |__________________↑

    Iteration-3:
        front = temp->next = 5
        temp->next = prev = 3
        prev = temp = 2
        temp = front = 5
                  ______________      ______________      ______________      ______________
        NULL <--- |_next_|__1__| <--- |_next_|__3__| <--- |_next_|__2__|      |__5__|_next_| ---> NULL
                                          𝘱𝘳𝘦𝘷                 𝘵𝘦𝘮𝘱                𝘧𝘳𝘰𝘯𝘵
                                            |__________________↑  |_________________↑

    Iteration-4:
        front = temp->next = NULL
        temp->next = prev = 2
        prev = temp = 5
        temp = front = NULL
                  ______________      ______________      ______________      ______________
        NULL <--- |_next_|__1__| <--- |_next_|__3__| <--- |_next_|__2__| <--- |_next_|__5__|      NULL
                                                                𝘱𝘳𝘦𝘷              𝘵𝘦𝘮𝘱            𝘧𝘳𝘰𝘯𝘵
                                                                  |_______________↑  |______________↑


    ● The iteration will stop here as temp will be NULL now. Finally we will have our reversed linked list in `prev`.
                  ______________      ______________      ______________      ______________
        NULL <--- |_next_|__1__| <--- |_next_|__3__| <--- |_next_|__2__| <--- |_next_|__5__|      NULL
                                                                                    𝘱𝘳𝘦𝘷        𝘵𝘦𝘮𝘱/𝘧𝘳𝘰𝘯𝘵
                                                                  

Complexity Analysis:
    1. Time Complexity: O(N), The code traverses the entire linked list once, where 'n' is the number of nodes in the list.
                        This traversal has a linear time complexity, O(n).

    2. Space Complexity: O(1), The code uses only a constant amount of additional space, regardless of the linked list's length.
                         This is achieved by using three pointers (𝘱𝘳𝘦𝘷, 𝘵𝘦𝘮𝘱 & 𝘧𝘳𝘰𝘯𝘵) to reverse the list without any significant
                         extra memory usage, resulting in constant space complexity, O(1).

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

    // Constructor with both data and next node as parameters
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


// Function to reverse a linked list using the 3-pointer approach
Node *reverseLinkedList(Node *head)
{
    // Initialize'temp' at head of linked list
    Node *temp = head;

    // Initialize pointer 'prev' to NULL, representing the previous node
    Node *prev = NULL;

    // Traverse the list, continue till 'temp' reaches the end (NULL)
    while (temp != NULL)
    {
        // Store the next node in 'front' to preserve the reference of temp
        Node *front = temp->next;

        // Reverse the direction of the current node's 'next' pointer to point to 'prev'
        temp->next = prev;

        // Move 'prev' to the current node for the next iteration
        prev = temp;

        // Move 'temp' to the 'front' node advancing the list traversal
        temp = front;
    }

    // Return the new head of the reversed linked list, i.e; `prev`
    return prev;
}


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
    // Create a linked list with values 1, 3, 2, 4, and 5
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the input linked list
    head = reverseLinkedList(head);

    // Print the output reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
