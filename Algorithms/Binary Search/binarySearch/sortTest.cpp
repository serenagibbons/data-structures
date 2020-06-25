#include <iostream>
#include <string>
#include "binarySearch.h"

// function prototypes
bool iterativeSortTest(int arr[], const int SIZE);
bool recursiveSortTest(int arr[], const int SIZE);

int main() {
	const int SIZE = 20;
	int arr[] = { -4, 0, 1, 3, 4, 5, 7, 8, 10, 11, 12, 13, 15, 19, 22, 23, 24, 28, 30, 31 };
	
	// call iterativeSortTest
	std::string result = "Fail";
	if (iterativeSortTest(arr, SIZE)) {
		result = "Pass";
	}
	std::cout << "Iterative binary search: " << result << std::endl;

	// call recursiveSortTest
	result = "Fail";
	if (recursiveSortTest(arr, SIZE)) {
		result = "Pass";
	}
	std::cout << "Recursive binary search: " << result << std::endl;

	system("pause");
	return 0;
}

// test iterative binary search
bool iterativeSortTest(int arr[], const int SIZE) {

	for (int i = 0; i < SIZE; i++) {
		if (binarySearch(arr, 0, SIZE - 1, arr[i]) != i) {
			return false;
		}
	}

	// numbers not included in arr
	int test[] = { -3, -2, -1, 2, 6, 9, 14, 16, 17, 18, 20, 21, 25, 26, 27, 29, 32, 33, 34, 35 };
	for (int i = 0; i < SIZE; i++) {
		if (binarySearch(arr, 0, SIZE - 1, test[i]) != -1) {
			return false;
		}
	}

	
	return true;
}

// test recursive binary search
bool recursiveSortTest(int arr[], const int SIZE) {
	
	for (int i = 0; i < SIZE; i++) {
		if (binarySearch(arr, SIZE, arr[i]) != i) {
			return false;
		}
	}

	// numbers not included in arr
	int test[] = { -3, -2, -1, 2, 6, 9, 14, 16, 17, 18, 20, 21, 25, 26, 27, 29, 32, 33, 34, 35 };
	for (int i = 0; i < SIZE; i++) {
		if (binarySearch(arr, SIZE, test[i]) != -1) {
			return false;
		}
	}

	return true;
}