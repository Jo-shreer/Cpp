/*
Got it! Here’s a clean, classic C++ code snippet to find the intersection node of two singly linked lists — the node where they start to share the same tail.

Problem:
Given two singly linked lists, 
find the node at which the two lists intersect.
If they do not intersect, return nullptr.

Approach:
Use two pointers, each starting at the head of the two lists.
Move both pointers forward.
When a pointer reaches the end, redirect it to the head of the other list.
If the lists intersect, the pointers will meet at the 
intersection node after at most 2 passes.
If no intersection, both will reach nullptr.
*/

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to print a linked list
void printList(Node* head) 
{
    while (head) 
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

// Function to get intersection node
Node* getIntersectionNode(Node* headA, Node* headB) 
{
    if (!headA || !headB) return nullptr;

    Node* ptrA = headA;
    Node* ptrB = headB;

    // Traverse both lists, switch heads when reaching end
    while (ptrA != ptrB) 
    {
        ptrA = (ptrA == nullptr) ? headB : ptrA->next;
        ptrB = (ptrB == nullptr) ? headA : ptrB->next;
    }

    return ptrA;  // either intersection or nullptr
}

int main() 
{
    // Create first list: 1->2->3->4->5
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);

    // Create second list: 9->4->5 (intersecting at node with value 4)
    Node* headB = new Node(9);
    headB->next = headA->next->next->next;  // Pointing to node with value 4 in list A

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->data << "\n";
    } else {
        cout << "No intersection.\n";
    }

    return 0;
}
