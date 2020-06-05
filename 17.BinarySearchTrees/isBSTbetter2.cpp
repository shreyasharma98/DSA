
#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
bool isBST_helper(BinaryTreeNode<int>* root,int maximum ,int minimum)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data < minimum|| root->data >maximum )
    {
        return false;
    }
    bool checkL = isBST_helper(root->left,root->data-1,minimum);
    bool checkR = isBST_helper(root->right,maximum,root->data);

    return checkL && checkR;
}
bool isBST(BinaryTreeNode<int> *root){
    return isBST_helper(root,INT_MAX,INT_MIN);
}
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}
