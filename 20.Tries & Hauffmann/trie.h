#include"trieClass.h"
#include<string>
class myTrie
{
    TrieNode *root;

public:
    myTrie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(string word,TrieNode *root)
    {
        //Base case
        if(word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //small calculation
        int index = word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //Recusion

        insertWord(word.substr(1),child);

    }
    void insert(string word)
    {
        insertWord(word,root);
    }
    bool searchWord(TrieNode *root,string word)
    {
        if(word.size() == 0)
        {
           return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] == NULL)
        {
            return false;
        }
        else
        {
            child = root->children[index];
        }
         return searchWord(child,word.substr(1));
    }
    bool search(string word)
    {
       return searchWord(root,word);
    }
    void removeWord(TrieNode *root,string word)
    {
        if(word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index] == NULL)
        {
            return ;
        }
        else
        {
            child = root->children[index];
        }
        removeWord(child,word.substr(1));
        if(child->isTerminal == false)
        {
            for(int i = 0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                    return;
            }
            delete child;
            root -> children[index] = NULL;
        }


    }
    void remove(string word)
    {
        removeWord(root,word);
    }
};
