#include <iostream>
using namespace std;

void operator<<(ostream &os, const char *c) {
    os.write("Entering the Hello program saying...\nHello, world.\nThen exiting... ", 67);
}

int main(){
	cout << "Hello, world.\n";
}
