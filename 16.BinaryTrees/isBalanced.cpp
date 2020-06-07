#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int heit = 1;
    int heightL = height(root->left);
    int heightR = height(root->right);

    return heit+max(heightL,heightR);

}

bool isBalanced(BinaryTreeNode<int> *root) {
    if(root == NULL)
    {
        return true;
    }
    int lft = height(root->left);
    int rit = height(root->right);
    if(lft - rit >= 2)
    {
        return false;
    }
    bool l = isBalanced(root->left);
    bool r = isBalanced(root->right);

    return l&&r;
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

    if(isBalanced(root)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    delete root;
    return 0;
}
