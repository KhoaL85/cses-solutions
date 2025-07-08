#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
int n, m, p[200002], a, b, x, up[18][200002], h[200002], f[200002];
vector<int>g[200002];
void dfs(int u)
{
    for(auto v:g[u])
    {
        if(v==p[u])
            continue;
        h[v]=h[u]+1;
        p[v]=u;
        dfs(v);
    }
}
void process()
{
    dfs(1);
    for(int i=1;i<=n;i++)
        up[0][i]=p[i];
    for(int j=1;j<18;j++)
        for(int u=1;u<=n;u++)
            up[j][u]=up[j-1][up[j-1][u]];
}
int LCA(int u, int v)
{
    if(h[u]<h[v])
        swap(u,v);
    for(int j=0;(1<<j)<=h[u]-h[v];j++)
        if((h[u]-h[v])>>j&1)
            u=up[j][u];
    if(u==v)
        return u;
    for(int j=17;j>=0;j--)
        if(up[j][u]!=up[j][v])
        {
            u=up[j][u];
            v=up[j][v];
        }
    return up[0][u];
}
void sumUp(int u)
{
    for(auto v:g[u])
    {
        if(v==p[u])
            continue;
        sumUp(v);
        f[u]+=f[v];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    process();
    while(m--)
    {
        cin>>a>>b;
        f[a]++;
        f[b]++;
        x=LCA(a,b);
        f[x]--;
        f[up[0][x]]--;
    }
    sumUp(1);
    for(int i=1;i<=n;i++)
        cout<<f[i]<<' ';
    return 0;
}