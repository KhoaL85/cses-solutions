#include <iostream>
#include <fstream>
#include <set>
#define f first
#define se second

using namespace std;
const int maxN=2e5+2;

int n, m, a[maxN], pos[maxN], res=1, u, v;
set<pair<int,int>>s;
void modify(bool k)
{
    for(auto x:s)
        if(x.f&&x.se<=n)
            res=res+(pos[x.f]>pos[x.se])*(k?1:-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<n;i++)
        res+=(pos[i]>pos[i+1]);
    while(m--)
    {
        s.clear();
        cin>>u>>v;
        s.insert({a[u]-1,a[u]});
        s.insert({a[u],a[u]+1});
        s.insert({a[v]-1,a[v]});
        s.insert({a[v],a[v]+1});

        modify(0);
        
        swap(pos[a[u]],pos[a[v]]);
        swap(a[u],a[v]);

        modify(1);
        cout<<res<<'\n';
    }
    return 0;
}