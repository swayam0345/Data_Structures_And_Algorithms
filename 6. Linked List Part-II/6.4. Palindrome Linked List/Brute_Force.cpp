/*
Intuition:
    ● A straightforward approach to checking if the given linked list is a palindrome or not is to temporarily
      store the values in an additional data structure. We can use a stack for this.

    ● By pushing each node onto the stack as we traverse the list, we effectively store the data values in the reverse order.

    ● Once all the nodes are stored in the stack, we traverse the linked list again comparing each node's value
      with the values popped from the top of the stack. 


Approach:
    1. Create an empty stack. This stack will be used to temporarily store the nodes from the original
       linked list as we traverse it.

    2. Traverse the linked list using a temporary variable `temp` till it reaches null. At each node,
       push the value at the current node onto the stack. 

    3. Set variable `temp` back to the head of the linked list. While the stack is not empty, compare
       the value at the temp node to the value at the top of the stack. Pop the stack and move the
       temp to the next node till it reaches the end.

       During the comparison, if at any point the values do not match, the linked list is not a
       palindrome and hence returns false.

    4. If all values match till emp reaches the end, it means that the linked list is a palindrome,
       as the values read the same way both forward and backward hence we return true.


Dry Run:
  Let take the below as inputs to our program.
                     _________   _________    _________    _________    _________
        Linked List: |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL

    (a) Iterating the linked list till NULL, and storing each value into a stack.
                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________                |_______|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL        |_______|
          head                                                                      |_______|
          temp                                                                      |___1___|

                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________                |_______|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL        |_______|
          head         temp                                                         |___2___|
                                                                                    |___1___|

                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________                |_______|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL        |___3___|
          head                     temp                                             |___2___|
                                                                                    |___1___|

                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________                |___2___|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL        |___3___|
          head                                  temp                                |___2___|
                                                                                    |___1___|
  
                                                                                    _________
                                                                                    |___1___|
        _________   _________    _________    _________    _________                |___2___|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL        |___3___|
          head                                                temp                  |___2___|
                                                                                    |___1___|

    (b) Traversing the linked list from head, comparing temp & top of stack and poping them out.
                                                                                    _________
                                                                                ┌--→|___𝟷̶___| ===> pop()
        _________   _________    _________    _________    _________            |   |___2___|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL    |   |___3___|
          head  |_______________________________________________________________|   |___2___|
          temp          As {temp} 1 = 1 {top()}, we will pop out the stack          |___1___|

                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________            ┌--→|___𝟸̶___| ===> pop()
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL    |   |___3___|
          head        temp |____________________________________________________|   |___2___|
                                            {temp} 2 = 2 {top()}                    |___1___|

                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________            ┌--→|_______|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL    |   |___𝟹̶___| ===> pop()
          head                     temp |_______________________________________|   |___2___|
                                                {temp} 3 = 3 {top()}                |___1___|

                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________            ┌--→|_______|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL    |   |_______|
          head                                  temp |__________________________|   |___𝟸̶___| ===> pop()
                                                        {temp} 2 = 2 {top()}        |___1___|

                                                                                    _________
                                                                                    |_______|
        _________   _________    _________    _________    _________            ┌--→|_______|
        |_1_|_n_| ->|_2_|_n_| -> |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> NULL    |   |_______|
          head                                              temp |______________|   |_______|
                                                                        1 = 1       |___𝟷̶___| ===> pop()

    ● Since the stack is emptied without encountering any mismatches, we can conclude that the given linked list is a palindrome.


Complexity Analysis:
    1. Time Complexity: O(N), This is because we traverse the linked list twice: once to push the values onto the stack,
                        and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.

    2. Space Complexity: O(N), We use a stack to store the values of the linked list, and in the worst case, the stack will
                         have all N values,  ie. storing the complete linked list.

*/


#include <iostream>
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

bool isPalindrome(Node *head)
{
    // Create an empty stack
    stack<int> st;
    Node *temp = head;

    // Traverse the linked list and push values onto the stack
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    // Reset the temporary pointer back to the head of the linked list
    temp = head;

    // Compare values by popping from the stack & checking against linked list nodes
    while (temp != NULL)
    {
        if (temp->data != st.top())
        {
            // If values don't match, it's not a palindrome
            return false;
        }

        // Pop the value from the stack
        st.pop();

        temp = temp->next;
    }

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
