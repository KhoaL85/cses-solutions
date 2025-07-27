#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int a[9][9], x, y;
int dx[]={-2,-1,1,2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
bool check(int x, int y)
{
    return 1<=x&&x<=8&&1<=y&&y<=8;
}
int cnt(int x, int y)
{
    int s=0;
    for(int i=0;i<8;i++)
    {
        int u=x+dx[i], v=y+dy[i];
        s+=(check(u,v)&&!a[u][v]);
    }
    return s;
}
void dfs(int x, int y)
{
    if(a[x][y]==64)
    {
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
                cout<<a[j][i]<<' ';
            cout<<'\n';
        }
        exit(0);
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    for(int i=0;i<8;i++)
    {
        int u=x+dx[i], v=y+dy[i];
        if(check(u,v)&&!a[u][v])
            q.push({cnt(u,v),{u,v}});
    }
    while(!q.empty())
    {
        auto [u,v]=q.top().second;
        q.pop();
        a[u][v]=a[x][y]+1;
        dfs(u,v);
        a[u][v]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("Knight'sTour.inp", "r")) {
        freopen("Knight'sTour.inp", "r", stdin);
        freopen("Knight'sTour.out", "w", stdout); }
    cin>>x>>y;
    a[x][y]=1;
    dfs(x,y);
    return 0;
}