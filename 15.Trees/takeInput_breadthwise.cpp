#include<iostream>
#include<queue>
#include "trees.h"
using namespace std;
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

void print_tree(TreeNode<int>* root)
{
    if(root == NULL)  //this is edge case not Base case
    {
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        for(int i =0;i<front->children.size();i++)
        {
            if(i == front->children.size()-1)
            {
                cout<<front->children[i]->data;
            }
            else
            {
                cout<<front->children[i]->data<<" , ";
            }
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;

    }
}
int main()
{
    TreeNode<int>* root = takeInput();

    print_tree(root);

    //delete tree
}
