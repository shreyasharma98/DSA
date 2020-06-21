#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == k)
    {
        return root;
    }
    BinaryTreeNode<int>* ans;
    if(root->data > k)
    {
        ans = searchInBST(root->left,k);
    }
    else
    {
        ans = searchInBST(root->right,k);
    }
    return ans;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
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
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
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
    int k;
    cin >> k;
    BinaryTreeNode<int> *ans = searchInBST(root, k);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    delete root;
}

