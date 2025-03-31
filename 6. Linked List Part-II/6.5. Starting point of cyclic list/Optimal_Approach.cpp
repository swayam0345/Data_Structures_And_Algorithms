/*
Intuition:
    ● The previous method uses O(N) additional memory, which can become quite large as the linked list length grows.
      To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization.

    ● The key insight is that when the slow and fast pointers meet inside the loop, the distance travelled by each
      pointer can be used to calculate the starting point of the loop.

    ● We will reset the `slow` pointer to the head of the linked list, and  Move `fast` and `slow` one step at a time
      until they meet again. The point where they meet again is the starting point.

Proof of this Algorithm:
    ● This algorithm hinges on the idea that the point where the slow and fast pointers converge can be leveraged to
      determine the starting point of the loop.
    

                                  _______________L1_____________  _______________________
                                  |             _______      __↓__↓_      _______       |
                                  |  ---------→ |__4__| ---> |__5__| ---> |__6__|       |
                                  |  ↑                         fast          |          |
        _______      _______      ↓__|___                                    |          |
        |__1__| ---> |__2__| ---> |__3__| slow                               |          | d
                                     ↑                                       |          |
        <----------- L1 -----------> |          _______      _______      ___↓___       |
                                     ←--------- |__9__| <--- |__8__| <--- |__7__|       |
                                                   ↑____________________________________|

    ● In the "tortoise and hare" algorithm for detecting loops in a linked list, when the slow pointer (tortoise) reaches
      the starting point of the loop, the fast pointer (hare) is positioned at a point that is twice the distance travelled
      by the slow pointer. This is because the hare moves at double the speed of the tortoise.

    ● If slow has travelled distance `L1` then fast has travelled `2 * L1`. Now that slow and fast have entered the loop,
      the distance fast will have to cover to catch up to slow is the total length of loop minus L1. Let this distance be `d`.
        ___________________________________________
        |                                         |
        |   Distance travelled by slow = L1       |
        |   Distance travelled by fast = 2 * L1   |
        |   Total length of loop = L1 + d         |
        |_________________________________________|

    ● In this configuration, the fast pointer advances toward the slow pointer with two jumps per step, while the slow pointer
      moves away with one jump per step. As a result, the gap between them decreases by 1 with each step. Given that the initial
      gap is `d`, it takes exactly `d` steps for them to meet.
        __________________________________________
        |                                        |
        |   Total length of loop = L1 + d        |
        |   Distance between slow and fast = d   |
        |________________________________________|

    ● During these d steps, the slow pointer effectively travels d steps from the starting point within the loop and fast travels
      `2 * d` and they meet at a specific point. Based on our previous calculations, the total length of the loop is `L1 + d`. And
      since the distance covered by the slow pointer within the loop is `d`, the remaining distance within the loop is equal to `L1`.

      After `d` steps
                                  _______________________________________________________
                                  |             _______      _______      _______       |
                                  |  ---------→ |__4__| ---> |__5__| ---> |__6__|       |
                                  |  ↑                                       |          |
        _______      _______      ↓__|___                                    |          |
        |__1__| ---> |__2__| ---> |__3__|                                    |          | d
                                  ↑  ↑                      fast/slow        |          |
                                  |  |          _______      _______      ___↓___       |
                                  |  ←--------- |__9__| <--- |__8__| <--- |__7__|       |
        Length of loop - d = L1   |___________________________↑   ↑_____________________|

        __________________________________________
        |                                        |
        |   Total length of loop - d = L1        |
        |________________________________________|


    ● Therefore, it is proven that the distance between the starting point of the loop and the point where the two pointers meet is
      indeed equal to the distance between the starting point and head of the linked list.


Approach:
    1. Initialise two pointers, `slow` and `fast`, to the head of the linked list. `slow` will advance one step at a time,
       while `fast` will advance two steps at a time. These pointers will move simultaneously.

    2. Traverse the linked list with the `slow` and `fast` pointers. While traversing, repeatedly move `slow` one step and
       `fast` two steps at a time.

    3. Continue this traversal until one of the following conditions is met:
        (a) `fast` or `fast.next` reaches the end of the linked list (i.e., becomes null). In this case, there is no loop
            in the linked list, and the algorithm terminates by returning null.
        (b) `fast` and `slow` pointers meet at the same node. This indicates the presence of a loop in the linked list.

    4. Reset the `slow` pointer to the head of the linked list. Move `fast` and `slow` one step at a time until they meet again.
       The point where they meet again is the starting point.


Complexity Analysis:
    1. Time Complexity: O(N), The code traverses the entire linked list once, where 'n' is the number of nodes in the list.
                        This traversal has a linear time complexity, O(n).

    2. Space Complexity: O(1), The code uses only a constant amount of additional space, regardless of the linked list's length.
                         This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra
                         memory usage, resulting in constant space complexity, O(1).

*/

#include <iostream>
#include <unordered_map>

using namespace std;

// Node class represents a node
// in a linked list
class Node
{
public:
    // Data stored in the node
    int data;
    // Pointer to the next node in the list
    Node *next;

    // Constructor with both data
    // and next node as parameters
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

// Function to find the first node of the loop in a linked list
Node *firstNodeOfCyclicList(Node *head)
{
    // Initialize a slow and fast to the head of the list
    Node *slow = head;
    Node *fast = head;

    /* Step-1: Detect the loop in the linked list */
    while (fast != NULL && fast->next != NULL)
    {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        /* Step-2: Find the first node of the loop */
        if (slow == fast)   // If slow and fast meet, a loop is detected
        {
            // Reset the slow pointer to the head of the list
            slow = head;

            while (slow != fast)
            {
                // Move slow and fast one step at a time
                slow = slow->next;
                fast = fast->next;
                // Intersection of slow & fast, is the first node of the loop. 
            }

            // Return the first node of the loop
            return slow;
        }
    }

    // If no loop is found, return NULL
    return NULL;
}

int main()
{
    // Create a sample linked list with a loop
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node *head = node1;

    // Detect the loop in the linked list
    Node *loopStartNode = firstNodeOfCyclicList(head);

    if (loopStartNode)
    {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}