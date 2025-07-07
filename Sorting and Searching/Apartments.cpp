#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int n, m, k, a[200002], b[200002], res, x, y, i, j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    i=1;
    j=1;
    while(i<=n&&j<=m)
    {
        x=a[i]-k;
        y=a[i]+k;
        if(b[j]<x)
        {
            j++;
            continue;
        }
        if(b[j]>y)
        {
            i++;
            continue;
        }
        res++;
        i++;
        j++;
    }
    cout<<res;
    return 0;
}