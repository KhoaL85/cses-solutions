#include <iostream>
#include <queue>
#include <fstream>
 
using namespace std;
const int N=2e5+5;
 
int n, m, a[N], u, v, tr[N], c[N];
vector<int>g[N], ans;
void dfs(int u, int pr=0)
{
    c[u]=1;
    tr[u]=pr;
    for(auto &v:g[u])
    {
        if(c[v]==1)
        {
            int tmp=u;
            ans.push_back(tmp);
            while(tmp!=v)
            {
                tmp=tr[tmp];
                ans.push_back(tmp);
            }

            cout<<ans.size()+1<<'\n';
            for(int i=ans.size()-1;i>=0;i--)
                cout<<ans[i]<<' ';
            cout<<v;
            exit(0);
        }
        if(!c[v])
            dfs(v,u);
    }
    c[u]=2;
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
    }
    for(int i=1;i<=n;i++)
        if(!c[i])
            dfs(i);
    cout<<"IMPOSSIBLE";
    return 0;
}