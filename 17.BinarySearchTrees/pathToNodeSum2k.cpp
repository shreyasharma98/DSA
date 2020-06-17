#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
void print(BinaryTreeNode<int>* root,int k ,int* arr,int m)
{
    if(root == NULL)
    {
        if(k == 0)
        {
             for(int i = 0;i<m;i++)
            {
                cout<<arr[i]<<" ";
            }
        cout<<endl;
        return;
        }
        else
            return;
    }
    arr[m] = root->data;
    k = k-root->data;
    print(root->left,k,arr,m+1);
    if(k!=0)
        print(root->right,k,arr,m+1);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    int output[100];
    print(root,k,output,0);
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
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}
