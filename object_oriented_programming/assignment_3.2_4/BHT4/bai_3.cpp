#include "stack.h"
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}
void PhanTichThuaSo(Stack *&stack, int n) {
    for (int i = 2; i <= n; i++)
    {
        while(n % i == 0 && isPrime(i)) 
        {
            Node *p = new Node(i);
            stack->Push(p);
            n /= i;
        }
    }
}
void XuatRa(Stack *&stack) {
    while (!stack->isEmpty())
    {
        int x;
        stack->Pop(x);
        cout << x;
        if (!stack->isEmpty()) {
            cout << " * ";
        }
        else {
            cout << "   ";
        }
    }
}
int main() {

    Stack *stack = new Stack;
    int n;
    cout << "PROGRAM CONVER SO NGUYEN TO (STACK)\n\n";
    cout << "ENTER THE NUMBER: ";
    cin >> n;
    PhanTichThuaSo(stack, n);
    cout << "\nRESULT: ";
    XuatRa(stack);
    delete stack;
    return 0;
}