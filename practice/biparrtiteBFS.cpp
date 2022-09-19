#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node]; // FILL WITH DIFFRENT COLOR 1-0=1,1-1=0;
                q.push(it);
            }
            else if (color[it] == color[node]) // AGR VISITED HAI TOH Y CONDITION CHECK HOGI KI CURRENT NODE K COLOUR PREVIOS VALE S SAME HAI TOH BIPRAATEE NAHI
            {
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];                    // visited array type
    memset(color, -1, sizeof color); // using memset we fill the array by -1 "MEMSENT FIRST ARGUMENT IS ARRAY SECOND IS VALUE WHICH HAVE TO FILL THIRD IS SIZE OF ARRAY"
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n))
    {
        cout << "yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

/*
8 7
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5

// bipartite graph example
*/

/*
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5
// not bipartite example
*/