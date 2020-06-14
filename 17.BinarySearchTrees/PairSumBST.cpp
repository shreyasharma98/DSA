#include<queue>
#include<stack>
#include<algorithm>
#include<iostream>
#include "BinaryTree.h"
int countNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1+ countNodes(root->left)+ countNodes(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    int n = countNodes(root);
    stack<BinaryTreeNode<int>*> inOrderStack;
    stack<BinaryTreeNode<int>*> reverseInOrderStack;
    BinaryTreeNode<int> *temp = root;
    int ctr = 0;
    while(temp != NULL)
    {
        inOrderStack.push(temp);
        temp = temp->left;
    }
    temp = root;
     while(temp != NULL)
    {
        reverseInOrderStack.push(temp);
        temp = temp->right;
    }
     while(inOrderStack.top() -> data < reverseInOrderStack.top() -> data)
    {
        BinaryTreeNode<int>* top1 = inOrderStack.top();
        BinaryTreeNode<int>* top2 = reverseInOrderStack.top();

        if(top1->data + top2->data == s)
        {
           cout<<top1->data<<" "<<top2->data<<endl;

           inOrderStack.pop();ctr++;
           reverseInOrderStack.pop();ctr++;

           temp = top1->right;
           while(temp!=NULL)
           {
              inOrderStack.push(temp);
              temp = temp->left;
           }
           temp = top2->left;
           while(temp!=NULL)
           {
              reverseInOrderStack.push(temp);
              temp = temp->right;
           }
        }
        else if(top1->data + top2->data < s)
        {
            inOrderStack.pop();
            ctr++;
            temp = top1->right;
            while(temp!=NULL)
            {
                inOrderStack.push(temp);
                temp = temp->left;
            }

        }
        else
        {
            reverseInOrderStack.pop();
           ctr++;
            temp = top2->left;
            while(temp!=NULL)
            {
                reverseInOrderStack.push(temp);
                temp = temp->right;
            }
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
//10 8 21 4 9 13 28 1 6 -1 -1 12 -1 23 -1 -1 -1 5 7 -1 -1 -1 24 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
