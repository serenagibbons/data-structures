#include <iostream>
#include <new>
#include <string>
#include "Queue.h"

template <class T> Queue<T>::Queue()
	: oldestIndex(0),
	nextInsertIndex(0),
	capacity(INITIAL_CAPACITY)
{
	arrayQueue = new T[capacity];
}

template <class T> Queue<T>::Queue(const Queue& otherQueue)
	: oldestIndex(0),
	nextInsertIndex(0),
	capacity(otherQueue.capacity)
{
	arrayQueue = new T[capacity];
	for (int i = otherQueue.oldestIndex; i != otherQueue.nextInsertIndex; i = otherQueue.advanceIndex(i)) {
		// copy the item in position i in otherQueue into current object's nextInsertIndex
		arrayQueue[nextInsertIndex] = otherQueue.arrayQueue[i];
		nextInsertIndex = advanceIndex(nextInsertIndex);
	}
}

template <class T> Queue<T>::~Queue() {
	// deallocate memory
	delete[] arrayQueue;
}

template <class T> void Queue<T>::enqueue(T item) {
	if (isFull()) {
		T *temp;
		int newCapacity = capacity * 2;
		try {
			temp = new T[newCapacity];
		}
		catch (std::bad_alloc &ba) {
			std::cerr << ba.what() << std::endl;
			exit(EXIT_FAILURE);
		}
		// copy contents in old array into new array
		int i;
		for (i = 0; oldestIndex != nextInsertIndex; ++i) {
			temp[i] = arrayQueue[oldestIndex++];
			// 			oldestIndex = advanceIndex(oldestIndex);
		}	
		// new oldestIndex is 0 and nextInsertIndex is now i
		oldestIndex = 0;
		nextInsertIndex = i;
		// delete the old array memory
		delete[] arrayQueue;
		// point data to the newly allocated array
		arrayQueue = temp;
		// update capacity
		capacity = newCapacity;
	}
	arrayQueue[nextInsertIndex] = item;
	nextInsertIndex = advanceIndex(nextInsertIndex);
}

template <class T> void Queue<T>::dequeue() {
	if (isEmpty()) {
		exit(EXIT_FAILURE);
	}
	oldestIndex = advanceIndex(oldestIndex);
}

template <class T> T Queue<T>::peek() {
	if (isEmpty()) {
		exit(EXIT_FAILURE);
	}
	return oldestIndex;
}