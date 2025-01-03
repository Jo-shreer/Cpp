#include <iostream>
using namespace std;

struct Node 
{
    int data;   
    Node* next; 
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
        Node* newNode = new Node(value);  
        if (head == nullptr) 
        {             
            head = newNode;                
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAtBeginning(int value) 
    {
        Node* newNode = new Node(value);  
        newNode->next = head;  
        head = newNode;  
    }
    void printList() const 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {  
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~LinkedList() 
    {
        Node* temp;
        while (head != nullptr) 
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
    cout << "Linked List: ";
    list.printList();  // Output: 10 20 30 40
    list.insertAtBeginning(5);
    cout << "After inserting 5 at the beginning: ";
    list.printList();  // Output: 5 10 20 30 40
    return 0;
}
