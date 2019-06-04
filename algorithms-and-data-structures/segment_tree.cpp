#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class SegTree
{
public:
    SegTree(size_t max_range)
    {
        size_t p = 1;
        while(p < max_range) p*=2;
        this->max_range = p;
        vec.resize(p*2+5, 0);
        lazy.resize(p*2+5, 0);
    }

    void update_interval(size_t l, size_t r, T val)
    {
        update_interval_rec(l,r,1,max_range,1,val);
    }

    T query(size_t l, size_t r)
    {
        return query_rec(l,r,1,max_range,1);
    }

private:

    void propagate(size_t len, size_t node)
    {
        if(lazy[node])
        {
            vec[node] += static_cast<T>(len)*lazy[node];
            if(2*node < lazy.size())
                lazy[2*node] += lazy[node];
            if(2*node+1 < lazy.size())
                lazy[2*node+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    T query_rec(size_t l, size_t r, size_t start, size_t end, size_t node)
    {
        propagate(end-start+1,node);

        if(l <= start and end <= r)
        {
            return vec[node];
        }

        if(l > end or r < start)
            return 0;
        
        size_t m = (start+end)/2;
        T left_res  = query_rec(l, r, start, m, node*2);
        T right_res = query_rec(l, r, m+1, end, node*2+1);
        return left_res + right_res;
    }

    void update_interval_rec(size_t l, size_t r, size_t start, size_t end, size_t node, T val)
    {
        propagate(end-start+1,node);

        if(l <= start and end <= r)
        {
            lazy[node] += val;
            propagate(end-start+1,node);
            return;
        }

        if(l > end or r < start)
            return;
        
        size_t m = (start+end)/2;
        update_interval_rec(l, r, start, m, node*2, val);
        update_interval_rec(l, r, m+1, end, node*2+1, val);
        vec[node] = vec[2*node]+vec[2*node+1];
    }

    size_t max_range;
    vector<T> lazy;
    vector<T> vec;
};

int main()
{
}
