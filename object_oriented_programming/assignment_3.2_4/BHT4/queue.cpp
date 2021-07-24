#include "queue.h"

Queue::Queue() {
    this->pFont = this->pRear = NULL;
}
Queue::~Queue() {
    delete this->pFont;
    delete this->pRear;
}
bool Queue::isEmpty() {
    return (this->pFont == NULL);
}
bool Queue::enQueue(Node *p) {
    if (!p) {
        return false;
    }
    else if (this->pFont == NULL) {
        this->pFont = this->pRear = p;
    }
    else {
        this->pRear->pNext = p;
        this->pRear = p;
    }
    this->n++;
    return true;
}
bool Queue::deQueue(int &x) {
    if (this->isEmpty()) {
        return false;
    }
    x = this->pFont->data;
    this->pFont = this->pFont->pNext;
    if (this->n == 1) {
        this->pFont = NULL;
    }
    if (this->pFont == NULL)
        this->pRear = NULL;
    this->n--;
    return true;
}