#include <iostream>
#include <fstream>
#include <climits>

using namespace std;
int t, n, a[200002];
long long l=1, r, m, res, mx;
bool check(long long k)
{
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        s+=k/a[i];
        if(s>=t)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,1LL*a[i]);
    }
    r=mx*max(n,t);
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