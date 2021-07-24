#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};
struct Stack {
    Node *pTop;
    int count;
};
void Init(Stack &s) {
    s.pTop = NULL;
    s.count = 0;
}
Node *CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL)
        return 0;
    p->data = x;
    p->pNext = NULL;
    return p;
}
bool isEmpty(Stack s) {
    return (s.pTop == NULL);
}
bool Push(Stack &s, Node *p) {
    if (!p) {
        return 0;
    }
    if (!s.pTop) {
        s.pTop = p;
    }
    else {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    s.count++;
    return 1;
}
bool Pop(Stack &s, int &x) {
    if (isEmpty(s)) {
        return 0;
    }
    x = s.pTop->data;
    Node *p = s.pTop;
    s.pTop = s.pTop->pNext;
    s.count--;
    if (s.count == 0) {
        Init(s);
    }
    delete p;
    return 1;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}
void PhanTichThuaSo(Stack &storage, int n) {
    for (int i = 2; i <= n; i++)
    {
        while(n % i == 0 && isPrime(i)) 
        {
            Node *p = CreateNode(i);
            Push(storage, p);
            n /= i;
            cout << i << endl;
        }
    }
}
void XuatRa(Stack storage) {
    while (!isEmpty(storage))
    {
        int x;
        Pop(storage, x);
        cout << x;
        if (storage.count >= 1)
            cout << " * ";
    }
}
int main() {
    Stack storage;
    Init(storage);
    int n;
    cin >> n;
    PhanTichThuaSo(storage, n);
    XuatRa(storage);
    return 0;
}