
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class graph
{
public:
    int vertices;
    list<int> *adjlist; // create a list type pointer
    graph(int vertices)
    {
        this->vertices = vertices; // it change the data mamber value by this pointer
        // array of list ,array store vertices,and list store neigbhour or edges which is connected to the partictular vertices
        adjlist = new list<int>[vertices];
    }
    void addEdges(int u, int v, bool bidir = true)
    {
        adjlist[u].push_back(v);
        if (bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void shortestDistanceUndirected(list<int> adj, int src, int vertices)
    {
        int distances[vertices];
        for (int i = 0; i < vertices; i++)
        {
            distances[i] = INT_MAX;
        }
        distances[src] = 0;
        queue<int> q;
        q.push(src);
        while (q.empty() == false)
        {
            int node = q.front();
            q.pop();
            for (auto neighbour : adjlist[node])
            {
                if (distances[node] + 1 < distances[neighbour])
                {
                    distances[neighbour] = distances[node] + 1;
                    q.push(neighbour);
                }
            }
        }
        for (int i = 0; i < vertices; i++)
            cout << distances[i] << " ";
    }

    void printGraph()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << "<<--"; // for vertices
            for (auto neighbour : adjlist[i])
            {
                cout << neighbour << "---"; // for neighbour
            }
            cout << endl;
        }
    }
};
int main()

{
    graph g(6);
    g.addEdges(0, 4);
    g.addEdges(0, 3);
    g.addEdges(1, 2);
    g.addEdges(1, 4);
    g.addEdges(1, 5);
    g.addEdges(2, 3);
    g.addEdges(2, 5);
    g.addEdges(5, 3);
    g.addEdges(5, 4);
    g.printGraph();

        return 0;
}