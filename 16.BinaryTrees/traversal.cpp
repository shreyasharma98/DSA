#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
void inorder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void pre_order(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
void postOrder(BinaryTreeNode<int> *root) {
    if(root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

BinaryTreeNode<int>* TakeInput()
{
    queue<BinaryTreeNode<int>*> pendingQ ;
    int rootData;
    cout<<"Enter Root data : "<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    pendingQ.push(root);
    while(!pendingQ.empty())
    {
        BinaryTreeNode<int>* top = pendingQ.front();
        pendingQ.pop();
        int leftData,rightData;
        cout<<"Enter left of "<<top->data<<" : "<<endl;
        cin>>leftData;
        if(leftData != -1)
        {
            BinaryTreeNode<int>* lt = new BinaryTreeNode<int>(leftData);
            top->left = lt;
            pendingQ.push(lt);
        }
        cout<<"Enter right of "<<top->data<<" : "<<endl;
        cin>>rightData;
        if(rightData != -1)
        {
            BinaryTreeNode<int>* rt = new BinaryTreeNode<int>(rightData);
            top->right = rt;
            pendingQ.push(rt);
        }

    }
    return root;
}
int main()
{
    BinaryTreeNode<int>* root = TakeInput();
    //inorder(root);
   // pre_order(root);
    postOrder(root);
    delete root;
    return 0;
}
