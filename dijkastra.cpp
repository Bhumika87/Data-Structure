#include <iostream>
#include <queue>
#include <list>
#include <map>
#include<set>
#include <unordered_map>
using namespace std;
template<typename T>
class Graph {
public:
	unordered_map<T, list<pair<T, int> > > adjList;
	void addEdge(T u, T v, int dist, bool bidir = true) {
		adjList[u].push_back({v, dist});
		if (bidir) {
			adjList[v].push_back({u, dist});
		}
	}

	void print() {
		for (auto p : adjList) {
			cout << p.first << ": ";
			for (auto n : p.second) {
				cout << "(" << n.first << ", " << n.second << ") ";
			}
			cout << endl;
		}
	}

    auto dijkastra(T src,T des)
    {
        set<pair<int,T>>s;
        unordered_map<T,int>distance;
        unordered_map<T,T>parent;
        for(auto p:adjlist){                 //hr position pr infinitive
            distance[p.first]=INT_MAX;
        }
        distance[src]=0;  //starting node a k khud s distance 
        parent[src]=src;   //starting  parent k parent s map
        s.insert({0,src}); //usko set m dalna 
        while(s!=empty()){   
            auto =f.begin();

        }
        for(auto p: distance)
        {
            cout<<"distance of"<<p.first<<"from"<<src<< ":"<<p.second<<endl;  //here p repersent parent
        }
        T temp= des;
        while(des !=src)
        {
            cout<<des<<"<--";
            des =parent[des];
        }
        cout<<src<<endl;
        return distance[temp];
    }
};

int main() {
	Graph<string> g;
	g.addEdge("Amritsar", "Jaipur", 4);
	g.addEdge("Amritsar", "Agra", 1);
	g.addEdge("Delhi", "Agra", 1);
	g.addEdge("Delhi", "Jaipur", 2);
	g.addEdge("Mumbai", "Jaipur", 8);
	g.addEdge("Mumbai", "Bhopal", 3);
	g.addEdge("Agra", "Bhopal", 2);

    int ans =g.dijkastra("amritsar","jaipur");
    cout<<"distance of amritsar to mumbai"<<ans<<endl;

	g.print();


	return 0;
}
