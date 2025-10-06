#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string s, t;
int n, m, dp[5002][5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    s='?'+s;
    t='?'+t;
    for(int i=1;i<=n;i++)
        dp[i][0]=i;
    for(int i=1;i<=m;i++)
        dp[0][i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i]==t[j])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        }
    cout<<dp[n][m];
    return 0;
}