#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root == NULL)
    {
        return;
    }
    BinaryTreeNode<int>* temp = root->left;
    BinaryTreeNode<int>* newLeft = new BinaryTreeNode<int>(root->data);
    root->left = newLeft;
    insertDuplicateNode(temp);
    insertDuplicateNode(root->right);
    newLeft->left = temp;
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
void printLevelATNewLine(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		BinaryTreeNode<int> *first = q.front();
		q.pop();
		if(first == NULL) {
			if(q.empty()) {
				break;
			}
			cout << endl;
			q.push(NULL);
			continue;
		}
		cout << first -> data << " ";
		if(first -> left != NULL) {
			q.push(first -> left);
		}
		if(first -> right != NULL) {
			q.push(first -> right);
		}
	}
}
int main() {
BinaryTreeNode<int>* root = takeInput();
insertDuplicateNode(root);
printLevelATNewLine(root);
delete root;

}


