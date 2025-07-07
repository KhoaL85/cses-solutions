#include <iostream>
#include <climits>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
int n, m, k, u, l, mx[100002], mn[100002], v;
long long d[100002], cnt[100002], mod=1000000007;
bool c[100002];
vector<pair<int,int>>a[100002];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
void JQK(int s)
{
    for(int i=1;i<=n;i++)
        d[i]=LLONG_MAX;
    d[s]=0;
    cnt[s]=1;
    q.push({0,s}); /// {du,u}
    while(!q.empty())
    {
        auto tmp=q.top();
        q.pop();
        u=tmp.se;
        if(c[u])
            continue;
        c[u]=1;
        for(auto &[v,w]:a[u])
        {
            if(d[v]-w>d[u])
            {
                d[v]=d[u]+w;
                cnt[v]=cnt[u];
                mx[v]=mx[u]+1;
                mn[v]=mn[u]+1;
                q.push({d[v],v});
            }
            else if(d[v]-w==d[u])
            {
                cnt[v]=(cnt[v]+cnt[u])%mod;
                mx[v]=max(mx[v],mx[u]+1);
                mn[v]=min(mn[v],mn[u]+1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("Investigation.inp", "r")) {
        freopen("Investigation.inp", "r", stdin);
        freopen("Investigation.out", "w", stdout); }
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v>>l;
        a[u].push_back({v,l});
    }
    JQK(1);
    cout<<d[n]<<' '<<cnt[n]<<' '<<mn[n]<<' '<<mx[n];
    return 0;
}
