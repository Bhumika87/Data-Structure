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
    void bfsTraversal(int vertices, vector<int> adjlist[])
    {
        vector<int> bfs;
        vector<int> vis(vertices + 1, 0);
        for (int i = 1; i <= vertices; i++)
        {
            if (!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty())
                {
                    int n = q.front();
                    q.pop();
                    bfs.push_back(n);
                    for (auto i : adjlist[n])
                    {
                        if (!vis[i])
                        {
                            q.push(i);
                            vis[i] = 1;
                        }
                    }
                }
            }
        }
    }
};
int main()
{
    return 0;
}