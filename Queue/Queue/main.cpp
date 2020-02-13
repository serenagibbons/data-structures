#include <iostream>
#include <queue>
#include "Queue.h"
#include "Queue.cpp"

// function prototype
bool queueTest();

int main() {

	bool passed = queueTest();

	if (passed) {
		std::cout << "Passed the queue test\n";
	}
	else {
		std::cout << "Failed the queue test\n";
	}
	
	system("pause");
	return 0;
}


bool queueTest() {
	Queue<int> myQueue;
	std::queue<int> stlQueue;

	static const int TEST_SIZE = 100000;

	// check that top of each stack is the same after inserting values
	for (int i = 0; i < TEST_SIZE; ++i) {
		myQueue.enqueue(i);
		stlQueue.push(i);
		if (myQueue.peek() != stlQueue.front()) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
			return false;
		}
	}

	// check that top of each stack is the same after removing top element 
	for (int i = 0; i < TEST_SIZE; ++i) {
		myQueue.dequeue();
		stlQueue.pop();
		// if top of the stacks are not the same, return false
		if (!myQueue.isEmpty() && !stlQueue.empty()) {
			if (myQueue.peek() != stlQueue.front()) {
				std::cerr << "Error on line " << __LINE__ << std::endl;
				return false;
			}
		}
	}

	return true;
}