#include <iostream>
#include <climits>
#include <fstream>

using namespace std;
int n, m, q, u, v, c;
long long a[502][502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=(i==j?0:LLONG_MAX);
    while(m--)
    {
        cin>>u>>v>>c;
        a[u][v]=min(a[u][v],1LL*c);
        a[v][u]=a[u][v];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][k]!=LLONG_MAX&&a[k][j]!=LLONG_MAX)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    while(q--)
    {
        cin>>u>>v;  
        cout<<(a[u][v]==LLONG_MAX?-1:a[u][v])<<'\n';
    }
    return 0;
}