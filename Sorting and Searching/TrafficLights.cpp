#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;
int n, x, p, l, r;
set<pair<int,int>>a;
multiset<int>res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>x>>n;
    a.insert({0,x});
    res.insert(x);
    while(n--)
    {
        cin>>p;
        auto v=a.upper_bound({p,0});
        v--;
        l=(*v).first;
        r=(*v).second;
        a.erase(v);
        auto k=res.find(r-l);
        res.erase(k);
        a.insert({l,p});
        res.insert(p-l);
        a.insert({p,r});
        res.insert(r-p);
        cout<<*res.rbegin()<<' ';
    }
    return 0;
}