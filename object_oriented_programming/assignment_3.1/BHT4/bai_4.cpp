#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};
struct Stack
{
    Node *pTop;
};

void CreateStack(Stack &s) {
    s.pTop = NULL;
}
Node *CreateNode(int data) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "KHONG DU BO NHO\n";
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    return p;
}
bool EmptyStack(Stack s) {
    if (s.pTop == NULL) {
        return 1;
    }
    return 0;
}
bool Push(Stack &s, Node *p) {
    if (p == NULL) {
        return false;
    }
    if (EmptyStack(s)) {
        s.pTop = p;
    }
    else {
        p->pNext = s.pTop;
		s.pTop = p;
    }
    return true;
}
bool Pop(Stack &s, int &x) {
    if (EmptyStack(s))
    {
        return 0;
    }
    Node *p = s.pTop;
    s.pTop = s.pTop->pNext;
    x = p->data;
    delete p;
    return true;
}
void ChuyenDoiCoSo(Stack &s, int coso, int n) {
    while (n != 0)
    {
        int x = n % coso;
        Node *p = CreateNode(x);
        Push(s, p);
        n /= coso;
    }
}
void DisplayStack(Stack s) {
    while (!EmptyStack(s)) {
        int x;
        Pop(s, x);
        if (x < 10)
            cout << x;
        else {
            cout << (char)(x + 55);
        }
    }
}

void Menu(Stack &s, int &n) {

    system("cls");
    cout << "NHAP SO CAN CHUYEN DOI: ";
    cin >> n;

    while (true)
    {
        system("cls");
        cout << "1. CHUYEN DOI HE NHI PHAN\n";
        cout << "2. CHUYEN DOI HE BAT PHAN\n";
        cout << "3. CHUYEN DOI HE THAP LUC PHAN\n";
        cout << "4. NHAP LAI SO\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP LUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();

        if (lc == '0') {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            break;
            system("pause;");
        }
        else if (lc == '1') {
            system("cls");
            ChuyenDoiCoSo(s, 2, n);
            cout << "HE NHI PHAN: ";
            DisplayStack(s);
            system("pause");
        }
        else if (lc == '2') {
            system("cls");
            ChuyenDoiCoSo(s, 8, n);
            cout << "HE BAT PHAN: ";
            DisplayStack(s);
            system("pause");
        }
        else if (lc == '3') {
            system("cls");
            ChuyenDoiCoSo(s, 16, n);
            cout << "HE THAP LUC PHAN: ";
            DisplayStack(s);
            system("pause");
        }
        else if (lc == '4') {
            system("cls");
            cout << "NHAP SO CAN CHUYEN DOI: ";
            cin >> n;
            system("pause");
        }
        else {
            system("cls");
            cout << "LUA CHON KHONG HOP LE. VUI LONG THU lAI\n";
            system("pause");
        }
    }
}
int main() {
    Stack s;
    int n = 0;
    Menu(s, n);
    return 0;
}

