#include<queue>
#include<iostream>
#include<stack>
#include "BinaryTree.h"
using namespace std;
void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;

    s1.push(root);
    while(s1.size()!=0 || s2.size()!=0)
    {
        while(!s1.empty())
    {
        BinaryTreeNode<int>* top = s1.top();
        s1.pop();

        cout<<top->data<<" ";
        if(top->left!=NULL)
            s2.push(top->left);
        if(top->right!=NULL)
            s2.push(top->right);
    }
    cout<<endl;
    while(!s2.empty())
    {
        BinaryTreeNode<int>* top = s2.top();
        s2.pop();
        cout<<top->data<<" ";
        if(top->right!=NULL)
            s1.push(top->right);
        if(top->left!=NULL)
            s1.push(top->left);
    }
    cout<<endl;
    }

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
    zigZagOrder(root);
}
