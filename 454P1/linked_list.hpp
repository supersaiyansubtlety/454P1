#pragma once

#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;
    Node* parent;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;
    
    LinkedList();
    ~LinkedList();
    void add(int data, Node* parent);
    void print();
};
