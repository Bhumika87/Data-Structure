#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class graph
{
public:
    int vertices;
    list<int> *adjlist; // create a list type pointer
    graph(int vertices)
    {
        this->vertices = vertices;
        adjlist = new list<int>[vertices];
    }
    void dfs(int node, vector<int> &vis, list<int> adj[], vector<int> &storedfs)
    {

        storedfs.push_back(node);
        vis[node] = 1;
        for (auto i : adj[node]) // fir pdosi p traverse kra
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, storedfs); /// pdosi k phle node k lia dfs call krdia
            }
        }
    }
    vector<int> dfsOfGraph(int vertices, list<int> adjlist[])
    {
        vector<int> storedfs;
        vector<int> visited(vertices + 1, 0);
        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i]) // first node k lia check kra
            {
                dfs(i, visited, adjlist, storedfs);
            }
        }
        return storedfs;
    }
    void bfsc(int i, list<int> adjlist[], vector<int> &bfs, vector<int> &vis)
    {
        // queue<int>q;
        bfs.push_back(i);
        vis[i] = 1;
        int node = bfs.front();
        for (auto j : adjlist[node])
        {
            if (!vis[j])
            {
                bfs.push_back(i);
                vis[j] = 1;
            }
        }
    }
    vector<int> bfs(int v, list<int> adjlist[])
    {
        vector<int> bfs;
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!adjlist[i])
            {
                bfsc(i, adjlist, bfs, vis);
            }
        }
        return bfs;
    }
};
int main()

{
    graph g(6);
    return 0;
}