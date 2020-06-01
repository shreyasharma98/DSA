#include<queue>
#include<iostream>
#include "trees.h"
using namespace std;

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {

    TreeNode<int>* ans = root;
    int diff = ans->data - n;
    if(diff < 1)
    {
        diff = INT_MAX;
    }
    for(int i = 0;i<root->children.size();i++)
    {
        TreeNode<int>* s = nextLargerElement(root->children[i],n);
        if(s->data-n < diff && s->data-n >=1)
        {
            diff= s->data-n;
            ans = s;
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
int main()  //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
{
    int n;
    cin >> n;
    TreeNode<int>* root = takeInput();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}

