#include "linked_list.hpp"

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
  //  std::cout << "LIST DELETED";
}

void LinkedList::add(int data, Node* parent){
    Node* node = new Node();
    node->data = data;
    node->parent = parent;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}
