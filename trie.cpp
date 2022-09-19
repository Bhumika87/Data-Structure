#include<iostream>
using namespace std;
#include <unordered_map>

class node{
    public:
    char c;
    bool isterminal;
    unordered_map<char,node* > h;


}
class trie{
    public node * root;
    trie()
    {

    }
    void searchWord()
    {
        node* temp=root;
        for(auto r: )

    }
}
int main()
{
    trie t;
    t.addWord("Hello");
     t.addWord("code");
     t.addWord("coders");
    t.addWord("Hello");
  

}