#include <iostream>
using namespace std;
#include "Trie.h"


int main() {
	myTrie t;
	t.insert("and");
	t.insert("are");
	t.insert("dot");

	cout << t.search("and") << endl;

	t.remove("and");
	cout << t.search("and") << endl;
}


