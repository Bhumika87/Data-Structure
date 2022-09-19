#include <iostream>
#include<list>
#include<map>
#include<queue>

#include<unordered_map>
using namespace std;

class graph{
public:
    unordered_map<string,list<string> > adjlist;
    void addedges(string u,string v, bool bidir =true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void helper(unordered_map<string,bool> & visit,string node,list<string>&l)
    {
        visit[node]=true;
        for(auto child : adjlist[node])
        {
            if(!visit[child])
            {
                helper(visit,child,l);
            }
        }
        l.push_front(node);
    }
    void taplogical_Sort()
    {
        list<string> l;
        unordered_map<string,bool> visit;
        for(auto p:adjlist)
        {
            if(!visit[p.first])
            {
                helper(visit,p.first,l);
            }
        }
        for(auto e : l)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    void tps_bfs()
    {
        unordered_map<string,bool> visited;
        unordered_map<string ,int> indegree;
        queue<string> q;
         for(auto p: adjlist)
         {
            for(auto c:p.second)
            {
            indegree[c]++;
            }
        }
         for(auto p:adjlist)
         {
            if(indegree.count(p.first)==0)
            {
                q.push(p.first);
                visited[p.first]=true;
            }

         }
         while(!q.empty())
         {
            string node =q.front();
            q.pop();
            cout<<node<<" ";
            for(auto c:adjlist[node])
            {
                if(--indegree[c]==0)
                {
                    q.push(c);
                }
            }
         }
         cout<<endl;

    }
    bool cycle_bfs_helper(string node,unordered_map<string,bool> visited,unordered_map<string,string> parent)
    {
       queue<string> q;
       visited[node]=true;
       parent[node]=true;
       q.push(node);
       while(!q.empty())
       {
        string node =q.front();
        q.pop();
        for (auto child: adjlist[node])
        {
            if(visited[child] and parent[node] != child){
                return true;
            }else if(!visited[child]){
                q.push(child);
                parent[child]=node;
                visited[child]=true;
            }
        }
       } 
       return false;
    }
    bool cycleBfs()
    {
        unordered_map<string,bool> visited;
        unordered_map<string,string> parent;
        for (auto p:adjlist)
        {
            if(!visited[p.first])
            {
                if(cycle_bfs_helper(p.first,visited,parent))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    graph g;
    /*
    g.addedges("ENGLISH","DSA");
    g.addedges("LAPTOP","DSA");
    g.addedges("DSA","PYTHON");
    g.addedges("PYTHON","C++");
    g.addedges("PYTHON","ML");
    g.addedges("DSA","WEB");
    g.addedges("WEB","ML");
   
    

    //g.taplogical_Sort();
    g.tps_bfs();
    */
   g.addedges("1","0",true);
   g.addedges("2","0",true);
   // g.addedges("1","3",true);
   g.addedges("2","3",true);

   if(g.cycleBfs())
   {
    cout<<"cycle present"<<endl;
   }else{
    cout<<"cycle not present"<<endl;
   }
   

    return 0;
}