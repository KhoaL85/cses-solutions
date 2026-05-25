#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int N=1e5+5;

int n, m, u, v, p[N], cnt;
long long res;
struct Edge{
    int u, v, w;
    bool operator<(Edge &other){
        return w<other.w;
    };
} e[200002];
int fset(int u)
{
    return p[u]==u?u:p[u]=fset(p[u]);
}
void unite(int u, int v, int w)
{
    u=fset(u);
    v=fset(v);
    if(u==v)
        return;
    cnt++;
    res+=w;
    p[u]=v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        p[i]=i;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++)
        unite(e[i].u,e[i].v,e[i].w);
    if(cnt==n-1)
        cout<<res;
    else
        cout<<"IMPOSSIBLE";
    return 0;
}