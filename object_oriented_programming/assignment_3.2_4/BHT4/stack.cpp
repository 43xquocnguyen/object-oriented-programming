#include "stack.h"

Stack::Stack() {
    this->pTop = NULL;
    this->n = 0;
}
Stack::~Stack() {
    delete pTop;
}
bool Stack::isEmpty() {
    return (this->pTop == NULL);
}
bool Stack::Push(Node *p) {
    if (!p) {
        return false;
    }
    else if (!this->pTop) {
        this->pTop = p;
    }
    else {
        p->pNext = this->pTop;
        this->pTop = p;
    }
    this->n++;
    return true;
}
bool Stack::Pop(int &x) {
    if (this->isEmpty()) {
        return false;
    }
    x = this->pTop->data;
    this->pTop = this->pTop->pNext;
    if (this->n == 1) {
        this->pTop = NULL;
    }
    this->n--;
    return true;
}