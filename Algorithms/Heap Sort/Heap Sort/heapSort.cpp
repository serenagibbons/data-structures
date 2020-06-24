#include <iostream>
#include "heapSort.h"

// fix node i in heap arr of length n
void fixTheHeap(int arr[], int n, int i) {

	// get index of left and right children of node i
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if (left > n - 1) {
		// node i has no children
		return;
	}

	int largest = i;

	// compare largest with left child
	if (arr[left] > arr[largest]) {
		// fixTheHeap already checked that left child exists
		largest = left;
	}

	// compare largest with right child
	if (right < n && arr[right] > arr[largest]) { 
		// must check that right child exists
		largest = right;
	}

	// if largest changed
	if (largest != i)
	{
		// swap the node with the larger child
		std::swap(arr[i], arr[largest]);
		// recursively fix the smaller heap
		fixTheHeap(arr, n, largest);
	}
}

// main heap sort function - takes an array and the the length of the array
void heapSort(int arr[], int length) {
	// build the heap
	for (int i = length/2 - 1; i >= 0; --i) { 
		// can start at length/2 -1 because all leaf nodes have no children
		fixTheHeap(arr, length, i);
	}

	// sort by repeatedly wrecking the heap and fixing it
	for (int i = length - 1; i > 0; --i) { // after looping, element 0 will be the smallest
		// swap the last element with the first
		std::swap(arr[0], arr[i]);	// i - 1 is now the end of the heap
		// fix the heap
		fixTheHeap(arr, i, 0);
	}
	
}
