#include "stack.h"

void ChuyenDoiCoSo(Stack *&stack, int coso, int n) {
    while (n != 0)
    {
        int x = n % coso;
        Node *p = new Node(x);
        stack->Push(p);
        n /= coso;
    }
}
void DisplayStack(Stack *stack) {
    while (!stack->isEmpty()) {
        int x;
        stack->Pop(x);
        if (x < 10)
            cout << x;
        else {
            cout << (char)(x + 55);
        }
    }
}

void Menu(Stack *&stack, int &n) {
    stack = new Stack;
    system("cls");
    cout << "NHAP SO CAN CHUYEN DOI: ";
    cin >> n;

    while (true)
    {
        system("cls");
        cout << "CHUONG TRINH CHUYEN DOI HE SO\n\n";
        cout << "1. CHUYEN DOI HE NHI PHAN\n";
        cout << "2. CHUYEN DOI HE BAT PHAN\n";
        cout << "3. CHUYEN DOI HE THAP LUC PHAN\n";
        cout << "4. NHAP LAI SO\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP LUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') {
            cout << "CHUONG TRINH KET THUC\n";
            break;
        }
        else if (lc == '1') {
            ChuyenDoiCoSo(stack, 2, n);
            cout << "HE NHI PHAN: ";
            DisplayStack(stack);
            cout << "\n";
        }
        else if (lc == '2') {
            ChuyenDoiCoSo(stack, 8, n);
            cout << "HE BAT PHAN: ";
            DisplayStack(stack);
            cout << "\n";
        }
        else if (lc == '3') {
            ChuyenDoiCoSo(stack, 16, n);
            cout << "HE THAP LUC PHAN: ";
            DisplayStack(stack);
            cout << "\n";
        }
        else if (lc == '4') {
            cout << "NHAP SO CAN CHUYEN DOI: ";
            cin >> n;
        }
        else {
            cout << "LUA CHON KHONG HOP LE. VUI LONG THU lAI\n";
        }
        system("pause");
    }
}
int main() {
    Stack *stack;
    int n = 0;
    Menu(stack, n);
    return 0;
}

