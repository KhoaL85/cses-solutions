#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int maxN=1e5+5;

int n, m, u, v, in[maxN];
vector<int>g[maxN], ans, s;
void top(vector<int>&topo)
{
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            s.push_back(i);
    while(!s.empty())
    {
        u=s.back();
        s.pop_back();
        topo.push_back(u);
        for(auto &v:g[u])
            if(!(--in[v]))
                s.push_back(v);
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
    top(ans);
    if(ans.size()!=n)
        return cout<<"IMPOSSIBLE", 0;
    for(auto u:ans)
        cout<<u<<' ';
    return 0;
}