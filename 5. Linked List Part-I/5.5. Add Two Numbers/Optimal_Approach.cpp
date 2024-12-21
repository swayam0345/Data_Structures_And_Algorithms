/*
Intuition:
    ● Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of the list,
      which contains the least significant digit.
    ● We don't need to reverse the input list and perform addition operation. Because mathematically we start addition
      from the right hand side. And the input is already present in that format.
    ● Also the output is expected to be in reverse order of the addition result.

Approach:
    1. Initialize Data Structures:
        ● Define a Node structure to represent linked list nodes with data (digit value) and
          a next pointer (link to the next node).
        ● Create pointers `sumList` (head of the result list) and `tail` (to maintain the tail for
          efficient appending).
        ● Initialize variables `sum` (to store the sum of corresponding digits) and `carry` (to store
          carry-over between digit additions).

    2. Iterate Until All Digits and Carry Are Processed:
        ● Use a while loop that continues until all nodes of both lists (list1 and list2) are
          processed and any remaining non-zero carry is added.

    3. Extract Digit Values:
        ● Retrieve the digit value from the current node of list1 (val1) or use 0 if list1 is nullptr.
        ● Retrieve the digit value from the current node of list2 (val2) or use 0 if list2 is nullptr.

    4. Compute Sum and Carry:
        ● Calculate the total sum of val1, val2, and carry.
        ● Compute the new carry as (sum / 10) (integer division).
        ● Extract the single-digit result for the current position using (sum % 10).

    5. Create a New Node for the Current Digit:
        ● Create a new Node to store the single-digit result.
        ● If sumList is nullptr (this is the first digit):
            ➤ Initialize sumList with the new node.
            ➤ Set tail to point to this node.

        ● Otherwise:
            ➤ Append the new node to the tail's next.
            ➤ Update tail to point to the new node.

    6. Advance the Input Lists:
        ● Move the list1 pointer to its next node if it's not nullptr.
        ● Move the list2 pointer to its next node if it's not nullptr.

    7. Handle Remaining Carry:
        ● If a carry exists after processing both lists, it will be added as an additional
          node in the result list.

    8. Result:
        ● The `sumList` now contains the resultant sum represented as a linked list with digits
          in reverse order.


Complexity Analysis:
    1. Time Complexity: O(max(m, n)), where m and n represent the length of l1 and l2 respectively,
                        the while loop iterates at most max(m, n) times.

    2. Space Complexity: O(max(m, n)), The length of the new list is at most (max(m, n) + 1), because at the
                         end of the addition operation a carry might remain. Say l1 = 9 and l2 = 8, then
                         our sumList will be 1 -> 7. So, here we will require (max(1, 1) + 1) memory.

*/

#include <bits/stdc++.h>
using namespace std;


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


void printLL(Node *head)
{
    cout << "\t" << "[ ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "]";
}


Node* sumOfTwoLinkedList(Node* list1, Node* list2)
{
    Node *sumList = nullptr;
    Node* tail = nullptr;
    int sum = 0;
    int carry = 0;

    while((list1 != nullptr) || (list2 != nullptr) || (carry != 0))
    {
        int val1 = (list1 != nullptr) ? list1->data : 0;    // Value from list1 or 0 if list1 is null
        int val2 = (list2 != nullptr) ? list2->data : 0;    // Value from list2 or 0 if list2 is null

        sum = val1 + val2 + carry;                          // Calculate the sum
        carry = sum / 10;                                   // Calculate the carry for the next digit
        sum = sum % 10;                                     // Extract the single digit for the current node

        // Create a new node for the sum and add it to the list
        Node *newNode = new Node(sum);
        if (sumList == nullptr)
        {
            sumList = newNode;                              // Initialize head if this is the first node
            tail = newNode;                                 // Tail is the same as head for the first node
        }
        else
        {
            tail->next = newNode;                           // Append the new node at the end
            tail = newNode;                                 // Update the tail pointer
        }

        // Advance the input lists if not null
        if (list1 != nullptr)
            list1 = list1->next;
        if (list2 != nullptr)
            list2 = list2->next;
    }

    return sumList;
}


int main()
{
    /* Second Sample Input */
/*
    Node *list1 = new Node(2);
    list1->next = new Node(4);
    list1->next->next = new Node(9);

    Node *list2 = new Node(5);
    list2->next = new Node(6);
    list2->next->next = new Node(4);
*/

    /* Second Sample Input */
    Node *list1 = new Node(9);
    list1->next = new Node(9);
    list1->next->next = new Node(9);
    list1->next->next->next = new Node(9);

    Node *list2 = new Node(9);
    list2->next = new Node(9);
    list2->next->next = new Node(9);
    list2->next->next->next = new Node(9);
    list2->next->next->next->next = new Node(9);
    list2->next->next->next->next->next = new Node(9);
    list2->next->next->next->next->next->next = new Node(9);

    /* Printing the input linked lists. */
    printLL(list1);
    cout << endl << "+";
    printLL(list2);
    cout << endl << "\t" << "-------------------" << endl;

    Node* resultList = sumOfTwoLinkedList(list1, list2);
    /* Print the output sum linked list. */
    printLL(resultList);

    return 0;
}