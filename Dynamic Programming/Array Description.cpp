#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int mod=1e9+7;

int n, m, a[100002], res, dp[100002][102];
vector<int>val[100002];
bool on[100002][102];
bool check(int x)
{
    return 1<=x&&x<=m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(!a[1])
        for(int i=1;i<=m;i++)
        {
            val[1].push_back(i);
            on[1][i]=1;
            dp[1][i]=1;
        }
    else
    {
        val[1].push_back(a[1]);
        on[1][a[1]]=1;
        dp[1][a[1]]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i])
        {
            for(auto x:{a[i]-1,a[i],a[i]+1})
                if(check(x))
                {
                    val[i].push_back(x);
                    on[i][x]=1;
                    (dp[i][a[i]]+=dp[i-1][x])%=mod;
                }
        }
        else
        {
            for(auto &x:val[i-1])
            {
                if(check(x-1))
                {
                    (dp[i][x-1]+=dp[i-1][x])%=mod;
                    if(!on[i][x-1])
                    {
                        on[i][x-1]=1;
                        val[i].push_back(x-1);
                    }
                }
                if(check(x))
                {
                    (dp[i][x]+=dp[i-1][x])%=mod;
                    if(!on[i][x])
                    {
                        on[i][x]=1;
                        val[i].push_back(x);
                    }
                }
                if(check(x+1))
                {
                    (dp[i][x+1]+=dp[i-1][x])%=mod;
                    if(!on[i][x+1])
                    {
                        on[i][x+1]=1;
                        val[i].push_back(x+1);
                    }
                }
            }
        }
    }

    for(auto &x:val[n])
        (res+=dp[n][x])%=mod;
    cout<<res;
    return 0;
}