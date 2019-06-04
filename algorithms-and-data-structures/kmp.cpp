#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void prefix_function(string &P, int* tab)
{
    int m = P.length()+1;
    tab[0] = 0;
    tab[1] = 0;
    int k = 0;
    for(int i = 2; i <= m; i++)
        {
            while(k > 0 && P[k] != P[i-1]) k = tab[k];
            if(P[k] == P[i-1]) k++;
            tab[i] = k;
        }
}

void KMP(string &T, string &P) //tekst - wzorzec
{
    int m = P.length();
    int n = T.length();
    int pi[m+1];
    prefix_function(P, pi);
    int q = 0;
    for(int i = 0; i < n ; i++)
    {
        while(q > 0 && P[q] != T[i]) q = pi[q];
        if(P[q] == T[i]) q++;
        if(q == m)
            {
            cout << i-m+1 << endl;
            q = pi[q];
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int l;
        string wzorzec;
        cin >> l >> wzorzec;
        string tekst;
        cin >> tekst;
        KMP(tekst, wzorzec);
    }
}


