#include <iostream>
#include <fstream>

using namespace std;
const int mod=1000000007, maxN=1002;

int n, dp[maxN][maxN];
char a[maxN][maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];

    dp[1][1]=(a[1][1]=='.');

    for(int i=1;i<=n;i++)
        for(int j=1+(i==1);j<=n;j++)
            if(a[i][j]=='.')
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    cout<<dp[n][n];
    return 0;
}