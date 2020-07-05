#include<iostream>
#include<queue>
using namespace std;
void BFS(int **edges,int n,int start,bool *visited)
{
    queue<int> pendingQ;
    pendingQ.push(start);
    visited[start]=true;
    while(!pendingQ.empty())
    {
        int front = pendingQ.front();
        pendingQ.pop();
        cout<<front<<" ";
        for(int i = 0;i<n;i++)
        {
            if(i == front)
                continue;
            if(edges[front][i] == 1 && !visited[i])
            {
                pendingQ.push(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i = 0;i<n;i++)
    {
        edges[i] = new int[n];
    }

    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i = 0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    bool *visited = new bool[n];
    for(int i = 0;i<n;i++)
    {
        visited[i] = false;
    }
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
            BFS(edges,n,i,visited);
    }
    return 0;
}
