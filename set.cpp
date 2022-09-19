#include <iostream>
using namespace std;
#include<set>
int main()
{
    set<int> s;
     s.insert(1);
     s.insert(2);
     s.insert(3);
     for(auto h: s)
     {
        cout<<h<<endl;
     }

    set<pair<int,string>>p;
    p.insert({1,"bhumi"});
    p.insert({2,"dcdi"});
    p.insert({3,"hdfvjhi"});

    for(auto g: p)
    {
        cout<<"{"<<g.first<<" , "<<g.second<<"}"<<endl;
    }



   return 0;
}