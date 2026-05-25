#include <iostream>
#include <fstream>

using namespace std;
const int N=1e5+5;

int n, m, u, v, p[N], cnt, mx;
int fset(int u)
{
    return p[u]<0?u:p[u]=fset(p[u]);
}
bool unite(int u, int v)
{
    u=fset(u);
    v=fset(v);
    if(u==v)
        return 0;
    p[v]+=p[u];
    p[u]=v;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        p[i]=-1;
    cnt=n;
    mx=1;
    while(m--)
    {
        cin>>u>>v;
        if(unite(u,v))
        {
            cnt--;
            mx=max(mx,-p[fset(u)]);
        }
        cout<<cnt<<' '<<mx<<'\n';
    }
    return 0;
}