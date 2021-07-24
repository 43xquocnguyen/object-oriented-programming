#pragma once
#include <iostream>
using namespace std;

class Node
{
    friend class Stack;
    friend class Queue;
private:
    int data;
    Node *pNext;
public:
    Node();
    Node(int);
    ~Node();
};
