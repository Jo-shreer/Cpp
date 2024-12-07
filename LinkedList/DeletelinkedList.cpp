#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val): data(val), next(nullptr){}
};
class LinkedList
{
  private:
  Node* head;
  public:
  void insertAtEnd(int val)
  {
      Node* newNode = new Node(val);
      if(head == nullptr)
      {
          head = newNode;
      }
      else
      {
          Node* temp = head;
          while(temp->next != nullptr)
          { 
              temp = temp->next;
          }
          temp->next = newNode;
      }
  }
  void insertAtFirst(int val)
  {
      Node* newNode = new Node(val);
      newNode->next = head;
      head = newNode;
  }
  void deleteAtFirst()
  {
      if(head == nullptr)
      {
          cout << "lst is empty" << endl;
      }
      else
      {
          Node *temp = head;
          head = head->next;
          delete temp;
      }
  }
  void deleteAtposition( int pos)
  {
      Node* temp = head;
      if(head == nullptr)
      {
          cout << "List is empty" << endl;
      }
      for(int i =0; temp != nullptr && i < pos - 1; ++i)
           temp = temp->next;
      Node *detedNode = temp->next;
      temp->next = temp->next->next;
      delete detedNode;
  }
  
  void display()
  {
      if(head == nullptr)
      {
          cout << "List is empty" << endl;
      }
      else
      {
          Node* temp = head;
          while(temp !=nullptr)
          {
              cout << "List is " << temp->data << "  " << endl; 
              temp = temp->next;
          }
      }
  }
};

int main()
{
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();
    list.deleteAtFirst();
    cout << "After deleteAtFirst" << endl;
    list.display();
    list.deleteAtposition(2);
    cout << "After deleteAtposition" << endl;
    list.display();
    return 0;
}
