class minHeap{
    void heapify(int indx)
    {
        int li=2*indx;
        int ri=li+1;
        int mi=indx;
        if(li<v.size() and v[li]<v[ri])
        {
            mi=li;
        }
        if(li<v.size() and v[li]<v[ri])
        {
            mi=ri;
        }
    }
    public:
    vector <int> v;
    minHeap(){
        v.pushback(-1);
    }
    void push(int d)
    {
        v.push_back(d);
        int c=v.size()-1;
        int p=c/2;

        while(p)
    }
}