#include <climits>
#include <iostream>
#include <fstream>

using namespace std;
int n, x, a[102], dp[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=x;i++)
        dp[i]=INT_MAX;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=n;j++)
            if(!(a[j]>i||dp[i-a[j]]==INT_MAX))
                dp[i]=min(dp[i],dp[i-a[j]]+1);
    cout<<(dp[x]==INT_MAX?-1:dp[x]);
    return 0;
}