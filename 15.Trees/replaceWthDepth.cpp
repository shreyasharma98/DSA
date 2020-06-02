#include<queue>
#include<iostream>
#include "trees.h"
using namespace std;
void helper(TreeNode<int> *root,int k)
{
  root->data = k;
  k++;
  for(int i = 0;i<root->children.size();i++)
  {
      helper(root->children[i],k);
  }
}
void replaceWithDepthValue(TreeNode<int> *root){
    helper(root,0);
}


TreeNode<int>* takeInput()
{
    int rootdata;
    queue<TreeNode<int>*> pendingNodes;
    cout<<"Enter Root data : "<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        int numChild;
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the no. of children of "<<front->data<<endl;
        cin>>numChild;

        for(int i = 0;i<numChild;i++)
        {
            int childData;
            cout<<"Enter the "<<i+1<<"th child of : "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


void printLevelATNewLine(TreeNode<int> *root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeNode<int> *first = q.front();
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
        for(int i = 0; i < first -> children.size(); i++) {
            q.push(first -> children[i]);
        }
    }
}

int main()  //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
{
    TreeNode<int>* root = takeInput();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}
