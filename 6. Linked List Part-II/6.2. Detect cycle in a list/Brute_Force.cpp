/*
Intuition:
    ● A loop in a linked list occurs when there's a node that, when followed, brings you back to it,
      indicating a closed loop in the list.
    ● Hence it's important to keep track of nodes that have already been visited so that loops can be detected.
      One common way to do this is by using hashing.
                                                _______      ________      _______
                                     ---------→ |__4__| ---> |__13__| ---> |__6__|
                                     ↑                                        |
        _______      _______      ___|____                                    |
        |__1__| ---> |__2__| ---> |__15__|                                    |
                                     ↑                                        |
                                     |           _______      _______      ___↓___
                                     ----------← |__9__| <--- |__8__| <--- |__7__|

        ● Here, `15` is the node that is the first node which is encountered twice in the traversal.
          Hence, it is the starting point of the cyclic linked list.


Approach:
    1. Traverse through the LL using the traversal technique of assigning a temp node to the head and iterating by moving
       to the next element till we reach null.

    2. While traversing, keep a track of the visited nodes in the map data structure.
        Note: Storing the entire node in the map is essential to distinguish between nodes with identical values but
              different positions in the list. This ensures accurate loop detection and not just duplicate value checks.

    3. If a previously visited node is encountered again, that proves that there is a loop in the linked list hence return true.

    4. If the traversal is completed, and we reach the last point of the LL which is null, it means there was noloop,
       hence we return false.


Complexity Analysis:
    1. Time Complexity: O(N * (2 * log(N)))
            Reason: The algorithm traverses the linked list once, performing hashmap insertions and searches in
                    the while loop for each node. The insertion and search operations in the unordered_map have a
                    worst-case time complexity of O(log(N)). As the loop iterates through N nodes, the total time
                    complexity is determined by the product of the traversal (O(N)) and the average-case complexity
                    of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)). 

    2. Space Complexity: O(N)
            Reason: The code uses a hashmap/dictionary to store encountered nodes, which can take up to O(N) additional
                    space, where 'n' is the number of nodes in the list. Hence, the spacecomplexity is O(N) due to the
                    use of the map to track nodes.

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1)
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

bool isCyclicLinkedList(Node *head1)
{
    unordered_set<Node*> st;

    /* Insert into unordered set and check for circular dependency. */
    while (head1 != NULL)
    {
        if (st.find(head1) != st.end())
        {
            return true;
        }
        st.insert(head1);
        head1 = head1->next;
    }

    return false;
}

int main()
{        
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    bool result = isCyclicLinkedList(head);
    cout << ((result == true) ? "True" : "False");

    return 0;
}