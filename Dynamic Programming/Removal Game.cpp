#include <iostream>
#include <fstream>

using namespace std;

int n, j;
long long a[5002], dp[5002][5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n-k+1;i++)
        {
            j=i+k-1;
            dp[i][j]=a[j]-a[i-1]-min(dp[i+1][j],dp[i][j-1]);
        }
    cout<<dp[1][n];
    return 0;
}