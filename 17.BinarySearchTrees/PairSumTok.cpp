#include<queue>
#include<algorithm>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
vector<int> helper(BinaryTreeNode<int> *root, int sum)
{
    vector<int> V;
   queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()) {
		BinaryTreeNode<int> *first = q.front();
		q.pop();
		if(first == NULL) {
			continue;
		}
		V.push_back(first -> data);
		if(first -> left != NULL) {
			q.push(first -> left);
		}
		if(first -> right != NULL) {
			q.push(first -> right);
		}
	}
	return V;
}
void nodesSumToS(BinaryTreeNode<int> *root, int sum) {

        vector<int> V = helper(root,sum);
        sort(V.begin(),V.end());
        //for(int i = 0;i<V.size();i++)
            //cout<<V[i]<<" ";
        int start = 0,end = V.size()-1;
        while(start<=end)
        {
            if(V[start]+V[end] == sum)
            {
                cout<<V[start]<<" "<<V[end]<<endl;
                start++;end--;
            }
            else if(V[start]+V[end] > sum)
            {
                end--;
            }
            else
            {
                start++;
            }
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
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
