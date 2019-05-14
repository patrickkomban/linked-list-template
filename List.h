#include <string>
using namespace std;

//Purpose: A template of a linked list. To implement a singly-linked
//            list to store T data types
//Operations:
//          -operator+=: adds the course given in the argument to the linked list
//
//          -print: prints the data of each node in the linked list, and
//              in addition to that, also prints out the head and tail of that
//              particular list.

template <class T>
class List
{
  public:
    List();
    ~List();
    void print();
    List<T>& operator+=(T);

  protected:

    class Node
    {
      friend class List<T>;
      public:
        T         data;
        Node*     next;
    };

    Node* head; //head node: indicates the beginning of the list
    Node* tail; //tail node: incidcates the end of the list
};

template <class T>
List<T>::List() : head(NULL), tail(NULL) { }

template <class T>
List<T>::~List()
{
  Node* curNode = head;
  Node* nextNode;

  while (curNode != NULL) {
    nextNode = curNode->next;
    delete curNode->data;
    delete curNode;
    curNode = nextNode;
  }
}

template <class T>
List<T>& List<T>::operator+=(T addThis)
{
  Node* tmpNode;
  Node* curNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = addThis;
  tmpNode->next = NULL;

  curNode = head;
  prevNode = NULL;

  if (curNode == NULL) {
    head = tmpNode;
    tail = tmpNode;
    return *this;
  }

  while (curNode != NULL) {
    if (addThis->lessThan(curNode->data))
      break;
    prevNode = curNode;
    curNode = curNode->next;
  }

  if (curNode == head) {
    tmpNode->next = head;
    head = tmpNode;
    return *this;
  }

  tmpNode->next = curNode;
  prevNode->next = tmpNode;

  if (tmpNode->next == NULL)
    tail = tmpNode;

  return *this;
}

template <class T>
void List<T>::print()
{
  Node* curNode = head;
  Node* prevNode = NULL;

  if (curNode == NULL) {
    cout << "List is empty!" << endl;
    return;
  }

  while (curNode != NULL) {
    curNode->data->print();
    prevNode = curNode;
    curNode = curNode->next;
  }


  cout << endl;
  cout << "** HEAD: ";
  head->data->print();
  cout << "** TAIL: ";
  tail->data->print();
  cout << endl;

}
