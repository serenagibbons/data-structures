#include "Node.h"

struct Node {
	int data;
	Node *next;
};

Node *head;	// declare head Node

void display() {
	if (head == NULL) {
		cout << "The list is empty.\n";
	}
	else {
		Node *p = head;
		while (p != NULL) {		// while the current Node is not null
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
		while (p->next != NULL) {	// while the current Node is not the tail
			p = p->next;			// traverse the list
		}
		Node *n = new Node;
		p->next = n;				// add the Node to the linked list
		n->data = x;
		n->next = NULL;
	}
}

bool search(int x) {
	Node *p;	// temporary pointer
	p = head;

	while (p != NULL) {	// while the current Node is not null
		if (p->data == x) {
			cout << "The value " << x << " was found in the list.\n";
			return true;	// if the Node data is equal to search key x, return true
		}
		p = p->next;
	}

	cout << "The value " << x << " was not found in the list.\n";
	return false;			// else return false
}

void remove(int x) {
	Node *p = head;	// temporary pointer
	Node *t = head;	// trailing pointer
	
	if (head == NULL) {	
			cout << "Remove failed: The list is empty.\n";
	}
	else if (head->data == x) {	// if the search value is the head
		cout << "Removing value " << x << endl;
		head = head->next;
		delete p;
		return;
	}

	while (p != NULL && p->data != x) {	// while the current node is not null or the tail
		t = p;
		p = p->next;
	}
	if (p == NULL) {	// the list was traversed without finding the search value
		cout << "The value " << x << " was not found in the list.\n";
		return;
	}
	cout << "Removing value " << x << endl;

	t->next = p->next;
	delete p;
}