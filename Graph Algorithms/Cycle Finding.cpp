#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#define f first
#define se second

using namespace std;
const int maxN=2504;

int n, m, u, v, w, tr[maxN];
long long d[maxN];
vector<pair<pair<int,int>,int>>e;
vector<int>path;
void bellman_ford(int s)
{
    for(int i=1;i<=n;i++)
    {
        d[i]=1e18;
        tr[i]=-1;
    }
    d[s]=0;
    for(int i=1;i<n;i++)
        for(auto edge:e)
        {
            u=edge.f.f;
            v=edge.f.se;
            w=edge.se;
            if(d[v]-w>d[u])
            {
                d[v]=d[u]+w;
                tr[v]=u;
            }
        }
}
void trace(int s, int u, vector<int>&path)
{
    if(u!=s&&tr[u]==-1)
        return;
    while(u!=-1)
    {
        path.push_back(u);
        u=tr[u];
    }
    reverse(path.begin(),path.end());
}
void negativeCycle(vector<int>&path)
{
    int s=-1;
    for(auto edge:e)
    {
        u=edge.f.f;
        v=edge.f.se;
        w=edge.se;
        if(d[v]-w>d[u])
        {
            tr[v]=u;
            s=v;
            break;
        }
    }
    if(s==-1)
        return;
    u=s;
    for(int i=1;i<=n;i++)
        u=tr[u];
    
    path.push_back(u);
    for(int v=tr[u];v!=u;v=tr[v])
        path.push_back(v);
    path.push_back(u);
    reverse(path.begin(),path.end());
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v>>w;
        e.push_back({{u,v},w});   
    }
    bellman_ford(1);
    negativeCycle(path);
    if(path.empty())
        return cout<<"NO", 0;
    cout<<"YES\n";
    for(auto x:path)
        cout<<x<<' ';
    return 0;
}