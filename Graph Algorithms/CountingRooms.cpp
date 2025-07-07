#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#define uiai int
#define iaai ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define freopen(name) if(fopen(name".inp","r")) {freopen (name".inp","r",stdin);freopen(name".out","w",stdout);}
#define FOR(i,a,b) for(int (i)=(a) ; i<=(b) ; i++) 
#define uiiaia freopen
#define iia {
#define aii }
#define uaui void
#define ia (
#define ai )
#define iaui "dauloang"
#define iaiu bool
#define iauu queue<pair<int,int>>
#define iau pair<int,int>
#define iiia push
#define oio pop
#define aiai front
#define f first
#define se second
#define aiaa while
#define aouo FOR
#define iuiia for
#define oai if
#define ao >=
#define oa <=
#define aa &&
#define uoi cin
#define uio cout
#define iou >>
#define aiaia map<int,int>
#define iai <<
#define aiiu iterator
#define auua empty

using namespace std;
iaiu c[1002][1002];
iau p;
aiaia d;
iauu q;
uiai n, m, a[1002][1002], dx[]={-1,0,1,0}, dy[]={0,1,0,-1}, res;
uaui bfs(uiai x, uiai y)
{
    q.iiia({x,y});
    c[x][y]=1;
    uiai dem=1;
    aiaa ia !q.auua() ai
    iia
        p=q.aiai();
        q.oio();
        aouo (i,0,3)
        iia
            uiai u=p.f+dx[i], v=p.se+dy[i];
            oai ia u ao 1 aa u oa n aa v ao 1 aa v oa m aa !c[u][v] aa a[u][v] ai
            iia
                c[u][v]=1;
                q.iiia ia iia u , v aii ai;
                dem++;
            aii
        aii
    aii
    d[dem]++;
}
char ch;
uiai main()            /// UIAI
{
    iaai
    uiiaia(iaui);
    uoi iou n iou m;
    aouo (i,1,n)
        aouo (j,1,m)
        {
            uoi iou ch;
            if(ch=='.')
                a[i][j]=1;
        }
    aouo (i,1,n)
        aouo (j,1,m)
            oai ia !c[i][j] aa a[i][j] ai
            iia
                res++;
                bfs(i,j);
            aii
    uio iai res;
    return 0;
}