#include "stack.h"
#include <vector>

void MENU(Stack *stack) {
    while (true)
    {
        system("cls");
        cout << "PROGRAM PUSH & POP (STACK)\n\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. POP ALL\n\n";
        cout << "YOUR CHOOSE: ";

        char choose;
        cin >> choose;
        cin.ignore();
        system("cls");

        if (choose == '1') {
            int x;
            cout << "PUSH: ";
            cin >> x;
            Node *p = new Node(x);
            stack->Push(p);
        }
        else if (choose == '2') {
            int x;
            if (stack->Pop(x)) {
                cout << "POP: " << x << endl;
            }
            else {
                cout << "EMPTY STACK\n";
            }
        }
        else if (choose == '3') {
            int i = 0;
            while (true)
            {
                int x;
                if (stack->Pop(x)) {
                    cout << "POP " << i + 1 << ": " << x << endl;
                    i++;
                }
                else break;
            }
            if (!i) cout << "EMPTY STACK\n";
        }
        else {
            cout << "NOT FOUND OPTION!\n";
        }
        system("pause");
    }
}
int main() {
    Stack *stack = new Stack;
    MENU(stack);
    delete stack;
    return 0;
}