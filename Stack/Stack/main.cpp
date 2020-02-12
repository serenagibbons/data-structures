#include <iostream>
#include <stack>
#include <string>
#include "Stack.h"
#include "Stack.cpp"

// function prototype
bool stackTest();

int main() {

	bool passed = stackTest();
	if (passed) {
		std::cout << "Passed the stack test" << std::endl;
	}
	else {
		std::cout << "Failed the stack test" << std::endl;
	}

	system("pause");
	return 0;
}

// test that the stack behaves appropriately
bool stackTest() {
	Stack<int> myStack;
	std::stack<int> stlStack;
	
	static const int TEST_SIZE = 1000;
	
	// check that top of each stack is the same after inserting values
	for (int i = 0; i < TEST_SIZE; ++i) {
		myStack.push(i);
		stlStack.push(i);
		if (myStack.peek() != stlStack.top()) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
			return false;
		}
	}

	// check that top of each stack is the same after removing top element 
	for (int i = 0; i < TEST_SIZE; ++i) {
		myStack.pop();
		stlStack.pop();
		// if top of the stacks are not the same, return false
		if (!myStack.isEmpty() && !stlStack.empty()) {
			if (myStack.peek() != stlStack.top()) {
				std::cerr << "Error on line " << __LINE__ << std::endl;
				return false;
			}
		}
	}
	
	return true;
}