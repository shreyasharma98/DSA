#include <iostream>
#include<vector>
using namespace std;
vector<int>* getPathDFS(int **edges,int n,bool *visited,int start,int end)
{
    vector<int>* V = new vector<int>();
    if(start == end)
    {
        V->push_back(end);
        return V;
    }
    visited[start] = true;
    for(int i=0;i<n;i++)
    {
        if(i == start)
            continue;
        if(edges[start][i] == 1 && !visited[i])
        {
            vector<int>* temp = getPathDFS(edges,n,visited,i,end);
            if(temp!=NULL)
            {
                temp->push_back(start);
                return temp;
            }
        }
    }

    return NULL;

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

    vector<int>* temp = getPathDFS(edges,n,visited,start,end);
    if(temp!=NULL)
    {
        for(int i = 0;i<temp->size();i++)
        {
           cout<<temp->at(i)<<" ";
        }
    }

  return 0;
}
