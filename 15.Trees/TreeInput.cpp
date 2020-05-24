
#include<iostream>
#include "trees.h"
using namespace std;
TreeNode<int>* takeInput()
{
    int rootdata;
    cout<<"Enter data : "<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter the no. of children of : "<<rootdata<<endl;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
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

    print_tree(root);

    //delete tree
}
