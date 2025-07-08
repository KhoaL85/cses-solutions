#include <iostream>
#include <fstream>

using namespace std;
int n, q, p[200002], x, k, up[18][200002];
void process()
{
    for(int i=1;i<=n;i++)
        up[0][i]=p[i];
    for(int j=1;j<18;j++)
        for(int i=1;i<=n;i++)
            up[j][i]=up[j-1][up[j-1][i]];
}
int ancestor(int u, int k)
{
    for(int j=0;(1<<j)<=k;j++)
        if((k>>j)&1)
            u=up[j][u];
    return u?u:-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=2;i<=n;i++)
        cin>>p[i];
    process();
    while(q--)
    {
        cin>>x>>k;
        cout<<ancestor(x,k)<<'\n';
    }
    return 0;
}