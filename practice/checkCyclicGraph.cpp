#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
class graph
{
    int vertices;
    // arry of list
    list<int> *adjlist;
    graph(int vertices)
    {
        this->vertices = vertices;
        adjlist = new list<int>[vertices];
    }
    // helper
    bool detectCycle(int node, vector<int> &visi, list<int> adjlist[])
    {
        queue<pair<int, int>> q;
        visi[node] = 1;
        q.push({node, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int previous = q.front().second;
            q.pop();
            for (auto neigh : adjlist[node])
            {
                if (!visi[neigh])
                {
                    visi[neigh] = 1;
                    q.push({neigh, node});
                }
                // agr voh visited hai or uska parent bhi nahi hai toh iska mtlb cycle hai
                else if (previous != neigh)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool cyclicGraph(int vertices, list<int> adjlist[])
    {
        vector<int> visi(vertices + 1, 0);
        for (int i = 1; i < vertices; i++)
        {
            if (!visi[i])
            {
                if (detectCycle(i, visi, adjlist))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    return 0;
}