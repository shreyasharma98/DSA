#include<queue>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
int find(int x,int *arr,int len)
{
    for(int i = 0;i<len;i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    if(postLength == 0)
    {
        return NULL;
    }
    if(postLength == 1)
    {
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postLength-1]);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postLength-1]);
   int pos = find(postorder[postLength-1],inorder,inLength);

   root->left = getTreeFromPostorderAndInorder(postorder,pos,inorder,pos);
   root->right = getTreeFromPostorderAndInorder(postorder+pos,postLength-pos-1,inorder+pos+1,postLength-pos-1);

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
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>post[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}

