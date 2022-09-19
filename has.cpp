#include<iostream>
using namespace std;
class node{
    public:
    string key;
    int value;
    node *next;
    node(){};
    node(string s,int v)
    {
        key=s;
        value=v;
    }
};
class hashMap{
    hashFunction(string k)
    {
        int ans=0;
        int mul=1;
        for(int i=;)

    }
    node ** olda=a;
    int oldts=ts;
    a=new node*(2*ts);
    ts *= 2;
    cs = 0;
    for(int i=0;i<ts;++i)
    {
        a[i]=NULL;
    }
 public:   
    node** a;
    int ts;
    hashMap(int s=7)
    {
        a=new node*[s];
        ts=s;
        for(int i=0;i<s;i++)
        {
            a[i]=NULL;
        }
    }
    void insert(string key,int value)
    {
        node* n= new node(key,value);
        int hash_index=hashFunction(key);
        n->next=a[hash_index];
        a[hash_index]=n;
        cs++;
        float load_factor =cs/(ts*1.0);
        if(load_factor >0.6)
        {
            rehash();
        }

    }

    void print(){
        for(int i=0;i<ts;i++)
        {
            cout<<i<<"-->";
            node * h =a[i];
            while(h!=NULL){
                cout<<"("<<h->key<<","<<h->value<<")";
                h=h->next;
            }
            cout<<endl;
        }
    }

    void search(string key)
    {
        int hash_index=hashFunction(key);
        node *h=a[hash_index];
        while(h)
        {
            if(h->key==key)
            {
                return h;
            }
            h=h->next;
        }
        return NULL;

    }

};
int main()
{
    hashMap h;
    h.insert("Apple",120);
}
