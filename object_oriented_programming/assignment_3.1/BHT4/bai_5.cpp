#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};
struct Queue {
    Node *pFont;
    Node *pRear;
    int count;
};
void CreateQueue(Queue &q) {
    q.pFont = q.pRear = NULL;
    q.count = 0;
}
Node *CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL)
        return 0;
    p->data = x;
    p->pNext = NULL;
    return p;
}
bool isEmpty(Queue q) {
    return q.pFont == NULL;
}
bool enQueue(Queue &q, Node *p) {
    if (!p) {
        return 0;
    }
    // rong
    if (q.pRear == NULL) {
        q.pFont = q.pRear = p;
        q.count++;
    }
    // khong rong
    else {
        q.pRear->pNext = p;
        q.pRear = p;
        q.count++;
    }
    return 1;
}
bool deQueue(Queue &q, int &x) {
    if (isEmpty(q)) {
        return 0;
    }
    x = q.pFont->data;
    Node *p = q.pFont;
    q.pFont = q.pFont->pNext;
    if (q.count == 1)
        CreateQueue(q);
    if (q.pFont == NULL)
        q.pRear = NULL;
    delete p;
    return 1;
}

void MENU(Queue &q) {
    while (true) {
        system("cls");
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. POP HET\n\n";
        cout << "NHAP LUA CHON: ";

        char luachon;
        cin >> luachon;
        cin.ignore();

        if (luachon == '1') {
            system("cls");
            int x;
            cin >> x;
            Node *p = CreateNode(x);
            enQueue(q, p);
            system("pause");
        }

        if (luachon == '2') {
            system("cls");
            int x;
            deQueue(q, x);
            cout << "POP: " << x;
            system("pause");
        }
    }
}
int main() {
    Queue q;
    CreateQueue(q);
    MENU(q);
    return 0;
}