#include <iostream>
#include <queue>
#include <fstream>
#define f first
#define se second

using namespace std;
const int maxN=1e3+3;

int n, m, a[maxN], b[maxN], res, dp[maxN][maxN], i, j;
pair<int,int>tr[maxN][maxN];
vector<int>ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    cout<<dp[n][m]<<'\n';
    i=n;
    j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<' ';
    return 0;
}