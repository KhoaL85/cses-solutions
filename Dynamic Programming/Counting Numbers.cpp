#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

long long dp[20][10][2][2];
string L, R;
bool check(string s)
{
    for(int i=1;i<s.size();i++)
        if(s[i]==s[i-1])
            return 0;
    return 1;
}
long long dfs(int i, int last, int ok, int isNum, string &R)
{
    if(i==R.size())
        return isNum;
    long long &d=dp[i][last][ok][isNum];
    if(d!=-1)
        return d;
    d=0;
    int high=(ok?9:R[i]-48);
    for(int c=0;c<=high;c++)
    {
        if(isNum&&c==last)
            continue;
        d+=dfs(i+1,c,ok|(c<high),isNum|(c>0),R);
    }
    return d;
}
long long cal(string R)
{
    memset(dp,-1,sizeof(dp));
    return dfs(0,0,0,0,R);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>L>>R;
    if(L=="0")
    {
        if(R=="0")
            return cout<<1, 0;
        return cout<<cal(R)+1, 0;
    }
    cout<<cal(R)-cal(L)+check(L);
    return 0;
}