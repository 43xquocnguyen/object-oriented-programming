#include "ListMenu.h"

int main() {
	hideCur();
	resizeConsole(900, 750);
	
	ListMenu a;
	a.Init();
	a.MainMenu();

	cin.get();
	return 0;
}