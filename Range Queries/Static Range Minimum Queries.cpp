#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int n, q, a[200002], m, l, r, st[18][200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st[0][i]=a[i];
    }
    m=__lg(n);
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    while(q--)
    {
        cin>>l>>r;
        m=__lg(r-l+1);
        cout<<min(st[m][l],st[m][r-(1<<m)+1])<<'\n';
    }
    return 0;
}