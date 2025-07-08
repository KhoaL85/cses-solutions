#include <iostream>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
int n, u, v, res;
vector<int>g[200002];
pair<int,int>dfs(int u, int pr=0)
{
    int s1=0, s2=0, tmp;
    for(auto v:g[u])
    {
        if(v==pr)
            continue;
        tmp=dfs(v,u).f+1;
        if(tmp>=s1)
        {
            s2=s1;
            s1=tmp;
        }
        else if(tmp>s2)
            s2=tmp;
    }
    res=max(res,s1+s2);
    return {s1,s2};
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
    dfs(1);
    cout<<res;
    return 0;
}