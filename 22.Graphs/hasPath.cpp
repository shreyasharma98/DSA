#include <iostream>
using namespace std;
bool hasPath(int **edges,int n,bool *visited,int start,int end)
{
    if(edges[start][end]==1)
    {
        return true;
    }
    bool ans = false;
    visited[start]= true;
    for(int i = 0;i<n;i++)
    {
        if(i == start)
            continue;
        if(edges[start][i] == 1)
        {
            if(!visited[i])
            ans = hasPath(edges,n,visited,i,end);
        }
        if(ans)
            return ans;
    }

    return false;

}
int main() {
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
    int start,end;
    cin>>start>>end;

    bool ans = hasPath(edges,n,visited,start,end);
    if(ans)
        cout<<"true";
    else
        cout<<"false";
  return 0;
}
