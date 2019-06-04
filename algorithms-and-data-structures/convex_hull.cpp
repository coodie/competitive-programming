#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pt pair<long long int,long long int>
using namespace std;

//last and first element of hull are different
inline bool on_right(const pt &p0, const pt &p1, const pt &p2){return ( (p0.first-p2.first)*(p1.second-p2.second)-(p0.second-p2.second)*(p1.first-p2.first) ) <= 0; }
vector<pt> convex_hull(vector<pt> pts)
{
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    int len = pts.size();
    if(len < 3)
        return pts;
    vector<pt> res(len+1);
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        while(j-2 >= 0 && on_right(res[j-2], res[j-1], pts[i])) j--;
        res[j++] = pts[i];
    }
    int k = j;
    for(int i = len-2; i >= 0; i--)
    {
        while(j-1 >= k && on_right(res[j-2], res[j-1], pts[i])) j--;
        res[j++] = pts[i];
    }
    if(res[j-1] == res[0]) j--;
    return vector<pt>(res.begin(), res.begin()+j);
}

int main()
{

}
