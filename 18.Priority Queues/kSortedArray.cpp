#include<queue>
#include<iostream>
using namespace std;
void kSortedArray(int *arr ,int n,int k)
{
    priority_queue<int> pq;
    for(int i = 0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    int j = 0;
    for(int  i=k;i<n;i++)
    {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while(!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main()
{
    int n;
    cin>>n;
    int *p = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>p[i];
    }
    int k;
    cin>>k;
    kSortedArray(p,n,k);
    for(int i = 0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
}
