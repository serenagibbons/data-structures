#include <iostream>
#include "heapSort.h"

int main() {

	const int SIZE = 10;
	int theArray[SIZE] = { 678, 34, 54, 24, 864, 234, 45, 42, 96, 48 };
	
	// sort the array
	heapSort(theArray, SIZE);
	
	// print the sorted array
	for (int i = 0; i < SIZE; ++i) {
		std::cout << theArray[i] << std::endl;
	}

	system("pause");
	return 0;
}