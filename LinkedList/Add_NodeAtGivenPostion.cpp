#include <iostream>
using namespace std;

// Node structure
struct Node 
{
    int data;
    Node* next;
    Node(int value) 
     {
        data = value;
        next = nullptr;
    }
};

// Class to represent the Linked List
class LinkedList 
{
    private:
    Node* head;
    
    public:
    // Constructor
    LinkedList() 
    {
        head = nullptr;
    }    
    // Function to print the linked list
    void printList() 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    
    // Function to add a node at a given position
    void addNodeAtPosition(int value, int position) 
    {
        Node* newNode = new Node(value);
        // If the list is empty or the position is 0, insert at the beginning
        if (position == 0) 
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        int current_pos = 0;
        while (temp != nullptr && current_pos < position - 1)  // Traverse to the node just before the desired position
        {
            temp = temp->next;
            current_pos++;
        }        
        // Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main() 
{
    LinkedList list;
    // Adding some nodes to the list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    cout << "Original List: ";
    list.printList();  // Output: 10 -> 20 -> 30 -> 40 -> nullptr
    
    // Add a node at position 2 (after the 2nd node)
    list.addNodeAtPosition(25, 2);
    
    cout << "List after adding 25 at position 2: ";
    list.printList();  // Output: 10 -> 20 -> 25 -> 30 -> 40 -> nullptr
    
    // Add a node at position 0 (insert at the beginning)
    list.addNodeAtPosition(5, 0);
    
    cout << "List after adding 5 at position 0: ";
    list.printList();  // Output: 5 -> 10 -> 20 -> 25 -> 30 -> 40 -> nullptr
    
    // Add a node at a position greater than the length of the list
    list.addNodeAtPosition(50, 10);  // Output: Position out of range
    
    return 0;
}
