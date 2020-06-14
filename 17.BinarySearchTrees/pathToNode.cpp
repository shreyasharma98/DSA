#include<vector>
#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
vector<int>* pathToNode(BinaryTreeNode<int>* root ,int x)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == x )
    {
        vector<int>* ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    if(root->data > x)
    {
        vector<int>* leftAns = pathToNode(root->left,x);
        if(leftAns != NULL)
        {
            leftAns->push_back(root->data);
            return leftAns;
        }
    }
    if(root->data < x)
    {
        vector<int>* rightAns = pathToNode(root->right,x);
        if(rightAns!=NULL)
        {
            rightAns->push_back(root->data);
            return rightAns;
        }
    }
    return NULL;
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
    int x;
    cin>>x;
    vector<int>* v = pathToNode(root,x);
    for(int i =0;i<v->size();i++)
    {
        cout<<v->at(i)<<" ";
    }
    delete root;
}


