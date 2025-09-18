#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n, k, a[200002], cnt[200002], res;
void reCord()
{
    for(int i=1;i<=n;i++)
        cnt[i]=a[i];
    sort(cnt+1,cnt+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(cnt+1,cnt+n+1,a[i])-cnt;
    for(int i=1;i<=n;i++)
        cnt[i]=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    reCord();
    for(int i=1;i<=n;i++)
    {
        res+=(++cnt[a[i]]==1);
        if(i>k)
            res-=(--cnt[a[i-k]]==0);
        if(i>=k)
            cout<<res<<' ';
    }
    return 0;
}