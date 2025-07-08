#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int n, res[200002], u;
vector<int>g[200002];
void dfs(int u, int pr)
{
    for(auto v:g[u])
        if(v!=pr)
        {
            dfs(v,u);
            res[u]+=res[v]+1;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>u;
        g[u].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        cout<<res[i]<<' ';
    return 0;
}