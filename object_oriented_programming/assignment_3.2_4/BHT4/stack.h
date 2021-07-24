#pragma once
#include "node.h"

class Stack
{
private:
    Node *pTop;
    int n;
public:
    Stack();
    ~Stack();
    
    bool isEmpty();
    bool Push(Node *);
    bool Pop(int &);
};