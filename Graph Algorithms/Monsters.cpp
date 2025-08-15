#include <iostream>
#include <climits>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;

int n, m, s, t, danger[1002][1002], x, y, u, v;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char a[1002][1002], dir[]={'D','R','U','L'};
pair<pair<int,int>,char>tr[1002][1002];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
void findMons()
{
    while(!q.empty())
    {
        auto tmp=q.top();
        q.pop();
        auto du=tmp.f;
        u=tmp.se.f;
        v=tmp.se.se;
        if(du!=danger[u][v])
            continue;
        for(int i=0;i<4;i++)
        {
            x=u+dx[i];
            y=v+dy[i];
            if(x<1||y<1||x>n||y>m||a[x][y]=='#')
                continue;
            if(danger[x][y]>danger[u][v]+1)
            {
                danger[x][y]=danger[u][v]+1;
                q.push({danger[x][y],{x,y}});
            }
        }
    }
}
bool c[1002][1002];
void solve()
{
    q.push({0,{s,t}});
    c[s][t]=1;
    s=t=-1;
    while(!q.empty())
    {
        auto tmp=q.top();
        q.pop();
        auto du=tmp.f;
        u=tmp.se.f;
        v=tmp.se.se;
        if(u==1||v==1||u==n||v==m)
        {
            s=u;
            t=v;
            return;
        }
        for(int i=0;i<4;i++)
        {
            x=u+dx[i];
            y=v+dy[i];
            if(x<1||y<1||x>n||y>m||a[x][y]=='#'||c[x][y])
                continue;
            if(danger[x][y]>du+1)
            {
                tr[x][y]={{u,v},dir[i]};
                c[x][y]=1;
                q.push({du+1,{x,y}});
            }
        }
    }
}
vector<char>ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            danger[i][j]=INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='M')
            {
                q.push({0,{i,j}});
                danger[i][j]=0;
            }
            if(a[i][j]=='A')
            {
                s=i;
                t=j;
            }
        }
    findMons();
    solve();
    if(s==-1)
        return cout<<"NO", 0;
    cout<<"YES\n";
    while(tr[s][t].f.f)
    {
        ans.push_back(tr[s][t].se);
        u=tr[s][t].f.f;
        v=tr[s][t].f.se;
        s=u;
        t=v;
    }
    cout<<ans.size()<<'\n';
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}