#include <iostream>
#include <unordered_map>
#include <queue>
#include <fstream>

using namespace std;
const int maxN=2e5+3;

int n, a[maxN], u, v, res[maxN];
vector<int>g[maxN];
unordered_map<int,int>*cnt[maxN];
void dfs(int u, int pr=0)
{
    int big=0;
    for(auto &v:g[u])
        if(v!=pr)
        {
            dfs(v,u);
            if(!big||(*cnt[v]).size()>(*cnt[big]).size())
                big=v;
        }
    if(big)
    {
        cnt[u]=cnt[big];
        res[u]=res[big];
    }
    else
        cnt[u]=new unordered_map<int,int>();
    res[u]+=(++(*cnt[u])[a[u]]==1);
    for(auto &v:g[u])
        if(v!=pr&&v!=big)
            for(auto &[col,w]:*cnt[v])
            {
                if((*cnt[u])[col]==0)
                    res[u]++;
                (*cnt[u])[col]+=w;
            }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        cout<<res[i]<<' ';
    return 0;
}