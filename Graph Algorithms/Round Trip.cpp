#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int maxN=1e5+5;

int n, m, u, v, h[maxN];
bool c[maxN];
vector<int>g[maxN], s, ans;
void dfs(int u, int pr=0)
{
    h[u]=h[pr]+1;
    c[u]=1;
    s.push_back(u);
    for(auto v:g[u])
        if(v!=pr)
        {
            if(c[v])
            {
                if(h[u]-h[v]<2)
                    continue;
                ans.push_back(v);
                while(s.back()!=v)
                {
                    ans.push_back(s.back());
                    s.pop_back();
                }
                ans.push_back(v);
                cout<<ans.size()<<'\n';
                for(auto x:ans)
                    cout<<x<<' ';
                exit(0);
            }
            else
                dfs(v,u);
        }
    s.pop_back();
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
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!c[i])
            dfs(i);
    cout<<"IMPOSSIBLE";
    return 0;
}