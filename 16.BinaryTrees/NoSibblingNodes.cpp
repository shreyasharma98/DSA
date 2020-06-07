
#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL)
    {
        return;
    }
    if(root->left ==NULL && root->right == NULL)
    {
        return;
    }
    if(root->left == NULL)
    {
        cout<<root->right->data<<endl;
    }
    if(root->right == NULL)
    {
        cout<<root->left->data<<endl;
    }

    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
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
int main() {
    BinaryTreeNode<int>* root = TakeInput();
    nodesWithoutSibling(root);
}
