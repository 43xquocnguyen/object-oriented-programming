#include <iostream>
using namespace std;

class Stack {
private:
    int a[1000];
    int top;
public:
    Stack();
    bool Push(int x);
    int Pop();
    int Peek();
    bool IsEmpty();
};
Stack::Stack() {
    this->top = -1;
}
bool Stack::Push(int x)
{
    if (this->top >= 1000) {
        cout << "Stack het cho chua!";
        return false;
    }
    else {
        a[this->top++] = x;
        cout << x << "Them thanh cong\n";
        return true;
    }
}
int Stack::Pop()
{
    if (this->top < 0) {
        cout << "Stack rong!";
        return 0;
    }
    else {
        int x = a[this->top--];
        return x;
    }
}
int Stack::Peek()
{
    if (this->top < 0) {
        cout << "Stack rong";
        return 0;
    }
    else {
        int x = a[this->top];
        return x;
    }
}
bool Stack::IsEmpty()
{
    return (this->top < 0);
}

bool IsPrime(int n) {
    if (n <= 0)
        return 0;
    if (n <= 2 && n >= 1)
        return 1;
    for (int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
void PTTSNT_Stack(Stack &s, int n) {
    for (int i = 2; i < n; i++)
    {
        if (IsPrime(i)) {
            if(n % i == 0) {
                s.Push(i);
                n /= i;
                cout << i;
            }
        }
    }
    while (!s.IsEmpty())
    {
        int x = s.Pop();
        cout << x << " * ";
    }
    
}

int main() {
    Stack s;
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "PHAN TICH: \n";
    PTTSNT_Stack(s, n);
    return 0;
}