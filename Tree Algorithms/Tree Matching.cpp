#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
const int INF=10000000;
int n, u, v, dp[2][200002];
vector<int>g[200002];
void dfs(int u, int pr=0)
{
    dp[0][u]=0;
    dp[1][u]=-INF;
    for(auto v:g[u])
    {
        if(v==pr)
            continue;
        dfs(v,u);
        dp[0][u]+=max(dp[0][v],dp[1][v]);
        dp[1][u]=max(dp[1][u],min(dp[0][v]-dp[1][v],0));
    }
    dp[1][u]+=dp[0][u]+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout<<max(dp[0][1],dp[1][1]);
    return 0;
}