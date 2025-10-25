#include <iostream>
#include <fstream>

using namespace std;
const int maxN=2e5+5;

int n, q, u, up[31][maxN], k;
void init()
{
    for(int j=1;j<=30;j++)
        for(int i=1;i<=n;i++)
            up[j][i]=up[j-1][up[j-1][i]];
}
int get(int u, int k)
{
    for(int i=0;i<=30;i++)
        if(k>>i&1)
            u=up[i][u];
    return u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>up[0][i];
    init();
    while(q--)
    {
        cin>>u>>k;
        cout<<get(u,k)<<'\n';
    }
    return 0;
}