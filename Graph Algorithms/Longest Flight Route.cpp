#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
const int maxN=1e5+5;

int n, m, u, v, dp[maxN], tr[maxN], in[maxN], cnt[maxN], c[maxN];
vector<int>g[maxN], ans, a[maxN];
void validate(int u)
{
    c[u]=1;
    for(auto v:a[u])
    {
        g[u].push_back(v);
        in[v]++;
        if(!c[v])
            validate(v);
    }
}
void dfs(int u)
{
    if(cnt[u]<in[u])
        return;
    for(auto v:g[u])
    {
        if(dp[v]<dp[u]+1)
        {
            dp[v]=dp[u]+1;
            tr[v]=u;
        }
        cnt[v]++;
        dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        a[u].push_back(v);
    }
    dp[1]=1;
    validate(1);
    dfs(1);
    if(!dp[n])
        return cout<<"IMPOSSIBLE", 0;
    u=n;
    while(u)
    {
        ans.push_back(u);
        u=tr[u];
    }
    cout<<ans.size()<<'\n';
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<' ';
    return 0;
}