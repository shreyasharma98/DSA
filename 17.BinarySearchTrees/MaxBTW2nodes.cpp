#include<stack>
#include<queue>
#include<algorithm>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
int maxNodeInBetween(BinaryTreeNode<int> *root, int n1, int n2){
    if(root == NULL)
    {
        return -1;
    }
    if(root->data >= n1 && root->data <= n2)
    {
        stack<BinaryTreeNode<int>*> S;
        BinaryTreeNode<int>* temp = root ;
        int max = S.top()->data;
        S.pop();
        while(!S.empty())
        {
            if(S.top()->data > max)
            {
                max = S.top()->data;
            }
            S.pop();
        }
        return max;
    }
    if(root->data > n1 && root->data > n2)
    {
        return maxNodeInBetween(root->left,n1,n2);
    }
    if(root->data < n1 && root->data < n2)
    {
        return maxNodeInBetween(root->right,n1,n2);
    }
}
