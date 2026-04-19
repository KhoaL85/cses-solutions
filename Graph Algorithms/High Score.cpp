#include <iostream>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;
const int N=2505, M=5003;
const long long INF=1e16;

int n, m, u, v, w, tr[N];
long long d[N], dn[N];
struct Edge{
    int u, v, w;
    void tie(int &_u, int &_v, int &_w)
    {
        _u=u;
        _v=v;
        _w=w;
    }
} e[M];
void bellmanFord(int S, long long d[])
{
    for(int i=0;i<=n;i++)
        d[i]=INF;
    d[S]=0;
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
        {
            e[j].tie(u,v,w);
            if(S==n)
                swap(u,v);
            if(d[u]!=INF&&d[v]>d[u]+w)
                d[v]=d[u]+w;
        }
}
bool check(int neg)
{
    u=neg;
    for(int i=1;i<=n;i++)
    {
        if(!tr[u])
            break;
        u=tr[u];
    }
    for(v=tr[u];v!=u&&v;v=tr[v])
        if(d[v]!=INF&&dn[v]!=INF)
            return 1;
    return d[u]!=INF&&dn[u]!=INF;
}
bool isNegative()
{
    vector<int>neg;
    for(int j=1;j<=m;j++)
    {
        e[j].tie(u,v,w);
        if(d[v]>d[u]+w)
        {
            tr[v]=u;
            neg.push_back(v);
        }
    }
    for(auto x:neg)
        if(check(x))
            return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].w=-e[i].w;
    }
    bellmanFord(1,d);
    bellmanFord(n,dn);
    cout<<(isNegative()?-1:-d[n]);
    return 0;
}