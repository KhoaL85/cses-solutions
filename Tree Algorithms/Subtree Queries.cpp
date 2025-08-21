#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int maxN=2e5+3;

int n, q, a[maxN], out[maxN], cnt, u, v, in[maxN];
long long st[4*maxN];
vector<int>g[maxN];
void number(int u, int pr=0)
{
    in[u]=++cnt;
    for(auto &v:g[u])
        if(v!=pr)
            number(v,u);
    out[u]=cnt;
}
void update(int id, int l, int r, int i, int val)
{
    if(l==r)
    {
        st[id]+=val;
        return;
    }
    int m=(l+r)/2;
    if(i<=m)
        update(2*id,l,m,i,val);
    else
        update(2*id+1,m+1,r,i,val);
    st[id]=st[2*id]+st[2*id+1];
}
long long get(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[id];
    int m=(l+r)/2;
    return get(2*id,l,m,u,v)+get(2*id+1,m+1,r,u,v);
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
    number(1);
    for(u=1;u<=n;u++)
        update(1,1,n,in[u],a[u]);
    while(q--)
    {
        cin>>u;
        if(u==1)
        {
            cin>>u>>v;
            update(1,1,n,in[u],v-a[u]);
            a[u]=v;
        }
        else
        {
            cin>>u;
            cout<<get(1,1,n,in[u],out[u])<<'\n';
        }
    }
    return 0;
}