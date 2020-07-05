#include<iostream>
using namespace std;
void isConnected(int **edges,int n,int start,bool *visited)
{
    visited[start]= true;
    for(int i = 0;i<n;i++)
    {
        if(i == start)
            continue;
        if(edges[start][i] == 1)
        {
            if(visited[i])
                continue;
            isConnected(edges,n,i,visited);
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
    isConnected(edges,n,0,visited);
    for(int i =0;i<n;i++)
    {
        if(!visited[i])
        {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
}

