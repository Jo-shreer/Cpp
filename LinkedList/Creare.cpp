#include <iostream>
using namespace std;

struct Node 
{
    int data;   // Data to store
    Node* next; // Pointer to the next node

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList 
{
    private:
    Node* head; 

    public:
    LinkedList() : head(nullptr) {}

    void append(int value) 
    {
        Node* newNode = new Node(value);  // Create a new node
        if (!head) 
        {
            head = newNode; // If the list is empty, the new node becomes the head
            return;
        }
        // Otherwise, find the last node and link the new node
        Node* temp = head;
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) 
    {
        Node* newNode = new Node(value);  // Create a new node
        newNode->next = head;  // New node points to the current head
        head = newNode;  // New node becomes the new head
    }

    // Function to print the entire list
    void printList() const 
    {
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    ~LinkedList() 
    {
        Node* temp;
        while (head) 
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() 
{
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    // Print the list
    cout << "Linked List: ";
    list.printList();  // Output: 10 20 30 40

    // Insert a node at the beginning
    list.insertAtBeginning(5);
    cout << "After inserting 5 at the beginning: ";
    list.printList();  // Output: 5 10 20 30 40

    return 0;
}


