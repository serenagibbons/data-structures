#include "Node.h"

struct Node {
	int data;
	Node *next;
};

Node *head;	// declare head node

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

bool search(int x) {
	Node *p;	// temporary pointer
	p = head;

	while (p != NULL) {	// while the current node is not null
		if (p->data == x) {
			cout << "The value " << x << " was found in the list.\n";
			return true;	// if the node data is equal to search key x, return true
		}
		p = p->next;
	}

	cout << "The value " << x << " was not found in the list.\n";
	return false;			// else return false
}

bool remove(int x) {
	Node *p;	// temporary pointer
	Node *t = NULL;	// trailing pointer
	p = head;

	if (p == NULL) {
		cout << "The list is empty.\n";
		return false;
	}
	else if (search(x) == false ) {
		cout << "The list does not contain " << x << endl;
		return false;
	}
	else {
		while (p != NULL) {	// while the current node is not null
	
			if (p->data == x) {		
				t->data = (p->next)->data;
				t->next = p->next;
			}
			t = p;
			p = p->next;
		}
		return true;
	}
}