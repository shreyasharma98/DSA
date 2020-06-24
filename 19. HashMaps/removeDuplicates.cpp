#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(int *a,int n)
{
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<n;i++)
    {
        if(seen.count(a[i])>0)
        {
            continue;
        }
        seen[a[i]]= true;
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    int n;
    cin>>n;
    int *p =  new int[n];
    for(int i =0;i<n;i++)
    {
        cin>>p[i];
    }
    vector<int> output = removeDuplicates(p,n);
    for(int i  =0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
