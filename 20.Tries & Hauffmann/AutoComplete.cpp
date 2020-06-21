// #include "TrieNode.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
TrieNode* searchNode(TrieNode* root,string pattern)
{
    if(pattern.size() == 0)
    {
       return root;
    }
    int index = pattern[0]-'a';
    TrieNode* child;
    if(root->children[index] == NULL)
    {
        return NULL;
    }

    child = root->children[index];
    return searchNode(child,pattern.substr(1));
}
void allPosibleOutputs(TrieNode *root,string pattern,string output)
{
    if(root->isTerminal == true)
    {
        cout<<pattern+output<<endl;
    }
    for(int i = 0;i<26;i++)
    {
        if(root->children[i]!=NULL)
        {
           TrieNode* child = root->children[i];
           allPosibleOutputs(child,pattern,output+root->children[i]->data);
        }
    }
}
void autoComplete(vector<string> input, string pattern) {
    for(int i = 0;i<input.size();i++)
    {
        insertWord(input[i]);
    }

    TrieNode* check = searchNode(root,pattern);
    if(check == NULL)
    {
        return;
    }
   allPosibleOutputs(check,pattern,"");

}


};

int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
