#ifndef QUEUE_H
#define QUEUE_H

template <class T> class Queue {
private:
	int capacity;	// current capacity the queue can hold
	int oldestIndex;	// index of the oldest element
	int nextInsertIndex;	// index of the first empty spot

	static const int INITIAL_CAPACITY = 16;
	T *arrayQueue;	// dynamically allocated array to hold queue items
	inline int advanceIndex(int index) const { return((index + 1) % queueCapacity()); } // give the address of the next index

public:
	Queue();	// constructor
	Queue(const Queue&);	// copy constructor
	~Queue();	// destructor
	inline int queueCapacity() const { return capacity; }
	inline bool isEmpty() const { return (oldestIndex == nextInsertIndex); }
	inline bool isFull() const { return (advanceIndex(nextInsertIndex) == oldestIndex); }
	void enqueue(T);
	void dequeue();
	T peek();
};

#endif // !QUEUE_H
