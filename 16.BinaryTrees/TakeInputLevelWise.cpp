#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
void print(BinaryTreeNode<int>* root)
{
    if(root== NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pendingQ ;
    pendingQ.push(root);
    while(!pendingQ.empty())
    {
        BinaryTreeNode<int>* front = pendingQ.front();
        pendingQ.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<"L "<<front->left->data;
            pendingQ.push(front->left);
        }
        if(front->right != NULL)
        {
            cout<<", R "<<front->right->data;
            pendingQ.push(front->right);
        }
        cout<<endl;
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
    print(root);
    delete root;
    return 0;
}
