#include <iostream>
#include <climits>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
int n, m, u, v, l;
long long d[100002][2];
bool c[100002][2];
vector<pair<int,int>>a[100002];
priority_queue<pair<long long,pair<int,bool>>,vector<pair<long long,pair<int,bool>>>,greater<pair<long long,pair<int,bool>>>>q;
void JQK(int s)
{
    for(int i=1;i<=n;i++)
    {
        d[i][0]=d[i][1]=LLONG_MAX;
        // c[i][0]=c[i][1]=0;
    }
    d[s][0]=0;
    q.push({d[s][0],{s,0}});
    while(!q.empty())
    {
        auto [u,stat]=q.top().se;
        q.pop();
        if(c[u][stat])
            continue;
        c[u][stat]=1;
        for(auto &[v,w]:a[u])
        {
            if(d[v][stat]-w>d[u][stat])
            {
                d[v][stat]=d[u][stat]+w;
                q.push({d[v][stat],{v,stat}});
            }
            if(!stat&&d[v][1]-w/2>d[u][0])
            {
                d[v][1]=d[u][0]+w/2;
                q.push({d[v][1],{v,1}});
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
        cin>>u>>v>>l;
        a[u].push_back({v,l});
    }
    JQK(1);
    cout<<d[n][1];
    return 0;
}