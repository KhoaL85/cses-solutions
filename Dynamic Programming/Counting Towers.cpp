#include <iostream>
#include <fstream>

using namespace std;
const int mod=1e9+7;

int n, t;
long long dp[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    dp[1]=2;
    dp[2]=8;
    for(int i=3;i<=1000000;i++)
        dp[i]=((6*dp[i-1]-7*dp[i-2])%mod+mod)%mod;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}