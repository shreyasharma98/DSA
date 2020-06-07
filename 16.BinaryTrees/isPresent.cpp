#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if(root == NULL)
    {
        return false;
    }
    if(root->data == x)
    {
        return true;
    }
    bool checkL = isNodePresent(root->left,x);
    bool checkR = isNodePresent(root->right,x);
	if(checkL == true || checkR == true)
    {
        return true;
    }
    return false;
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
    int x;
    cin >> x;
    if(isNodePresent(root, x)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    delete root;
    return 0;
}


