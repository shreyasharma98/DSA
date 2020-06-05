#include<queue>
#include<iostream>
#include "trees.h"
using namespace std;
class Pair
{
    public :
    TreeNode <int>* first;
    TreeNode <int>* second;
    Pair()
    {
        first = NULL;
        second = NULL;
    }

};
Pair helper(TreeNode<int> *root)
{
    TreeNode <int>* fMax = root;
    TreeNode <int>* sMax = NULL;
    Pair p1;
    p1.first = fMax;
    p1.second = sMax;
  for(int i = 0;i<root->children.size();i++)
   {
       Pair p2 = helper(root->children[i]);
       if(p1.second == NULL && p2.second == NULL)
       {
           if(p1.first->data > p2.first->data)
           {
               p1.second = p1.first;
           }
       }
       else if(p1.second == NULL)
       {
           if(p1.first->data > p2.first->data)
           {
               p1.second = p2.first;
           }
           else
           {
               if(p1.first->data > p2.second->data)
               {
                   p1.second = p1.first;
                   p1.first = p2.first;
               }
               else
               {
                   p1.first = p2.first;
                   p1.second = p2.second;
               }
           }
       }
       else if(p2.second== NULL)
       {
           if(p1.first->data > p2.first->data)
            {
                if(p1.second->data < p2.first->data)
                {
                    p1.second = p2.first;
                }
            }
            else
            {
                p1.second = p1.first;
                p1.first = p2.first;
            }
       }
       else if(p1.first->data > p2.first->data)
       {
           if(p2.first->data > p1.second->data)
           {
               p1.second = p2.first;
           }
       }
       else if(p2.first->data > p1.first->data)
       {
           if(p1.first->data > p2.second->data)
           {
               p1.second = p1.first;
               p1.first = p2.second;
           }
           else
           {
               p1.first = p2.first;
               p1.second = p2.second;
           }
       }

   }
   return p1;
}
void secondLargest(TreeNode<int> *root) {
  Pair p = helper(root);
  cout<< p.first->data;
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
    TreeNode<int>* root = takeInput();
    secondLargest(root);

}

