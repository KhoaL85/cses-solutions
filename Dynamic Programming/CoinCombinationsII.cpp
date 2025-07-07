#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int n, a[102], m=1000000007, x;
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
    for(int i=1;i<=n;i++)
        for(int j=a[i];j<=x;j++)
            dp[j]=(dp[j]+dp[j-a[i]])%m;
    cout<<dp[x];
    return 0;
}