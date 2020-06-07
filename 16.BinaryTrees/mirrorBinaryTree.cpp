#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL)
    {
        return;
    }
    else
    {
        BinaryTreeNode<int>* temp;
        mirrorBinaryTree(root->left);
        mirrorBinaryTree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
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
    mirrorBinaryTree(root);
    //print(root);
    delete root;
    return 0;
}
