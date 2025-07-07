#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int n, k, a[200002], b[200002], v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i<=k)
            b[i]=a[i];
    }
    sort(b+1,b+k+1);
    cout<<b[(k+1)/2]<<' ';
    for(int i=k+1;i<=n;i++)
    {
        v=lower_bound(b+1,b+k+1,a[i-k])-b;
        b[v]=a[i];
        sort(b+1,b+k+1);
        cout<<b[(k+1)/2]<<' ';
    }
    return 0;
}
