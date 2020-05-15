#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"

int main() {
	// instantiate trie
	Trie trie;

	// preliminary tests
	trie.insert("apple");
	std::cout << trie.search("apple");	// should return true
	std::cout << trie.startsWith("app"); // should return true
	std::cout << trie.search("app"); // should return false
	trie.insert("app");
	std::cout << trie.search("app"); // should return true
	std::cout << trie.search("apples"); // should return false
	trie.insert("apples");
	std::cout << trie.search("apples"); // should return true

	system("pause");
	return 0;
}