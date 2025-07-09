#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int mod=1000000007;

int n, x, a[102];
long long dp[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    dp[0]=1;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=n&&a[j]<=i;j++)
            (dp[i]+=dp[i-a[j]])%=mod;
    cout<<dp[x];
    return 0;
}