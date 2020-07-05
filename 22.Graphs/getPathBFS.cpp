#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>* getPathBFS(int **edges,int n,int start,int end,bool *visited)
{
    unordered_map<int,int> table;
    queue<int> pendingQ;
    pendingQ.push(start);
    visited[start]=true;
    bool done = false;
    while(!pendingQ.empty() && !done)
    {
        int front = pendingQ.front();
        pendingQ.pop();
        for(int i = 0;i<n;i++)
        {
            if(i == front)
                continue;
            if(edges[front][i] == 1 && !visited[i])
            {
                table[i] = front;
                pendingQ.push(i);
                visited[i] = true;
                if(i == end)
                {
                    done = true;
                    break;
                }
            }
        }
    }
    if(!done)
        return NULL;
     vector<int>* V = new vector<int>();
     int curr = end;
     V->push_back (end);
     while(curr!=start)
     {
         curr = table[curr];
         V->push_back(curr);
     }
     return V;
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
    int start,end;
    cin>>start>>end;
    vector<int>* temp = getPathBFS(edges,n,start,end,visited);
    if(temp!=NULL)
    {
        for(int i = 0;i<temp->size();i++)
        {
           cout<<temp->at(i)<<" ";
        }
    }
    return 0;
}

