#pragma once
#include "node.h"

class Queue
{
private:
    Node *pFont;
    Node *pRear;
    int n;
public:
    Queue();
    ~Queue();

    bool isEmpty();
    bool enQueue(Node *);
    bool deQueue(int &);
};
