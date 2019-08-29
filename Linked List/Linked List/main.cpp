#include <iostream>
using namespace std;

// function prototypes
void display();
void insert(int x);
void search(int x);

struct Node {
	int data;
	Node *next;
};

Node *head;	// declare head node

int main() {
	// preliminary code to test functions
	insert(5);
	insert(3);
	insert(2);
	display();
	search(5);
	search(4);
	search(2);
	search(3);
	   	 
	system("pause");
	return 0;
}

void display() {
	if (head == NULL) {
		cout << "No nodes have been added to the linked list yet.\n";
	}
	else {
		Node *p = head;
		while (p != NULL) {		// while the current node is not null
			cout << p << "\t" << p->data << endl;
			p = p->next;		// traverse the list
		}
	}
}

void insert(int x) {
	if (head == NULL) {
		Node *n = new Node;
		n->data = x;
		n->next = NULL;
		head = n;
	}
	else {
		Node *p;	// temporary pointer
		p = head;
		while (p->next != NULL) {	// while the current node is not the tail
			p = p->next;			// traverse the list
		}
		Node *n = new Node;
		p->next = n;				// add the node to the linked list
		n->data = x;
		n->next = NULL;
	}
}

void search(int x) {
	Node *p;	// temporary pointer
	p = head;
	bool found = false;

	while (p != NULL) {	// while the current node is not null
		if (p->data == x)	// if the node data is equal to search key x
			found = true;	// set found to true
		p = p->next;			
	}

	if (found == true)
		cout << "The value " << x << " was found in the list.\n";
	else
		cout << "The value " << x << " was not found in the list.\n";
}
