#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3,unroll-loops,no-stack-protector")
#include <iostream>
#include <fstream>
#include <string.h>
#include <climits>

using namespace std;

int a, b, dp[502][502];
int dfs(int x, int y)
{
    if(x==y)
        return dp[x][y]=0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y]=0;
    int ans=INT_MAX;
    for(int i=1;i<x;i++)
        ans=min(ans,1+dfs(i,y)+dfs(x-i,y));
    for(int i=1;i<y;i++)
        ans=min(ans,1+dfs(x,i)+dfs(x,y-i));
    return dp[x][y]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));
    cout<<dfs(a, b);
    return 0;
}