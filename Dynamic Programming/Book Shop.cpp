#include <iostream>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, x, dp[100002], res;
pair<int,int>a[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i].f;
    for(int i=1;i<=n;i++)
        cin>>a[i].se;
    for(int i=1;i<=n;i++)
        for(int j=x;j>=a[i].f;j--)
            dp[j]=max(dp[j],dp[j-a[i].f]+a[i].se);
    for(int i=1;i<=x;i++)
        res=max(res,dp[i]);
    cout<<res;
    return 0;
}