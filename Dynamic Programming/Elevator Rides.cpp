#include <iostream>
#include <fstream>
#define f first
#define se second

using namespace std;

int n, W, a[22], max_mask, nx, sum;
pair<int,long long>dp[1048576+6], tmp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>W;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    max_mask=(1<<n)-1;
    for(int mask=0;mask<=max_mask;mask++)
        dp[mask]={n,W+1};
    dp[0]={0,W+1};
    for(int mask=0;mask<=max_mask;mask++)
        for(int i=0;i<n;i++)
            if(((mask>>i)&1)==0)
            {
                nx=mask|(1<<i);
                if(dp[mask].se+a[i+1]>W)
                    tmp={dp[mask].f+1,a[i+1]};
                else
                    tmp={dp[mask].f,dp[mask].se+a[i+1]};
                if(dp[nx].f>tmp.f||(dp[nx].f==tmp.f&&dp[nx].se>tmp.se))
                    dp[nx]=tmp;
            }
    cout<<dp[max_mask].f;
    return 0;
}