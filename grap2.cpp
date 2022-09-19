#include <iostream>
using namespace std;
#include<list>
#include<map>
#include<unordered_map>
class graph{
public:
    unordered_map<string,list<string>> adjlist;
    void addedges(string u,string v, bool bidir =true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        for(auto p:adjlist)
        {
            cout<<p.first<<"<--";
            for(auto negibour: p.second)
            {
                cout<<negibour<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g;
    g.addedges("modi","yogi",true);
    g.addedges("yogi","prabhu",false);
    g.addedges("prabhu","modi",false);
    g.addedges("modi","trump",true);
    g.addedges("putin","trump",false);
    g.addedges("","",false);
    g.addedges("","",false);

    return 0;
}