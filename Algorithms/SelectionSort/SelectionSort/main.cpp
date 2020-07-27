#include <iostream>
#include <string>
using namespace std;

void selectionSort(int[], int);

int main() {

	int list[] = {3, 5, 7, 2, 1, 6, 8, 8, 3};
	int SIZE = 9;

	selectionSort(list, SIZE);
	for (int i = 0; i < SIZE; i++)
		cout << list[i] << "\n";

	system("pause");
	return 0;
}

void selectionSort(int unsortedList[], int size) {

	for (int line = 0; line < size - 1; line++) {
		int smallestIndex = line;
		for (int j = line; j < size; j++) {
			if (unsortedList[j] < unsortedList[smallestIndex]) {
				smallestIndex = j;
			}
			// swap unsortedList[smallestIndex] & unsortedList[line];
			int tempSmallest = unsortedList[smallestIndex];
			unsortedList[smallestIndex] = unsortedList[line];
			unsortedList[line] = tempSmallest;
		}
	}

}