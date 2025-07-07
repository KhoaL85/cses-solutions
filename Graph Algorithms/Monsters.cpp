#include <iostream>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
int n, m, d[1002][1002], dx[]={-1,0,1,0}, dy[]={0,-1,0,1}, u, v, p1, p2;
char a[1002][1002];
bool c[1002][1002];
queue<pair<int,int>>q;
pair<int,int>p;
vector<pair<int,int>>ms, fl;
void bfs1(int x, int y)
{
    for(auto v:ms)
        c[v.f][v.se]=0;
    for(auto v:fl)
        c[v.f][v.se]=0;
    q.push({x,y});
    c[x][y]=1;
    d[x][y]=0;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            u=p.f+dx[i];
            v=p.se+dy[i];
            if(1<=u&&u<=n&&1<=v&&v<=m&&!c[u][v]&&a[u][v]!='#')
            {
                c[u][v]=1;
                d[u][v]=min(d[u][v],d[p.f][p.se]+1);
                q.push({u,v});
            }
        }
    }
}
void bfs2(int x, int y)
{
    for(auto v:ms)
        c[v.f][v.se]=0;
    for(auto v:fl)
        c[v.f][v.se]=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='M')
                ms.push_back({i,j});
            if(a[i][j]=='.')
                fl.push_back({i,j});
            if(a[i][j]=='A')
            {
                p1=i;
                p2=j;
            }
            d[i][j]=10000000;
        }
    for(auto x:ms)
        bfs1(x.f,x.se);
    
    return 0;
}