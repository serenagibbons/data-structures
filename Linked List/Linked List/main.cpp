#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *head;	// declare head node

int main() {

	system("pause");
	return 0;
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
		while (p->next != NULL) {	// while the node is not the tail
			p = p->next;			// traverse the list
		}
		Node *n = new Node;
		p->next = n;				// add the node to the linked list
		n->data = x;
		n->next = NULL;
	}
}
