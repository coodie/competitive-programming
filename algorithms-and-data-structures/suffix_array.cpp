#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;


struct entry
{
    int a,b,pos;
    bool operator < (const entry& x) const
    {
        return (a == x.a) ? (b < x.b) : (a < x.a);
    }
    bool operator == (const entry& x) const
    {
        return (a == x.a) && (b == x.b);
    }
};

class SuffixArray
{
public:
    SuffixArray(const string &str, vector<int> &res)
        : str(str), res(res) 
    {
        n = str.size();
        res.resize(n);
        logn = 1;
        for(int x = 1; x < n; x *= 2) logn++;
        L.resize(n);
    } 

    void compute()
    {
        vector<vector<int> > P(logn);
        for(int i = 0; i < logn; i++) P[i].resize(n);

        vector<int> cnt(256,0);
        for(int i = 0; i < n; i++)
            cnt[str[i]]++;

        int cur = 0;
        for(int i = 0; i < 256; i++)
            if(cnt[i] > 0)
                cnt[i] = cur++;

        for(int i = 0; i < n; i++)
            P[0][i] = cnt[str[i]];


        for(int i = 1; i < logn; i++)
        {
            int k = (1 << (i-1) ); 
            for(int j = 0; j < n; j++)
            {
                L[j].a = P[i-1][j];
                L[j].b = (j+k < n) ? P[i-1][j+k] : -1;
                L[j].pos = j;
            }

            sort(L.begin(), L.end());

            P[i][L[0].pos] = 0;
            for(int j = 1; j < n; j++)
            {
                P[i][L[j].pos] = (L[j] == L[j-1]) ? P[i][L[j-1].pos] : j;
            }
            P[i-1].clear();
        }

        res = P[logn-1];
    }

private:

    //Arguments to suffix array algorithm
    const string &str;
    vector<int> &res;

    //Context needed for algorithm
    int n, logn;
    vector<entry> L;
};

void suffix_array(const string& str, vector<int>& tab)
{
    SuffixArray alg(str, tab);
    alg.compute();
}

int main()
{
    ios_base::sync_with_stdio(0);
    string x;
    cin >> x;
    vector<int> arr;
    suffix_array(x, arr);
    for(unsigned i = 0; i < arr.size(); i++)
        cout << arr[i] << ' '; cout << endl;
}
