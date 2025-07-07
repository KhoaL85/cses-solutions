#include <iostream>
#include <fstream>

using namespace std;
int m=1000000007;
long long dp[1000002];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=6&&j<=i;j++)
            dp[i]=(dp[i]+dp[i-j])%m;
    cout<<dp[n];
    return 0;
}