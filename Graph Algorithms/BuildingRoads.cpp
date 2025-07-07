#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int n, u, v, m, res;
vector<int>a[100002], dsu;
bool c[100002];
void dfs(int u)
{
    c[u]=true;
    for(auto v:a[u])
        if(!c[v])
            dfs(v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!c[i])
        {
            dsu.push_back(i);
            dfs(i);
        }
    cout<<dsu.size()-1<<'\n';
    for(int i=1;i<dsu.size();i++)
        cout<<dsu[i-1]<<' '<<dsu[i]<<'\n';
    return 0;
}
