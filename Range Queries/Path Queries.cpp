#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int maxN=2e5+4;

int n, q, a[maxN], u, v, cnt, in[maxN], out[maxN];
long long res[maxN], st[4*maxN], lazy[4*maxN];
vector<int>g[maxN];
void dfs(int u, int pr=0)
{
    in[u]=++cnt;
    res[u]=res[pr]+a[u];
    for(auto &v:g[u])
        if(v!=pr)
            dfs(v,u);
    out[u]=cnt;
}
void prop(int id, int l, int r)
{
    int m=(l+r)/2;
    st[2*id]+=lazy[id]*(m-l+1);
    st[2*id+1]+=lazy[id]*(r-m);
    lazy[2*id]+=lazy[id];
    lazy[2*id+1]+=lazy[id];
    lazy[id]=0;
}
void update(int id, int l, int r, int u, int v, long long val)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        st[id]+=val*(r-l+1);
        lazy[id]+=val;
        return;
    }
    prop(id,l,r);
    int m=(l+r)/2;
    update(2*id,l,m,u,v,val);
    update(2*id+1,m+1,r,u,v,val);
    st[id]=st[2*id]+st[2*id+1];
}
long long get(int id, int l, int r, int i)
{
    if(l==r)
        return st[id];
    int m=(l+r)/2;
    prop(id,l,r);
    if(i<=m)
        return get(2*id,l,m,i);
    return get(2*id+1,m+1,r,i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    while(q--)
    {
        cin>>u;
        if(u==1)
        {
            cin>>u>>v;
            update(1,1,n,in[u],out[u],v-a[u]);
            a[u]=v;
        }
        else
        {
            cin>>u;
            cout<<res[u]+get(1,1,n,in[u])<<'\n';
        }
    }
    return 0;
}