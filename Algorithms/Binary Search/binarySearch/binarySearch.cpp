#include <iostream>
#include "binarySearch.h"

int binarySearch(int arr[], const int SIZE, int target) {
	int l = 0;
	int r = SIZE - 1;

	while (l <= r) {
		// same as (l+r)/2 to avoid overflow
		int m = l + (r - l) / 2;

		if (arr[m] == target) {
			return m;
		}
		else if (arr[m] > target) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	// return -1 if the target was not found
	return -1;
}

// recursive binary search
int binarySearch(int arr[], int l, int r, int target) {
	if (l > r) {
		// return -1 if the target was not found
		return -1;
	}

	// same as (l+r)/2 to avoid overflow
	int m = l + (r - l) / 2;

	if (arr[m] == target) { return m; }

	if (arr[m] > target) {
		binarySearch(arr, l, m - 1, target);
	}
	else {
		binarySearch(arr, m + 1, r, target);
	}
}