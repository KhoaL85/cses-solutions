#include <iostream>
#include <fstream>

using namespace std;
const int mod=1e9+7;

int t;
long long a, b, c, m1[1000002], m2[1000002];
long long power(long long a, long long b, long long mod)
{
    a%=mod;
    long long t=1;
    while(b)
    {
        if(b&1)
            (t*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return t;
}
void init()
{
    m1[0]=1;
    for(int i=1;i<=1000000;i++)
        (m1[i]=m1[i-1]*i)%=mod;
    m2[1000000]=power(m1[1000000],mod-2,mod);
    for(int i=999999;i>=0;i--)
        m2[i]=m2[i+1]*(i+1)%mod;
}
void solve()
{
    cin>>a>>b;
    c=a-b;
    cout<<m1[a]*m2[b]%mod*m2[c]%mod<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    cin>>t;
    while(t--)
        solve();
    return 0;
}