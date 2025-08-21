#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int maxN=2e5+3;

int n, u, v, sz[maxN];
long long down[maxN], up[maxN];
vector<int>g[maxN];
void dfsDown(int u, int pr=0)
{
    sz[u]=1;
    for(auto &v:g[u])
        if(v!=pr)
        {
            dfsDown(v,u);
            sz[u]+=sz[v];
            down[u]+=down[v]+sz[v];
        }
}
void dfsUp(int u, int pr=0)
{
    if(pr)
        up[u]=up[pr]+n-sz[pr]+1+down[pr]-down[u]-sz[u]+sz[pr]-sz[u]-1;
    for(auto &v:g[u])
        if(v!=pr)
            dfsUp(v,u);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsDown(1);
    dfsUp(1);
    for(int i=1;i<=n;i++)
        cout<<up[i]+down[i]<<' ';
    return 0;
}