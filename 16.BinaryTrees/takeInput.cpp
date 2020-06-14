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
BinaryTreeNode<int>* TakeInput()
{
    int rootData;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    cout<<"Enter Left of "<<rootData<<endl;
    BinaryTreeNode<int>* left = TakeInput();
    cout<<"Enter Right of "<<rootData<<endl;
    BinaryTreeNode<int>* right = TakeInput();
    root->left = left;
    root->right = right;

    return root;
}
int main()
{
    BinaryTreeNode<int>* root = TakeInput();
    print(root);
    delete root;
    return 0;
}
