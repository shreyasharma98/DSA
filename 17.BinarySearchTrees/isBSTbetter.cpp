#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
class BST
{
    public:
    int mininmum;
    int maximum;
    bool IsBST;
};

BST isBST_helper(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        BST ans;
        ans.IsBST = true;
        ans.maximum = INT_MIN;
        ans.mininmum = INT_MAX;
        return ans;
    }
    BST LeftAns = isBST_helper(root->left);
    BST RightAns = isBST_helper(root->right);

    int minimum = min(root->data,min(LeftAns.mininmum,RightAns.mininmum));
    int maximum = max(root->data,max(LeftAns.maximum,RightAns.maximum));
    bool Final_isBST = (root->data > LeftAns.maximum) && (root->data <= RightAns.mininmum) &&  LeftAns.IsBST && RightAns.IsBST;

    BST ans;
    ans.IsBST = Final_isBST;
    ans.maximum = maximum;
    ans.mininmum = minimum;

    return ans;
}
bool isBST(BinaryTreeNode<int> *root){
    return isBST_helper(root).IsBST;
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
