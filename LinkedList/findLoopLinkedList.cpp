#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to detect loop using Floyd’s Cycle-Finding Algorithm
bool hasLoop(Node* head) 
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;           // move slow by one
        fast = fast->next->next;     // move fast by two

        if (slow == fast) 
        {
            return true;             // loop detected
        }
    }

    return false;                    // no loop
}

// Helper function to create a loop for testing
void createLoop(Node* head, int pos) {
    if (pos == -1) return;

    Node* loopNode = head;
    for (int i = 0; i < pos; ++i) {
        loopNode = loopNode->next;
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = loopNode;
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    createLoop(head, 2); // Creates a loop starting at position 2 (0-based index)

    if (hasLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop in the linked list." << endl;
    }

    return 0;
}
