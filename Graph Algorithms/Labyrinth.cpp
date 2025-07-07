#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
char a[1002][1002], dt[]={'U','R','D','L'}, tr[1002][1002];
bool kt;
int n, m, dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
queue<pair<int,int>>q;
pair<int,int>p1, p2, p;
bool c[1002][1002];
pair<int,int>trace(pair<int,int>x)
{
    if(tr[x.f][x.se]=='U')
        return {x.f+1,x.se};
    if(tr[x.f][x.se]=='R')
        return {x.f,x.se-1};
    if(tr[x.f][x.se]=='D')
        return {x.f-1,x.se};
    if(tr[x.f][x.se]=='L')
        return {x.f,x.se+1};
    return {0,0};
}
void bfs(int x, int y)
{
    c[x][y]=1;
    q.push({x,y});
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int d=0;d<=3;d++)
        {
            int u=p.f+dx[d], v=p.se+dy[d];
            if(1<=u&&u<=n&&1<=v&&v<=m&&!c[u][v]&&a[u][v]!='#')
            {
                c[u][v]=1;
                q.push({u,v});
                tr[u][v]=dt[d];
                if(a[u][v]=='B')
                {
                    kt=1;
                    return;
                }
            }
        }
    }
}
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
                p1={i,j};
            if(a[i][j]=='B')
                p2={i,j};
        }
    bfs(p1.f,p1.se);
    if(!kt)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    while(p2.f!=0)
    {
        if(isalpha(tr[p2.f][p2.se]))
            s.push_back(tr[p2.f][p2.se]);
        else
            break;
        p2=trace(p2);
    }
    reverse(s.begin(),s.end());
    cout<<s.size()<<'\n'<<s;
    return 0;
}