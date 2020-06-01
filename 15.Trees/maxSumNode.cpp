
#include<queue>
#include<iostream>
#include "trees.h"
using namespace std;

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    int sum = root->data;
    for(int i = 0;i<root->children.size();i++)
    {
        sum+=root->children[i]->data;
    }
    TreeNode<int>* ans = root;
    for(int i = 0;i<root->children.size();i++)
    {
        TreeNode<int>* small = maxSumNode(root->children[i]);
        int s = small->data;
        for(int i = 0;i<small->children.size();i++)
        {
            s+=small->children[i]->data;
        }
        if(s>sum)
        {
            sum = s;
            ans = small;
        }
    }
    return ans;
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
    TreeNode<int>* ans = maxSumNode(root);
   if(ans != NULL) {
        cout << ans -> data << endl;
    }
}
