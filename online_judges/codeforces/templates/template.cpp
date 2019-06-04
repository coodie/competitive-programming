#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <stack>
#include <cstring>
#include <functional>
#include <iomanip>
using namespace std;

//Defines
#define FIRST(a) (a).begin()
#define REMOVE_FIRST(a) (a).erase((a).begin())
#define REMOVE_LAST(a) (a).erase(--(a).end())
#define LAST(a) (--(a).end())
#define PRINT_ALL(a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ ) printf("%d ", *it);
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define FORD(i,n) for(int (i)=n; (i)>=0; --(i))
#define DBG(var) cerr << #var << " = " << var << endl;
#define pint pair<int, int>
#define vint vector<int>
#define PB push_back
#define LL long long int
#define ULL unsigned long long int
#define UI unsigned int
#define MP make_pair
#define f first
#define s second
#define TEST(name) freopen( (name), "r", stdin);
#define print(n) cout<<(n)<<endl
#define EXIT(message) {cout<<(message); exit(0);}
#define IOS ios_base::sync_with_stdio(0)
inline void scan(int &n){register char c = 0;while (c < 33) c=getc(stdin);n = 0;while (c>32) {n=n*10 + (c-'0'); c=getc(stdin);}}
inline void scan(LL &n){register char c = 0;while (c < 33) c=getc(stdin);n = 0;while (c>32) {n=n*10LL + (c-'0'); c=getc(stdin);}}
#define mod 1000000009
#define INF 1000000000
//Code starts here


int main()
{
    IOS;
    //TEST("in.txt");
}
