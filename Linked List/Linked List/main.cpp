#include <iostream>
#include "Node.h"
using namespace std;

int main() {
	// preliminary code to test functions
	insert(5);
	insert(3);
	insert(2);
	display();
	search(5);
	search(4);
	search(2);
	search(3);
	display();
	remove(4);
	remove(3);
	display();
	remove(2);
	display();
	   	 
	system("pause");
	return 0;
}
