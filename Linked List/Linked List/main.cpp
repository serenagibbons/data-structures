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
	remove(5);
	display();
	remove(2);
	remove(4);
	display();
	remove(3);
	display();
	   	 
	system("pause");
	return 0;
}
