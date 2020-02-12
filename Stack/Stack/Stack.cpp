#include <iostream>
#include <new>
#include <string>
#include "Stack.h"

template <class T> Stack<T>::Stack()
	: size(0),
	capacity(INITIAL_CAPACITY)
{
	// initialize empty arrayStack of initial capacity
	arrayStack = new T[capacity];
}

template <class T> Stack<T>::Stack(const Stack& otherStack) 
	: size(otherStack.size),
	capacity(otherStack.capacity) 
{
	arrayStack = new T[capacity];
	// copy data from otherStack's arrayStack into current object's arrayStack
	for (int i = 0; i < size; ++i) {
		arrayStack[i] = otherStack.arrayStack[i];
	}
}

template <class T> Stack<T>::~Stack() {
	// deallocate memory
	delete[] arrayStack;
}

template <class T> void Stack<T>::push(T item) {
	if (isFull()) {
		T *tempStack;
		int newCapacity = capacity * 2;
		try {
			// allocate more memory
			tempStack = new T[newCapacity];
		}
		catch (std::bad_alloc& ba) {
			// print exception to console error
			std::cerr << ba.what() << std::endl;
			exit(EXIT_FAILURE);
		}
		// copy items into new array
		for (int i = 0; i < size; ++i) {
			tempStack[i] = arrayStack[i];
		}
		// delete old stack
		delete[] arrayStack;
		// reassign arrayStack to the temporary stack
		arrayStack = tempStack;
		// update the capacity
		capacity = newCapacity;
	}
	// insert new item and incremenet size
	arrayStack[size++] = item;
}

template <class T> void Stack<T>::pop() {
	if (isEmpty()) {
		exit(EXIT_FAILURE);
	}
	// remove top item of the stack
	--size;
}

template <class T> T Stack<T>::peek() {
	if (isEmpty()) {
		exit(EXIT_FAILURE);
	}
	// return top of the stack
	return arrayStack[size-1];
}