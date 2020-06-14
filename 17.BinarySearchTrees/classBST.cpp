#include<iostream>
#include "BinaryTree.h"
using namespace std;

class BST
{
    bool hasData(int x,BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            return false;
        }
        if(node->data == x)
        {
            return true;
        }
        if(node->data < x)
        {
            return hasData(x,node->left);
        }
        else
            return hasData(x,node->right);
    }
    void print(BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            return;
        }
        cout<<node->data<<":";
        if(node->left!=NULL)
            cout<<"L:"<<node->left->data;
        if(node->right!=NULL)
            cout<<",R:"<<node->right->data;

        print(node->left);
        print(node->right);
    }
    BinaryTreeNode<int>* insert(int val,BinaryTreeNode<int>* node)
    {
       if(node ==  NULL)
       {
           BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(val);
           return newNode;
       }
       if(node->data > val)
       {
           node->left = insert(val,node->left);
           return node;
       }
       if(node->data < val)
       {
           node->right = insert(val,node->right);
           return node;
       }
    }
public:

    BinaryTreeNode<int>* root;
    BST()
    {
        root = NULL;
    }
    bool hasData(int x)
    {
        return hasData(x,root);
    }
    void print()
    {
        print(root);
    }

    void insert(int elem)
    {
        BinaryTreeNode<int>* x = insert(elem,root);
    }

};
