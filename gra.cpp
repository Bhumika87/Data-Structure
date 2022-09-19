#include <iostream>
using namespace std;
#include <list>
class graph
{
public:
    list<int> *adjlist;
    int n;
    graph(int n)
    {
        this->n = n;
        adjlist = new list<int>[n];
    }
    void addedges(int u, int v, bool bidir = true)
    {
        adjlist[u].push_back(v);
        if (bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "<--";
            for (auto negibour : adjlist[i])
            {
                cout << negibour << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(5);
    g.addedges(0, 1);
    g.addedges(0, 4);
    g.addedges(1, 4);
    g.addedges(1, 3);
    g.addedges(1, 2);
    g.addedges(3, 2);
    g.addedges(3, 4);

    g.print();

    return 0;
}
