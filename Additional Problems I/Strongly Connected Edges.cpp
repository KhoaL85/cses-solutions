#include <iostream>
#include <queue>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, m, u, v, cnt, low[100002], num[100002], dem;
bool c[100002], vs[100002];
vector<pair<int,int>>a[100002], res;
bool kt=1;
void tarzan(int u, int pr)
{
    low[u]=num[u]=++cnt;
    vs[u]=1;
    dem++;
    int v, child=0;
    for(auto x:a[u])
    {
        v=x.f;
        if(v==pr)
            continue;
        if(vs[v])
            low[u]=min(low[u],num[v]);
        else
        {
            if(!c[x.se])
            {
                c[x.se]=1;
                res.push_back({u,v});
            }
            tarzan(v,u);
            if(!kt)
                return;
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u])
            {
                kt=0;
                cout<<u<<' '<<v<<'\n';
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
        cnt++;
        a[u].push_back({v,cnt});
        a[v].push_back({u,cnt});
    }
    tarzan(1,0);
    if(!kt||dem!=n)
        cout<<"IMPOSSIBLE";
    else
        for(auto x:res)
            cout<<x.f<<' '<<x.se<<'\n';
    return 0;
}