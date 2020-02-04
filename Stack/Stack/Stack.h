#ifndef STACK_H
#define STACK_H

template <class T> class Stack {
private:
	int capacity;	// current capacity the stack can hold
	int size;		// current size of the stack and index of first empty spot
	static const int INITIAL_CAPACITY = 16;
	T *arrayStack;	// dynamically allocated array to hold stack items

public:
	Stack();	// constructor
	Stack(const Stack&);	// copy constructor
	~Stack();	// destructor
	inline int stackCapacity() { return capacity; }
	inline bool isFull() { return (size == capacity) ? true : false; }
	inline bool isEmpty() { return (size == 0) ? true : false; }
	void push(T);
	void pop();
	T peek();
};

#endif // !STACK_H
