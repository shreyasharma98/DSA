#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
// THis method gives Time Complexity oh O(n^2) in case of skewed trees : isBSTbetter.cpp

int find_max(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(find_max(root->left),find_max(root->right)));
}
int find_min(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data,min(find_min(root->left),find_min(root->right)));
}
bool isBST(BinaryTreeNode<int> *root){
    if(root == NULL)
    {
        return true;
    }
    int LMax = find_max(root->left);
    int RMin = find_min(root->right);
    bool ans = (root->data >LMax) && (root->data < RMin) && isBST(root->left) && isBST(root->right);
    return ans;

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
