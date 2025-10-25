#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int maxN=1e5+5, mod=1e9+7;

int n, m, u, v, dp[maxN], cnt[maxN], in[maxN];
vector<int>g[maxN];
void dfs(int u)
{
    cnt[u]++;
    if(cnt[u]<in[u])
        return;
    for(int &v:g[u])
    {
        (dp[v]+=dp[u])%=mod;
        dfs(v);
    }
}
void del()
{
    queue<int>q;
    for(int i=2;i<=n;i++)
        if(!in[i])
            q.push(i);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int &v:g[u])
            if(--in[v]==0)
                q.push(v);
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
        g[u].push_back(v);
        in[v]++;
    }
    del();
    dp[1]=1;
    dfs(1);
    cout<<dp[n];
    return 0;
}