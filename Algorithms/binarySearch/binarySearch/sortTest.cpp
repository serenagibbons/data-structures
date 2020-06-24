#include <iostream>
#include "binarySearch.h"

int main() {
	const int SIZE = 20;
	int arr[] = { -4, 0, 1, 3, 4, 5, 7, 8, 10, 11, 12, 13, 15, 19, 22, 23, 24, 28, 30, 31 };

	// recursive binary search
	std::cout << binarySearch(arr, 0, SIZE - 1, 7) << std::endl;

	system("pause");
	return 0;
}