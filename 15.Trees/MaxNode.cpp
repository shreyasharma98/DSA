
#include<queue>
#include<iostream>
#include "trees.h"
using namespace std;

TreeNode<int>* MaxNode(TreeNode<int>* root)
{
    TreeNode<int>* final_max = root;
    for(int i = 0;i<root->children.size();i++)
    {
        TreeNode<int>* small = MaxNode(root->children[i]);
        if(small->data > final_max->data)
        {
            final_max = small;
        }
    }
    return final_max;
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


void print_tree(TreeNode<int>* root)
{
    if(root == NULL)  //this is edge case not Base case
    {
        return;
    }
    cout<<root->data<<" : ";                    //this is working as base case.
    for(int i =0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i =0;i<root->children.size();i++)
    {
        print_tree(root->children[i]);       //this is working as recurssive call.
    }
}
int main()
{
    TreeNode<int>* root = takeInput();

    //print_tree(root);
    cout<<MaxNode(root)->data;
    //delete tree
}

