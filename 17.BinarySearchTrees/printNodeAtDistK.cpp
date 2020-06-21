#include<queue>
#include<iostream>
#include "BinaryTree.h"
void printAtDepth(BinaryTreeNode<int> *root, int k)
{
    if(root == NULL)
    {
        return;
    }
    if(k == 0)
    {
        cout<<root->data<<endl;
        return;
    }
    printAtDepth(root->left,k-1);
    printAtDepth(root->right,k-1);
}
int helper(BinaryTreeNode<int> *root, int node, int k)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->data == node)
    {
        printAtDepth(root,k);
        return 0;
    }
    int leftChild = helper(root->left,node,k);
    if(leftChild != -1)
    {
        if(k == 1+leftChild)
        {
            cout<<root->data<<endl;
        }
        else
        {
            printAtDepth(root->right,k-leftChild-2);
        }
        return leftChild+1;
    }
    int rightChild = helper(root->right,node,k);
    if(rightChild != -1)
    {
        if(k == 1+rightChild)
        {
            cout<<root->data<<endl;
        }
        else
        {
            printAtDepth(root->left,k-rightChild-2);
        }
        return rightChild+1;
    }
    else
    {
        return -1;
    }

}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int s = helper(root,node,k);
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
