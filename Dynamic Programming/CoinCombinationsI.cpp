#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int n, x, a[102], m=1000000007;
long long dp[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("CoinCombinationsI.inp", "r")) {
        freopen("CoinCombinationsI.inp", "r", stdin);
        freopen("CoinCombinationsI.out", "w", stdout); }
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    dp[0]=1;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=n&&a[j]<=i;j++)
            dp[i]=(dp[i]+dp[i-a[j]])%m;
    cout<<dp[x];
    cerr<<"\n\nTime "<<(1.0*clock()/CLOCKS_PER_SEC)<<".s\n";
    return 0;
}