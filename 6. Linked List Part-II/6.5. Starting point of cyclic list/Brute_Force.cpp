/*
Intuition:
   ● The starting point of a loop of the linked list is the first node we visit twice during its traversal.
   ● It's the point where we realise that we are no longer moving forward in the list but rather entering a cycle.

                                                _______      ________      _______
                                     ---------→ |__4__| ---> |__13__| ---> |__6__|
                                     ↑                                        |
        _______      _______      ___|____                                    |
        |__1__| ---> |__2__| ---> |__15__|                                    |
                                     ↑                                        |
                                     |           _______      _______      ___↓___
                                     ←---------- |__9__| <--- |__8__| <--- |__7__|

   ● Here, `15` is the node that is the first node which is encountered twice in the traversal.
     Hence, it is the starting point of the cyclic linked list.


Approach:
    1. Traverse through the LL using the traversal technique of assigning a temp node to the head and iterating
       by moving to the next element till we reach null.

    2. While traversing, keep a track of the visited nodes in the map data structure.
        Note: Storing the entire node in the map is essential to distinguish between nodes with identical values but
              different positions in the list. This ensures accurate loop detection and not just duplicate value checks.

    3. If a previously visited node is encountered again, that proves that there is a loop in the linked list
       hence return that node.

    4. If the traversal is completed, and we reach the last point of the LL which is null, it means there was
       no loop, hence we return null.


Complexity Analysis:
   1. Time Complexity: O(N), The code traverses the entire linked list once, where 'N' is the number of nodes in the list.
                       Therefore, the time complexity is linear, O(N).

   2. Space Complexity: O(N), The code uses a hash map/dictionary to store encountered nodes, which can take up to O(N)
                        additional space, where 'n' is the number of nodes in the list. Hence, the space complexity is O(N)
                        due to the use of the map to track nodes.

*/


#include <iostream>
#include <unordered_map>

using namespace std;

// Node class represents a node in a linked list
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

   // Constructor with only data as
   // a parameter, sets next to nullptr
   Node(int data1)
   {
      data = data1;
      next = nullptr;
   }
};

// Function to detect a loop in a linked list
// and return the starting node of the loop
Node *detectStartOfLoop(Node *head)
{
   // Use temp to traverse the linked list
   Node *temp = head;

   // hashmap to store all visited nodes
   unordered_map<Node *, int> mp;

   // Traverse the list using temp
   while (temp != NULL)
   {
      // check if temp has been encountered again
      if (mp.count(temp) != 0)
      {
         // A loop is detected hence return temp
         return temp;
      }
      // store temp as visited
      mp[temp] = 1;
      // iterate through the list
      temp = temp->next;
   }

   // If no loop is detected, return nullptr
   return nullptr;
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
   Node *loopStartNode = detectStartOfLoop(head);

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
