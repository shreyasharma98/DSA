#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
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
	string reverse(string input)
	{
	    int i = 0 , j = input.size()-1;
	    while(i<j)
        {
            swap(input[i],input[j]);
            i++;j--;
        }

    return input;
	}
bool searchWord(TrieNode *root,string word)
    {
        if(word.size() == 0)
        {
           return true;
        }

        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL)
        {
            return true;
        }
        else
        {
           return false;
        }
       //  return searchWord(child,word.substr(1));
    }
    bool search(string word)
    {
       return searchWord(root,word);
    }
	bool findIfPalindromePair(vector<string> arr) {
		for(int i = 0;i<arr.size();i++)
        {
            string input = reverse(arr[i]);
            insertWord(input);
        }

        for(int i = 0;i<arr.size();i++)
        {
            bool check = search(arr[i]);
            if(check){return true;}
        }
        return false;
	}
};

int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
