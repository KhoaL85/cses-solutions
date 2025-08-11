#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
const int mod=1e9+7;

int n, m;
long long dp[1002][1026];
void gen(int i, int cur, int mask, vector<int>&nx)
{
    if(i==n)
    {
        nx.push_back(mask);
        return;
    }
    if(i+1<n && ((cur>>i)&1)==0 && ((cur>>(i+1))&1)==0)
        gen(i+2,cur,mask,nx);
    if(((cur>>i)&1)==0)
        gen(i+1,cur,mask|(1<<i),nx);
    if(((cur>>i)&1)==1)
        gen(i+1,cur,mask,nx);
}
long long solve(int i, int mask)
{
    if(i==m)
        return (mask==0);
    if(dp[i][mask]!=-1)
        return dp[i][mask];
    vector<int>nx;
    gen(0,mask,0,nx);
    long long ans=0;
    for(auto x:nx)
        (ans+=solve(i+1,x))%=mod;
    return dp[i][mask]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        for(int mask=0;mask<=1025;mask++)
            dp[i][mask]=-1;
    cout<<solve(0,0);
    return 0;
}