#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <vector>

using namespace std;
int n, m, s, t, u, v, tr[100002];
vector<int>a[100002];
queue<int>q;
bool c[100002];
void bfs(int u)
{
    q.push(u);
    c[u]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto v:a[x])
            if(!c[v])
            {
                c[v]=1;
                q.push(v);
                tr[v]=x;
                if(v==t)
                    return;
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    s=1;
    t=n;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        sort(a[i].begin(),a[i].end());
    bfs(s);
    if(!c[t])
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    u=t;
    while(u)
    {
        a[0].push_back(u);
        u=tr[u];
    }
    cout<<a[0].size()<<'\n';
    for(int i=a[0].size()-1;i>=0;i--)
        cout<<a[0][i]<<' ';
    return 0;
}