#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3,unroll-loops,no-stack-protector")
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
const int maxN=2e5+5;

int n, q, a[maxN], u, v, h[maxN], head[maxN], chain[maxN], pos[maxN], curChain, curPos, st[4*maxN], sz[maxN], p[maxN], val[maxN];
vector<int>g[maxN];
void dfs(int u, int pr=0)
{
    sz[u]=1;
    for(auto &v:g[u])
        if(v!=pr)
        {
            p[v]=u;
            h[v]=h[u]+1;
            dfs(v,u);
            sz[u]+=sz[v];
        }
}
void hld(int u, int pr=0)
{
    if(!head[curChain])
        head[curChain]=u;
    chain[u]=curChain;
    pos[u]=curPos;
    a[curPos]=u;
    curPos++;
    int big=0;
    for(auto &v:g[u])
        if(v!=pr&&sz[v]>sz[big])
            big=v;
    if(big)
        hld(big,u);
    for(auto &v:g[u])
        if(v!=pr&&v!=big)
        {
            curChain++;
            hld(v,u);
        }
}
int LCA(int u, int v)
{
    while(chain[u]!=chain[v])
    {
        if(chain[u]>chain[v])
            u=p[head[chain[u]]];
        else
            v=p[head[chain[v]]];
    }
    return (h[u]<h[v]?u:v);
}
void build(int id, int l, int r)
{
    if(l==r)
    {
        st[id]=val[a[l]];
        return;
    }
    int m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    st[id]=max(st[2*id],st[2*id+1]);
}
void update(int id, int l, int r, int i, int x)
{
    if(l==r)
    {
        st[id]=x;
        return;
    }
    int m=(l+r)/2;
    if(i<=m)
        update(2*id,l,m,i,x);
    else
        update(2*id+1,m+1,r,i,x);
    st[id]=max(st[2*id],st[2*id+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[id];
    int m=(l+r)/2;
    return max(get(2*id,l,m,u,v),get(2*id+1,m+1,r,u,v));
}
int get(int u, int v)
{
    int e=LCA(u,v), res=0;
    while(chain[u]!=chain[e])
    {
        res=max(res,get(1,1,n,pos[head[chain[u]]],pos[u]));
        u=p[head[chain[u]]];
    }
    while(chain[v]!=chain[e])
    {
        res=max(res,get(1,1,n,pos[head[chain[v]]],pos[v]));
        v=p[head[chain[v]]];
    }
    res=max(res,(h[u]<h[v]?get(1,1,n,pos[u],pos[v]):get(1,1,n,pos[v],pos[u])));
    return res;
}
void init()
{
    dfs(1);
    hld(1);
    build(1,1,n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    curPos=curChain=1;
    init();
    while(q--)
    {
        cin>>u;
        if(u==1)
        {
            cin>>u>>v;
            update(1,1,n,pos[u],v);
        }
        else
        {
            cin>>u>>v;
            cout<<get(u,v)<<' ';
        }
    }
    return 0;
}