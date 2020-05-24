#include<queue>
#include<iostream>
#include "trees.h"
using namespace std;
bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1->data != root2->data)
    {
        return false;
    }
    if(root1->children.size() != root2->children.size())
    {
        return false;
    }
    int i = 0,j=0;
    bool check = true;
    while(i<root1->children.size() && j<root2->children.size())
    {
        check = isIdentical(root1->children[i],root2->children[j]);
        i++;
        j++;
    }
    return check;

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
int main()  //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
{
    TreeNode<int>* root1 = takeInput();
    TreeNode<int>* root2 = takeInput();

    if(isIdentical(root1, root2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    //delete tree
}
