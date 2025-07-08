#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
int n, u, v, s, t, cur, ans, d[3][200002];
vector<int>g[200002];
void FIND(int u, int pr=0)
{
    for(auto v:g[u])
    {
        if(v==pr)
            continue;
        d[0][v]=d[0][u]+1;
        FIND(v,u);
        if(d[0][v]>cur)
        {
            cur=d[0][v];
            ans=v;
        }
    }
}
void furthest(int S, int &a)
{
    for(int i=1;i<=n;i++)
        d[0][i]=0;
    cur=0;
    ans=1;
    FIND(S);
    a=ans;
}
void dis(int u, int pr, bool k)
{
    for(auto v:g[u])
    {
        if(v==pr)
            continue;
        d[k][v]=d[k][u]+1;
        dis(v,u,k);
    }
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
    furthest(1,s);
    furthest(s,t);
    dis(s,0,0);
    dis(t,0,1);
    for(int i=1;i<=n;i++)
        cout<<max(d[0][i],d[1][i])<<' ';
    return 0;
}