/*
Intuition:
    ● The approach simplifies reversing linked list nodes by breaking the list into segments of K nodes
      and reversing each segment individually.

    ● Starting from the head, the algorithm traverses the list to identify segments of `K` nodes. Upon finding
      a segment, it reverses it, returning the modified list. If a segment has less than 'K' nodes left
      (ie. remaining nodes at the end), they are left unaltered.

    ● To implement this complex algorithm we can break down the process into three parts:
      (a) reverseLinkedList:
            ➤ This function takes the head of a segment as input and reverses the linked list formed by that segment.
            ➤ It operates by utilizing the classic iterative 3-pointer method to reverse the direction of pointers
               within the segment.

      (b) getKthNode:
            ➤ The purpose of this function is to identify the end of a segment of `K` nodes in the linked list.
            ➤ Given a starting node, it traverses `K` nodes in the list and returns the Kth node, allowing the
               segmentation of the list into smaller parts for reversal.

      (c) kReverse:
            ➤ The main function orchestrates the reversal process. It iterates through the linked list and identifies
               segments of `K` nodes using `getKthNode`.
            ➤ For each identified segment, it utilizes `reverseLinkedList` to reverse the nodes within that segment.
               This iterative approach efficiently reverses the linked list nodes in groups of K.


Approach:
    1. Initialise a pointer `temp` to the `head` of the linked list. Using `temp`, traverse to the Kth Node iteratively.

    2. On reaching the Kth Node, preserve the Kth Node’s next node as `nextNode` (this will help us in iterating the 
       next linked list segment). And set the Kth Node’s next pointer to `NULL`. This effectively breaks the linked
       list into a smaller list of size `K` that can be reversed and attached back.

        K = 3
        _________    _________    _________    _________    _________    _________    _________    _________    _________    __________
        |_1_|_n_| -> |_2_|_n_| -> |_3_|_n_| -> |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
            head        |
            temp        | getKthNode()
        ________________↓____________________________  ---→ NULL
        |    _________    _________    _________    |  |    _________    _________    _________    _________    _________    _________    __________
        |    |_1_|_n_| -> |_2_|_n_| -> |_3_|_n_| ______|    |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
        |___________________________________________|
                temp                     kth Node

    3. Treat this segment from `temp` to Kth Node as an individual linked list and reverse it. This can be done via the help
       of a helper function `reverseLinkedList` which will reverse the linked list using iterative 3-pointer method.

    4. The reversed linked list segment returns a modified list with `temp` now at its tail and the `Kth-Node` pointing to its head.
       Before updating `temp` to the `nextNode` we need to initialize `prevLast` with the current `temp`, so that we can link the segments later.
       Now update the temp's `next` pointer to `nextNode`, in order to jump to the next segment.
       If we are at the first segment of K nodes, we should update the `head` to `Kth Node`, as this will be the new head of the reversed linked list.

        K = 3
        _________    _________    _________    _________    _________    _________    _________    _________    _________    __________
        |_1_|_n_| -> |_2_|_n_| -> |_3_|_n_| -> |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
            head           |
            temp           | getKthNode()
        ___________________↓_________________________  ---→ NULL
        |    _________    _________    _________    |  |    _________    _________    _________    _________    _________    _________    __________
        |    |_1_|_n_| -> |_2_|_n_| -> |_3_|_n_| ___|__|    |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
NULL    |___________________________________________|
prevLast       temp        |            kth Node
               head        | reverseLinkedList()
        ___________________↓_________________________  ---→ NULL
        |    _________    _________    _________    |  |    _________    _________    _________    _________    _________    _________    __________
        |    |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| ___|__|    |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
NULL    |___________________________________________|
prevLast      kth Node                   temp
                                         head

            head = kth-Node (if 1st segment)
            prevLast = temp
            temp = nextNode
        _________    _________    _________    _________    _________    _________    _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_|    |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
        kth-Node                  prevLast     nextNode
          head                                   temp

    5. Continue this reversal for further groups. If a segment has fewer than `K` Nodes, leave them unmodified and return the new head.
       Use the `prevLast` pointer to maintain the link between the end of the previous reversed segment and the current segment.
        (a) Maintaining the `prevLast` if the segment has fewer than K nodes.
            if (kThNode == NULL) {
                if (prevLast != NULL) {
                    prevLast->next = temp;
                }
                break;
            }
                                                                                                                          NULL
        _________    _________    _________    _________    _________    _________    _________    _________    _________   ↑    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_|___|    |_10_|_n_| -> NULL
          head                                                                                                  prevLast          nextNode
                                                                                                                            |       temp
                                                                                                                            | 
                                                                                                                            | getKthNode(10, 3) returns NULL
                                                                                                                            ↓
        _________    _________    _________    _________    _________    _________    _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_| -> |_10_|_n_| -> NULL
          head                                                                                                  prevLast      nextNode
                                                                                                                                temp


        (b) Maintaining the `prevLast` for all remaining segments except the first one.
            if(1st segment) {
                head = kth-node
            } else {
                prevLast->next = kth-node
            }
                                                        reverseLinkedList(from node 4 to 6)
                                                                    |
                                             NULL                   |                   NULL
        _________    _________    _________   ↑     _________    ___↓_____    _________   ↑    _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_|___|     |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_|___|    |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head                     prevLast         kth-Node                    temp           nextNode
                                                                    |
            As it's not the 1st segment, so we need to link the     |
            prevLast to the kth-Node, in order to preserve the      |
            linked list.                                            |
                prevLast->next = kth-node                           |
                                                                    |              NULL
        _________    _________    _________    _________    ________↓    _________   ↑    _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_|___|    |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head                     prevLast    kth-Node                    temp           nextNode


Dry Run:
Let's consider the following example.
    Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10        and         K = 3

    ➤ ​̲𝗜​̲𝗻​̲𝗶​̲𝘁​̲𝗶​̲𝗮​̲𝗹​̲𝗶​̲𝘇​̲𝗮​̲𝘁​̲𝗶​̲𝗼​̲𝗻:
        temp = head = 1
        prevLast = NULL (tracks the last node of the previous group)

                                                            kReverse(head=1, k=3)
                                                                    |
                                                                    |
    ➤ ​̲𝗜​̲𝘁​̲𝗲​̲𝗿​̲𝗮​̲𝘁​̲𝗶​̲𝗼​̲𝗻​̲-​̲𝟭​:                                                   |
        _________    _________    _________    _________    ________↓    _________    _________    _________    _________    __________
        |_1_|_n_| -> |_2_|_n_| -> |_3_|_n_| -> |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head              |
          temp              | getKthNode(temp=1, k=3)
        ____________________↓________________________
        |    _________    _________    _________    |       _________    _________    _________    _________    _________    _________    __________
        |    |_1_|_n_| -> |_2_|_n_| -> |_3_|_n_| ---|-----→ |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
  NULL  |___________________________________________|
prevLast       temp        |            kth Node
               head        |
                           |  nextNode = kThNode->next = 4
                           |  kThNode->next = 3->next = NULL
                           |  reverseLinkedList(1 to 3)
        ___________________↓________________________  ---→ NULL
    ____|__ _________    _________    _________    |  |    _________    _________    _________    _________    _________    _________    __________
    ↓   |   |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| ___|__|    |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
  NULL  |__________________________________________|
prevLast    kth Node       |             temp
                           |             head
                           |
                           |  if(head(1) == temp(1)) {
                           |     it's the 1st segment
                           |     head = kth-Node
                           |  }
                           |  prevLast = temp
                           |  temp = nextNode
        ___________________↓________________________  ---→ NULL
    ____|__ _________    _________    _________    |  |     _________    _________    _________    _________    _________    _________    __________
    ↓   |   |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| ___|__|     |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
  NULL  |__________________________________________|         nextNode
            kth Node                  prevLast                 temp


    ➤ ​̲𝗜​̲𝘁​̲𝗲​̲𝗿​̲𝗮​̲𝘁​̲𝗶​̲𝗼​̲𝗻​̲-​̲𝟮:                            ---→ NULL
        _________    _________    _________  |  _________    _________    _________    _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_|__|  |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| -> |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head                    prevLast        temp              |
                                                                    | getKthNode(temp=4, k=3)
                                                ____________________↓________________________
        _________    _________    _________     |    _________    _________    _________    |      _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_|___  |    |_4_|_n_| -> |_5_|_n_| -> |_6_|_n_| ---|----→ |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head                    prevLast   |  |___________________________________________|       nextNode
                                             ↓          temp         |          kth Node
                                           NULL                      |
                                                                     |  nextNode = kThNode->next = 7
                                                                     |  kThNode->next = 6->next = NULL
                                                                     |  reverseLinkedList(4 to 6)
                                                 ____________________↓_______________________  ---→ NULL
        _________    _________    _________      |    _________    _________    _________   |  |  _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_|___ __|____|_6_|_n_| -> |_5_|_n_| -> |_4_|_n_|___|__|  |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head                     prevLast  | | |__________________________________________|      nextNode
                                             ↓ ↓       kth Node     |             temp
                                             NULL                   |
                                                                    | As, (head(3) != temp(4)), it's not the 1st segment
                                                                    |   prevLast->next = kThNode = 1->next = 6
                                                                    |   prevLast = temp = 4
                                                                    |   temp = nextNode = 7
                                                ____________________↓_____________________  ---→ NULL
        _________    _________    _________     |  _________    _________    _________   |  |  _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_|-----|→ |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_|___|__|  |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head                                  |________________________________________|      nextNode
                                                    Kth Node                  prevLast            temp


    ➤ ​̲𝗜​̲𝘁​̲𝗲​̲𝗿​̲𝗮​̲𝘁​̲𝗶​̲𝗼​̲𝗻​̲-​̲𝟯:​                                                                     ---→ NULL
        _________    _________    _________      _________    _________    _________  |  _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| ---→ |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_|__|  |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| -> |_10_|_n_| -> NULL
          head                                                              prevLast       temp             |
                                                                                                            | getKthNode(temp=7, k=3)
                                                                                        ____________________↓_______________________  
        _________    _________    _________    _________    _________    _________      |   _________    _________    _________    |    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_|____  |   |_7_|_n_| -> |_8_|_n_| -> |_9_|_n_| ---]--→ |_10_|_n_| -> NULL
          head                                                            prevLast   |  |__________________________________________|     nextNode
                                                                                     ↓         temp         |          Kth Node
                                                                                   NULL                     |  nextNode = kThNode->next = 7
                                                                                                            |  kThNode->next = 6->next = NULL
                                                                                                            |  reverseLinkedList(7 to 9)
                                                                                        ____________________↓________________________  ---→ NULL
        _________    _________    _________    _________    _________    _________      |    _________    _________    _________    |  |   __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_|____  |    |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_|____|__|   |_10_|_n_| -> NULL
          head                                                            prevLast   |  |___________________________________________|       nextNode
                                                                                     ↓        Kth Node      |             temp
                                                                                   NULL                     |
                                                                                                            | As, (head(3) != temp(7)), it's not the 1st segment
                                                                                                            |   prevLast->next = kThNode = 4->next = 9
                                                                                                            |   prevLast = temp = 7
                                                                                                            |   temp = nextNode = 10
                                                                                        ____________________↓________________________  ---→ NULL
        _________    _________    _________    _________    _________    _________      |    _________    _________    _________    |  |    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_| -----|--→ |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_|____|__|    |_10_|_n_| -> NULL
          head                                                                          |___________________________________________|        nextNode
                                                                                              kth Node                  prevLast               temp


    ➤ ​̲𝗜​̲𝘁​̲𝗲​̲𝗿​̲𝗮​̲𝘁​̲𝗶​̲𝗼​̲𝗻​̲-​̲𝟰:                                                                                                            ---→ NULL
        _________    _________    _________      _________    _________    _________    _________    _________    _________  |  __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| ---→ |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_|__|  |_10_|_n_| -> NULL
          head                                                                                                     prevLast        temp
                                                                                                                                    |
                                                                                                getKthNode(temp=10, k=3) {          |
                                                                                                  returns NULL                      |
                                                                                                  because there aren't k=3 elements |
                                                                                                  after node 10 to form a segment   |
                                                                                                }                    NULL ←---      |
        _________    _________    _________      _________    _________    _________    _________    _________    _________  |  ____↓_____
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| ---→ |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_|__|  |_10_|_n_| -> NULL
          head                                                                                                     prevLast        temp
                                                                                                                                    |
                                                                                                    (kth Node = NULL) {             | 
                                                                                                        (prevLast(7) != NULL) {     |
                                                                                                          prevLast->next = temp     |
                                                                                                          7->next = 10              |
                                                                                                        }                           |
                                                                                                    }                               |
        _________    _________    _________      _________    _________    _________    _________    _________    _________      ___↓______
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| ---→ |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_| ---→ |_10_|_n_| -> NULL
          head                                                                                                     prevLast         temp


    ● `kReverse()` will break/exit after Iteration-3 and we will have our desired output, i.e;
        _________    _________    _________    _________    _________    _________    _________    _________    _________    __________
        |_3_|_n_| -> |_2_|_n_| -> |_1_|_n_| -> |_6_|_n_| -> |_5_|_n_| -> |_4_|_n_| -> |_9_|_n_| -> |_8_|_n_| -> |_7_|_n_| -> |_10_|_n_| -> NULL


Complexity Analysis:
    1. Time Complexity: O(N), The time complexity consists of actions of reversing segments of `K` and finding the Kth node which
                        operates in linear time. Thus, O(N) + O(N) = O(2N), which simplifies to O(N).

    2. Space Complexity: O(1), as the algorithm operates in place without any additional space requirements.

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


// Function to reverse a linked list using the 3-pointer approach
Node *reverseLinkedList(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

// Function to get the Kth node from a given position in the linked list
Node *getKthNode(Node *temp, int k)
{
    // Decrement K as we already start from the 1st node
    k -= 1;

    // Decrement K until it reaches the desired position
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }

    // Return the Kth node
    return temp;
}

// Function to reverse nodes in groups of K
Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prevLast = NULL;    // last node of the previous group

    while (temp != NULL)
    {
        // Get the Kth node of the current group
        Node *kThNode = getKthNode(temp, k);

        // If the Kth node is NULL, it's not a segment of k-nodes
        if (kThNode == NULL)
        {
            // If there was a previous group, link the last node (prevLast)
            // of the previous group to the current node (temp).
            if (prevLast != NULL)
            {
                prevLast->next = temp;
            }

            break;
        }

        // Store the next node after the Kth node
        // for interation of the next segment.
        Node *nextNode = kThNode->next;

        // Disconnect the Kth node (isolate the segment from
        // the linked list), to prepare for reversal
        kThNode->next = NULL;

        // Reverse the nodes from temp to the Kth node
        reverseLinkedList(temp);

        // If it's the first segment then, tmep & head will be same.
        // If so then update the head of the linked list with the kth node.
        if (temp == head)
        {
            head = kThNode;
        }
        else
        {
            // If it's no the first segment then we need to link 
            // the isolated segment with the linked list.
            // So, we will link the last node of the previous group
            // (prevLast) to the first node of the reversed group (kth node).
            prevLast->next = kThNode;
        }

        // Update the pointer to the last node of the previous group
        prevLast = temp;

        // Move to the next group
        temp = nextNode;
    }

    // Return the head of the modified linked list
    return head;
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
    // linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);
	head->next->next->next->next->next->next->next->next = new Node(9);
	head->next->next->next->next->next->next->next->next->next = new Node(10);
    int k = 3;

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = kReverse(head, k);

    // Print the reversed linked list
    cout << "K[" << k << "]-Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}