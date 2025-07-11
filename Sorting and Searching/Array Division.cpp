#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int n, k, a[200002];
long long res, l, r, m;
bool check(long long x)
{
    long long s=0;
    int dem=1;
    for(int i=1;i<=n;i++)
    {
        if(s+a[i]<=x)
            s+=a[i];
        else
        {
            s=a[i];
            dem++;
            if(dem>k)
                return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l=max(l,1LL*a[i]);
        r+=a[i];
    }
    while(l<=r)
    {
        m=(l+r)/2;
        if(check(m))
        {
            res=m;
            r=m-1;
        }
        else
            l=m+1;
    }
    cout<<res;
    return 0;
}