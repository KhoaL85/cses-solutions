#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int n, u, v, sz[200002];
vector<int>g[200002];
void dfsSiz(int u, int pr=0)
{
    sz[u]=1;
    for(auto &v:g[u])
        if(v!=pr)
        {
            dfsSiz(v,u);
            sz[u]+=sz[v];
        }
}
int getCentroid(int u, int pr=0)
{
    for(auto &v:g[u])
        if(v!=pr&&sz[v]>n/2)
            return getCentroid(v,u);
    return u;
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
    dfsSiz(1);
    cout<<getCentroid(1);
    return 0;
}
