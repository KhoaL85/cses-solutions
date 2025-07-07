#include <iostream>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
int n, d[1002][1002], du, u, v, x, y;
queue<pair<int,pair<int,int>>>q;
int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
void bfs()
{
    q.push({0,{1,1}});
    while(!q.empty())
    {
        auto tmp=q.front();
        q.pop();
        du=tmp.f;
        u=tmp.se.f;
        v=tmp.se.se;
        for(int i=0;i<8;i++)
        {
            x=u+dx[i];
            y=v+dy[i];
            if((x==1&&y==1)||x<1||y<1||x>n||y>n||d[x][y])
                continue;
            d[x][y]=du+1;
            q.push({du+1,{x,y}});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    bfs();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<d[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}