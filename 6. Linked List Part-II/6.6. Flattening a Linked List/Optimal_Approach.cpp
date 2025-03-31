/*
Intuition:
    ● The time and space complexity of the previous approach can be optimised as we have not yet leveraged
      the given property that the child linked lists are sorted.
    
    ● We can eliminate the additional space and time complexity generated by sorting by using these sorted
      vertical linked lists.

    ● Instead of collecting all node values into an array and then sorting them, we can merge these pre-sorted
      lists directly during the traversal, eliminating the need for additional sorting steps.
    
    ● This merge operation can be performed efficiently in place without allocating extra space for the combined
      linked list.

    ● The base case ensures the termination of the recursion when there's either no list or only a single node
      remaining. The recursive function then handles the merging of the remaining lists after recursive flattening,
      creating a sorted flattened linked list.


Approach:
    1. Establish Base Case Conditions Check if the base case conditions are met, return the head if it is null or
       has no next pointer to head as there’s no further flattening or merging required.

        ➤ Base Case:
            ● If the head is null, indicating the end of the list, it is already flattened or there are no further
              nodes. Return the head as it is.
            ● Similarly, if there's no next node, meaning there's only one node left in the list, return the head as
              it is since it's already flattened.
        
            flattenLinkedList[NULL] = NULL
                                _____                       _____
                                |    _______________            |       _______________
                                |    |_c_|__5__|_n_| --→ NULL   |       |_c_|__5__|_n_| --→ NULL
                                |    __↓____________            |       __↓____________
                                |    |_c_|__6__|_n_|            |       |_c_|__6__|_n_|
            flattenLinkedList   |    __↓____________            |  =    __↓____________
                                |    |_c_|__8__|_n_|            |       |_c_|__8__|_n_|
                                |      ↓                        |         ↓
                                |     NULL                      |        NULL
                                |____                       ____|


    2. Recursively Merge the List:
        ● Initiate the recursive flattening process by calling `flattenLinkedList` on the next node (`head -> next`).
        ● The result of this recursive call is the head of the flattened and merged linked list.

        ➤ Recursive Function: The core of the algorithm lies in implementing a recursive function responsible for
                               flattening the linked list. The function operates based on the principle that;

            ● If the base conditions are not met, the function invokes itself recursively, by calling the next node.
              This recursion continues until it reaches the base case, gradually flattening the linked list and merging
              the resultant with the previous node.
            ● Following the recursion, the function returns the merged head of the new flattened linked list. This head
              marks the new head of the merged list starting from the end, which will now be merged with the present head.


    3. Merge Operations:
        ● We will use the "merging two sorted linked lists" approach to merge the sorted vertical lists together.
        ● Inside the recursive call, we will call the merge function right after the recursive operation. This function
          will take care of the merging of any two sorted lists based on their data values.
        ● The merged list is updated in the head, which is then returned as the result of the flattening process.



Dry Run:
    Let's consider the following example.
    _______________     _______________     _______________     _______________     _______________
    |_c_|__3__|_n_| --→ |_c_|__2__|_n_| --→ |_c_|__1__|_n_| --→ |_c_|__4__|_n_| --→ |_c_|__5__|_n_| --→ NULL
      |                   |                   |                   |                   |
      ↓            _______↓________    _______↓_______     _______↓_______     _______↓_______
    NULL           |_c_|__10__|_n_|    |_c_|__7__|_n_|     |_c_|__9__|_n_|     |_c_|__6__|_n_|
                     |                   |                   |                   |
                     ↓            _______↓________           ↓            _______↓_______
                    NULL          |_c_|__11__|_n_|          NULL          |_c_|__8__|_n_|
                                    |                                       |
                             _______↓________                               ↓
                             |_c_|__12__|_n_|                             NULL
                               |
                               ↓
                             NULL


    ➤ Initialization:
        For the simplicity of iteration, let's name each vertical linked list as; L1, L2, L3, L4 & L5.

        ________L1________   ________L2________   ________L3________    ________L4________    ________L5________
        |  _______next_  |   |  _______next_  |   |  _______next_  |    |  _______next_  |    |  _______next_  |
        |  |__3__|____|--|---|-→|__2__|____|--|---|-→|__1__|____|--|----|-→|__4__|____|--|----|-→|__5__|____|--|----→ NULL
        |     | child    |   |    | child     |   |     | child    |    |     | child    |    |     | child    |
        |     ↓          |   | ___↓_________  |   |  ___↓________  |    |  ___↓________  |    |  ___↓________  |
        |    NULL        |   | |__10__|____|  |   |  |__7__|____|  |    |  |__9__|____|  |    |  |__6__|____|  |
        |________________|   |    |           |   |     | child    |    |     | child    |    |     | child    |
                             |    ↓           |   |  ___↓_________ |    |     ↓          |    |  ___↓________  |
                             |  NULL          |   |  |__11__|____| |    |    NULL        |    |  |__8__|____|  |
                             |________________|   |     | child    |    |________________|    |     | child    |
                                                  |  ___↓_________ |                          |     ↓          |
                                                  |  |__12__|____| |                          |   NULL         |
                                                  |     | child    |                          |________________|
                                                  |     ↓          |
                                                  |   NULL         |
                                                  |________________|


    ➤ Recursive iteration:
        flattenLinkedList(L1)	flattenLinkedList(L2)	flattenLinkedList(L3)	flattenLinkedList(L4)	flattenLinkedList(L5)
        ________L1________      ________L2________      ________L3________    	________L4________    	________L5________
        |  _______next_  |      |  _______next_  |      |  _______next_  |    	|  _______next_  |    	|  _______next_  |
        |  |__3__|____|--|------|-→|__2__|____|--|------|-→|__1__|____|--|------|-→|__4__|____|--|------|-→|__5__|____|--|----→ NULL
        |     | child    |   	|    | child     |   	|     | child    |    	|     | child    |    	|     | child    |
        |     ↓          |   	| ___↓_________  |   	|  ___↓________  |    	|  ___↓________  |    	|  ___↓________  |
        |    NULL        |   	| |__10__|____|  |   	|  |__7__|____|  |    	|  |__9__|____|  |    	|  |__6__|____|  |
        |________________|   	|    |           |   	|     | child    |    	|     | child    |    	|     | child    |
                                |    ↓           |   	|  ___↓_________ |    	|     ↓          |    	|  ___↓________  |
                                |  NULL          |   	|  |__11__|____| |    	|    NULL        |    	|  |__8__|____|  |
                                |________________|   	|     | child    |    	|________________|    	|     | child    |
                                                        |  ___↓_________ |                          	|     ↓          |
                                                        |  |__12__|____| |                          	|   NULL         |
                                                        |     | child    |                          	|________________|
                                                        |     ↓          |
                                                        |   NULL         |
                                                        |________________|

        ● Once we reach base condition of recursion at `flattenLinkedList(L5)`, we can call the mergeLinkedList to merge each
          of the vertical linked list and flatten it.

                  𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐨𝐧 𝐒𝐭𝐚𝐜𝐤
            |                         |
            |_________________________|
            |  flattenLinkedList(L5)  | -----------→ Base Case
            |_________________________|
            |  flattenLinkedList(L4)  |
            |_________________________|
            |  flattenLinkedList(L3)  |
            |_________________________|
            |  flattenLinkedList(L2)  |
            |_________________________|
            |  flattenLinkedList(L1)  |
            |_________________________|


    ➤ Merge iteration:
        Once the recursion reaches it's base case, we will start merging the vertical list, by comparing their child node value.

            |                         |
            |_________________________|
            |  flattenLinkedList(L5)  | ____
            |_________________________|    |__merge(4, 5)__
            |  flattenLinkedList(L4)  | ___|              |
            |_________________________|                   |__merge(1, 4)__
            |  flattenLinkedList(L3)  | __________________|              |
            |_________________________|                                  |__merge(2, 1)__
            |  flattenLinkedList(L2)  | _________________________________|              |
            |_________________________|                                                 |__merge(3, 1)__ = Result
            |  flattenLinkedList(L1)  |_________________________________________________|
            |_________________________|


        ● Iteration-1: We will return the `L5` as it is, because it's the base case.

            ________L5________
            |  _______next_  |
            |-→|__5__|____|--|----→ NULL
            |     | child    |
            |  ___↓________  |
            |  |__6__|____|  |
            |     | child    |
            |  ___↓________  |
            |  |__8__|____|  |
            |     | child    |
            |     ↓          |
            |   NULL         |
            |________________|

        ● Iteration-2:
            mergedHead = 5  // return from base case
            head = 4        // Current Head
            mergeSortedLinkedList(head, mergeHead) = mergeSortedLinkedList(4, 5)
            t1 = 4
            t2 = 5                                              dummyNode
                                                                ________next_
                                                                |__-1__|____|
        ________t1________  	   ________t2________               | Child
        |  _______next_  |  	   |  _______next_  |           ____↓_______
        |  |__4__|____|  |    	   |  |__5__|____|  |           |__4__|____|
        |     | child    |  	   |     | child    |               | Child
        |  ___↓________  |  	   |  ___↓________  |           ____↓_______
        |  |__9__|____|  |  	   |  |__6__|____|  |           |__5__|____|
        |     | child    | merge() |     | child    |               | Child
        |     ↓          |  	   |  ___↓________  |     =     ____↓_______
        |    NULL        |  	   |  |__8__|____|  |           |__6__|____|
        |________________|  	   |     | child    |               | Child
                                   |     ↓          |           ____↓_______
                                   |   NULL         |           |__8__|____|
                                   |________________|               | Child
                                                                ____↓_______
                                                                |__9__|____|
                                                                    | Child
                                                                    ↓
                                                                   NULL

        ● Iteration-3:
            mergedHead = 4  // Node returned by mergeSortedLinkedList from the above iteration.
            head = 1        // Current Head
            mergeSortedLinkedList(head, mergeHead) = mergeSortedLinkedList(1, 4)
            t1  = 1
            t2  = 4
                                                                ________next_
                                                                |__-1__|____|
                                                                    | Child
                                                                ____↓_______
                                                                |__1__|____|
                                                                    | Child
        ________t1________           ________t2________         ____↓_______
        |  _______next_  |           |  _______next_  |         |__4__|____|
        |  |__1__|____|  |           |  |__4__|____|  |             | Child
        |     | child    |           |     | child    |         ____↓_______
        |  ___↓________  |           |  ___↓________  |         |__5__|____|
        |  |__7__|____|  |           |  |__5__|____|  |             | Child
        |     | child    |           |     | child    |         ____↓_______
        |  ___↓_________ |           |  ___↓________  |         |__6__|____|
        |  |__11__|____| |  merge()  |  |__6__|____|  |             | Child
        |     | child    |           |     | child    |  =      ____↓_______
        |  ___↓_________ |           |  ___↓________  |         |__7__|____|
        |  |__12__|____| |           |  |__8__|____|  |             | Child
        |     | child    |           |     | child    |         ____↓_______
        |     ↓          |           |  ___↓________  |         |__8__|____|
        |   NULL         |           |  |__9__|____|  |             | Child
        |________________|           |     |          |         ____↓_______
                                     |     ↓          |         |__9__|____|
                                     |   NULL         |             | Child
                                     |________________|         ____↓________
                                                                |__11__|____|
                                                                    | Child
                                                                ____↓________
                                                                |__12__|____|
                                                                    | Child
                                                                    ↓
                                                                   NULL

        ● Iteration-4:
            mergedHead = 2  // Node returned by mergeSortedLinkedList from the above iteration.
            head = 1        // Current Head
            mergeSortedLinkedList(head, mergeHead) = mergeSortedLinkedList(2, 1)
            t1  = 2
            t2  = 1
                                                                ________next_
                                                                |__-1__|____|
                                                                    | Child
                                                                ____↓_______
                                                                |__1__|____|
                                     ________t2_________            | Child
                                     |  _______next_   |        ____↓_______
                                     |  |__1__|____|   |        |__2__|____|
                                     |      | Child    |            | Child
                                     |  ____↓_______   |        ____↓_______
                                     |  |__4__|____|   |        |__4__|____|
                                     |      | Child    |            | Child
                                     |  ____↓_______   |        ____↓_______
        ________t1________           |  |__5__|____|   |        |__5__|____|
        |  _______next_  |           |      | Child    |            | Child
        |  |__2__|____|  |           |  ____↓_______   |        ____↓_______
        |     | child    |           |  |__6__|____|   |        |__6__|____|
        |  ___↓________  |           |      | Child    |            | Child
        |  |__10__|____| |  merge()  |  ____↓_______   |        ____↓_______
        |     | child    |           |  |__7__|____|   |   =    |__7__|____|
        |  	  ↓			 |           |      | Child    |            | Child
        |  	NULL		 |           |  ____↓_______   |        ____↓_______
        |________________|           |  |__8__|____|   |        |__8__|____|
                                     |      | Child    |            | Child
                                     |  ____↓_______   |        ____↓_______
                                     |  |__9__|____|   |        |__9__|____|
                                     |      | Child    |            | Child
                                     |  ____↓________  |        ____↓________
                                     |  |__11__|____|  |        |__10__|____|
                                     |      | Child    |            | Child
                                     |  ____↓________  |        ____↓________
                                     |  |__12__|____|  |        |__11__|____|
                                     |      | Child    |            | Child
                                     |      ↓          |        ____↓________
                                     |    NULL         |        |__12__|____|
                                     |_________________|            | Child
                                                                    ↓
                                                                  NULL

        ● Iteration-5:
            mergedHead = 1  // Node returned by mergeSortedLinkedList from the above iteration.
            head = 3        // Current Head
            mergeSortedLinkedList(head, mergeHead) = mergeSortedLinkedList(3, 1)
            t1  = 3
            t2  = 1                                             ________next_
                                                                |__-1__|____|
                                                                    | Child
                                     ________t2_________        ____↓_______
                                     |  _______next_   |        |__1__|____|
                                     |  |__1__|____|   |            | Child
                                     |      | Child    |        ____↓_______
                                     |  ____↓_______   |        |__2__|____|
                                     |  |__2__|____|   |            | Child
                                     |      | Child    |        ____↓_______
                                     |  ____↓_______   |        |__3__|____|
                                     |  |__4__|____|   |            | Child
                                     |      | Child	   |        ____↓_______
                                     |  ____↓_______   |        |__4__|____|
                                     |  |__5__|____|   |            | Child
                                     |      | Child	   |        ____↓_______
                                     |  ____↓_______   |        |__5__|____|
                                     |  |__6__|____|   |            | Child
                                     |      | Child	   |        ____↓_______
        ________t1________           |  ____↓______    |        |__6__|____|
        |  _______next_  |           |  |__7__|____|   |            | Child
        |  |__3__|____|  |           |      | Child	   |        ____↓_______
        |     | child    |  merge()  |  ____↓______	   |  =     |__7__|____|
        |     ↓          |           |  |__8__|____|   |            | Child
        |    NULL        |           |      | Child	   |        ____↓_______
        |________________|           |  ____↓_______   |        |__8__|____|
                                     |  |__9__|____|   |            | Child
                                     |      | Child	   |        ____↓_______
                                     |  ____↓________  |        |__9__|____|
                                     |  |__10__|____|  |            | Child
                                     |      | Child	   |        ____↓________
                                     |  ____↓________  |        |__10__|____|
                                     |  |__11__|____|  |            | Child
                                     |      | Child	   |        ____↓________
                                     |  ____↓________  |        |__11__|____|
                                     |  |__12__|____|  |            | Child
                                     |      | Child	   |        ____↓________
                                     |      ↓		   |        |__12__|____|
                                     |     NULL 	   |            | Child
                                     |_________________|            ↓
                                                                   NULL

    ● After the final iteration we will have the flattened sorted linked list.
        _________    _________    _________    _________    _________    _________    _________    _________    _________    __________    __________    __________
        |_1_|_C_| -> |_2_|_C_| -> |_3_|_C_| -> |_4_|_C_| -> |_5_|_C_| -> |_6_|_C_| -> |_7_|_C_| -> |_8_|_C_| -> |_9_|_C_| -> |_10_|_C_| -> |_11_|_C_| -> |_12_|_C_| -> NULL


Complexity Analysis:
    1. Time Complexity: O( N*(2M) ) ~ O(2 N*M), where `N` is the length of the linked list along the next pointers & `M` is the length
                        of the linked list along the child pointers.

                        ● The merge operation in each recursive call takes time complexity proportional to the length of the linked lists
                          being merged as they have to iterate over the entire lists. Since the vertical depth of the linked lists is
                          assume to be M, the time complexity for a single merge operation is proportional to O(2*M).

                        ● This operation operation is performed N number of times (to each and every node along the next pointer list)
                          hence the resultant time complexity becomes: O(N* 2M).

    2. Space Complexity: O(1), as this algorithm uses no external space or additional data structures to store values. But a recursive
                         stack uses O(N) space to build the recursive calls for each node along the next pointer list.

*/

#include <iostream>
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

// Merges two sorted linked lists in a particular order based on the data value
Node *mergeSortedLinkedList(Node *list1, Node *list2)
{
    // Create a dummy node for the result
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    // Merge the lists based on data values
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    // Connect the remaining elements if any
    if (list1)
    {
        res->child = list1;
    }
    else
    {
        res->child = list2;
    }

    // Break the last node's link to prevent cycles between the original and dummy.
    // If we don't nullify next, the first node (for eg; 4) might still retain its
    // old next pointer (i.e; 4->next = 12), causing an incorrect structure.
    if (dummyNode->child)
    {
        // To ensure that the next pointer of the first node in the flattened linked
        // list is set to NULL. By first node we mean the first valid node not '-1',
        // which is dummyNode->child.
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

// Flattens a linked list with child pointers
Node *flattenLinkedList(Node *head)
{
    // Base case of recursion
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    /* Recursively flatten the rest of the linked list */

    // `mergedHead` will store the returning value from either
    // flattenLinkedList (base case) or mergeSortedLinkedList.
    Node *mergedHead = flattenLinkedList(head->next);

    // `head` will store the current node of the next pointers.
    head = mergeSortedLinkedList(head, mergedHead);

    return head;
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

        // If child exists, recursively print it with indentation
        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
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

    head->next = new Node(4);
    head->next->child = new Node(10);

    head->next->next = new Node(12);
    head->next->next->child = new Node(13);
    head->next->next->child->child = new Node(20);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list and print the flattened list
    Node *flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}