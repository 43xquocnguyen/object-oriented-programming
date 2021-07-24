#include <iostream>
using namespace std;

int main() {
    int x;

    try
    {
        cin >> x;
        if (x < 0) {
            throw new exception("Invalid");
        }
    }
    catch (const exception &excep)
    {
        cout << "Invalid value" << endl;
        cerr << excep.what() << endl;
    }
    
}