#include<iostream>
#include "BinaryTree.h"
using namespace std;
void print(BinaryTreeNode<int>* root)
{
    if(root== NULL)
    {
        return;
    }
    cout<<root->data<<" : ";
    if(root->left != NULL)
        cout<<"L "<<root->left->data;
    if(root->right != NULL)
        cout<<", R "<<root->right->data;
    cout<<endl;
    print(root->left);
    print(root->right);
}
int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* left = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* right = new BinaryTreeNode<int>(3);
    root->left = left;
    root->right = right;
    print(root);
    delete root;
    return 0;
}
