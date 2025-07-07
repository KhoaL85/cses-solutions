#include <iostream>
#include <climits>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
int n, m, k, x, y, l;
long long d[100002];
bool c[100002];
vector<pair<int,int>>a[100002];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
void JQK(int s)
{
    for(int i=1;i<=n;i++)
        d[i]=LLONG_MAX;
    d[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        auto [du,u]=q.top();
        q.pop();
        if(!c[u])
        {
            c[u]=1;
            for(auto &[v,w]:a[u])
            {
                if(d[v]-w>d[u])
                {
                    d[v]=d[u]+w;
                    q.push({d[v],v});
                    // tr[v]=u;
                }
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
        cin>>x>>y>>l;
        a[x].push_back({y,l});
    }
    JQK(1);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<' ';
    return 0;
}
