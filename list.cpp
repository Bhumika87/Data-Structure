#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);


    for(int data: l)
    {
        cout<<data<<endl;
    }

    return 0;

}