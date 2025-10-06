#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;
const int mod=1e9+7, OS=125250;

int n, dp[OS+3], tmp, res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n*(n+1)%4)
        return cout<<0, 0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=n*(n+1)/2;j>=i;j--)
            (dp[j]+=dp[j-i])%=mod;
    cout<<dp[n*(n+1)/4]*500000004LL%mod;
    return 0;
}