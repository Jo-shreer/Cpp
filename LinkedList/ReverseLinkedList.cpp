#include <iostream>
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
    void insertAtEnd(int val) 
		{
        Node* newNode = new Node(val);  
        if (head == nullptr) 
				{
            head = newNode;  
        } 
				else
				{
            Node* temp = head;
            while (temp->next != nullptr) 
						{  
                temp = temp->next;
            }
            temp->next = newNode;  
        }
    }

    void display() const 
		{
        if (head == nullptr) 
				{
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) 
				{
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;  
    }

    void reverse() 
		{
        Node* prev = nullptr;  
        Node* current = head;  
        Node* next = nullptr;   

        while (current != nullptr) 
				{
            next = current->next;  
            current->next = prev;  
            prev = current;        
            current = next;
        }
        head = prev;
    }
    ~LinkedList() 
		{
        while (head != nullptr) 
				{
            deleteAtEnd();
        }
    }

    void deleteAtEnd() 
		{
        if (head == nullptr) 
				{  
            return;
        }

        if (head->next == nullptr) 
				{ 
            delete head;  
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) 
				{			
            temp = temp->next;
        }

        Node* lastNode = temp->next;
        temp->next = nullptr;
        delete lastNode;
    }
};

int main() 
{
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    std::cout << "Original Linked List: ";
    list.display();
    list.reverse();
    std::cout << "Reversed Linked List: ";
    list.display();
    return 0;
}
