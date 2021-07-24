#include "node.h"

Node::Node()
{
    this->data = 0;
    this->pNext = NULL;
}
Node::Node(int data)
{
    this->data = data;
    this->pNext = NULL;
}
Node::~Node()
{
    delete[] this->pNext;
}