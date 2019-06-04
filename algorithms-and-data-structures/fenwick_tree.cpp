#include <iostream>
using namespace std;

class FenwickTree
{
    public:
        FenwickTree(int N)
        {
            n = N;
            t = new int[n+1];
            for(int i = 0; i <= n; i++)
                t[i] = 0;
        }
        int read(int x)
        {
            int res = 0;
            for(;x>0;x-=(x&-x))res+=t[x];
            return res;
        }
        void update(int x ,int w)
        {
            for(;x<=n;x+=(x&-x))t[x]+=w;
        }
    private:
        int n;
        int *t;
};


int main()
{
}
