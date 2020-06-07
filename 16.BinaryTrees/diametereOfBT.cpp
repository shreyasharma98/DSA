#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
int diameter()
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

void print(BinaryTreeNode<int>* root)
{
    if(root== NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pendingQ ;
    pendingQ.push(root);
    while(!pendingQ.empty())
    {
        BinaryTreeNode<int>* front = pendingQ.front();
        pendingQ.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<"L "<<front->left->data;
            pendingQ.push(front->left);
        }
        if(front->right != NULL)
        {
            cout<<", R "<<front->right->data;
            pendingQ.push(front->right);
        }
        cout<<endl;
    }
}
int main()
{
}


