#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
class largestBST
{
public:
    int minimum;
    int maximum;
    bool IsBST;
    int height;
};

largestBST helper(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        largestBST ans;

        ans.IsBST = true;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        ans.height = 0;

        return ans;
    }
    if(root->left== NULL && root->right == NULL)
    {
        largestBST ans;

        ans.IsBST = true;
        ans.maximum = root->data;
        ans.minimum = root->data;
        ans.height = 1;

        return ans;
    }
    largestBST LeftAns = helper(root->left);
    largestBST RightAns = helper(root->right);
    largestBST myAns;

    myAns.maximum = max(root->data,max(LeftAns.maximum,RightAns.maximum));
    myAns.minimum = min(root->data,min(LeftAns.minimum,RightAns.minimum));

    if(LeftAns.IsBST && RightAns.IsBST && root->data > LeftAns.maximum && root->data <= RightAns.minimum)
    {
        myAns.height = max(LeftAns.height,RightAns.height)+1;
        myAns.IsBST = true;
        return myAns;
    }
    myAns.IsBST = false;
    myAns.height =max(LeftAns.height,RightAns.height);

    return myAns;

}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return helper(root).height;
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
    cout << largestBSTSubtree(root);
    delete root;
}

