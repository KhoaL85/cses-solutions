#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int n, m, u, v, t[100002];
vector<int>a[100002];
queue<int>q;
bool kt;
void bfs(int s)
{
    q.push(s);
    t[s]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto v:a[u])
        {
            if(!t[v])
            {
                t[v]=3-t[u];
                q.push(v);
            }
            else if(t[v]==t[u])
            {
                kt=1;
                return;
            }
        }
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
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!t[i])
        {
            bfs(i);
            if(kt)
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    for(int i=1;i<=n;i++)
        cout<<t[i]<<' ';
    return 0;
}