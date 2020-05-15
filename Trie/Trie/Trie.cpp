#include <iostream>
#include <string>
#include <map>
#include "Trie.h"

// constructor
Trie::Trie() {
	try {
		root = new TrieNode();
	}
	catch (std::bad_alloc &ba) {
		std::cerr << ba.what() << std::endl;
		exit(0);
	}
}

// helper function to recursively copy all children
TrieNode * copyTrie(const TrieNode * copyNode) {
	if (0 == copyNode) {
		return 0;
	}
	TrieNode * newNode;
	// prefix traversal--process node before its children
	try {
		newNode = new TrieNode();
	}
	catch (std::bad_alloc) {
		return 0;
	}

	// for each child of the node to copy, call copyTrie
	for (int i = 0; i < ALPHABET; ++i) {
		newNode->children[i] = copyTrie(copyNode->children[i]);
	}

	return newNode;
}

// copy constructor
Trie::Trie(const Trie& otherTrie) {
	root = copyTrie(otherTrie.root);
}

// helper function to recursively delete all children
void deleteAllChildren(TrieNode *node) {
	if (node != 0) {
		// if the node has no children, delete the node
		if (node->children == 0) {
			delete(node);
			return;
		}
		// for each child of the node, call deleteAllChildren
		for (TrieNode* child : node->children) {
			deleteAllChildren(child);
		}
	}
}

// destructor
Trie::~Trie() {
	deleteAllChildren(root);
	root = 0;
}

// insert method
void Trie::insert(std::string word) {
	TrieNode *current = root;

	for (int i = 0; i < (int)word.size(); ++i) {
		if (current->children[word[i] - 'a'] == 0) {
			// there is no node in the trie corresponding to the letter of word so allocate a new TrieNode
			try {
				current->children[word[i] - 'a'] = new TrieNode();
			}
			catch (std::bad_alloc &ba) {
				std::cerr << ba.what() << std::endl;
				exit(0);
			}
		}
		// move to next node
		current = current->children[word[i] - 'a'];
	}
	// mark the last node visited as the end of the word
	current->isWord = true;

}

// search method
bool Trie::search(std::string word) {
	if (isEmpty()) {
		return false;
	}
	TrieNode *current = root;

	for (int i = 0; i < (int)word.size(); ++i) {
		if (current->children[word[i] - 'a'] != 0) {
			// go to next node
			current = current->children[word[i] - 'a'];
		}
		else {
			return false;
		}
	}
	return current->isWord;
}

// check if a node has children
bool hasChildren(TrieNode* node) {
	for (int i = 0; i < ALPHABET; ++i) {
		if (node->children[i]) {
			// if the node has any children return true
			return true;
		}
	}
	// else return false
	return false;
}

// remove method stub
void Trie::remove(std::string word) {
	
}

// helper function to find if a prefix is the start of a word
bool findWord(TrieNode* node) {
	if (node == 0) {
		return false;
	}
	if (node->isWord) {
		return true;
	}

	bool isWord = false;
	for (int i = 0; i < 26; i++) {
		if (node->children[i] != 0) {
			if (findWord(node->children[i])) {
				isWord = true;
			}
		}
	}
	return isWord;
}

// starts with method
bool Trie::startsWith(std::string prefix) {
	if (root == 0) {
		return false;
	}
	TrieNode *current = root;

	// search for prefix
	for (int i = 0; i < (int)prefix.size(); ++i) {
		if (current->children[prefix[i] - 'a'] != 0) {
			// go to next node
			current = current->children[prefix[i] - 'a'];
		}
		else {
			return false;
		}
	}

	// search for ending of a word
	return findWord(current);
}
