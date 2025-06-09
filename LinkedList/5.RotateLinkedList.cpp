/*
Problem:
Rotate the linked list to the right by k nodes.

Explanation:
If the list is 1 -> 2 -> 3 -> 4 -> 5 and k = 2,

After rotation: 4 -> 5 -> 1 -> 2 -> 3.
*/

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to append a new node at the end
void append(Node*& head, int val) 
{
    if (!head) 
    {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

// Function to print linked list
void printList(Node* head) 
{
    while (head) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Function to rotate list right by k
Node* rotateRight(Node* head, int k) 
{
    if (!head || !head->next || k == 0)
        return head;

    // Compute length and get last node
    Node* temp = head;
    int length = 1;
    while (temp->next) 
    {
        temp = temp->next;
        length++;
    }

    // Connect last node to head to make it circular
    temp->next = head;

    // Find new tail: (length - k % length - 1)th node
    // and new head: (length - k % length)th node
    k = k % length;
    int stepsToNewHead = length - k;

    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;

    // Break the circle
    newTail->next = nullptr;

    return newHead;
}

int main() {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    cout << "List after rotating by " << k << ": ";
    printList(head);

    return 0;
}
