#include <iostream>
#include <fstream>

using namespace std;
const int mod=1000000007;

int n, m;
long long f[2000102];
void init()
{
    f[0]=1;
    for(int i=1;i<=m+n-1;i++)
        f[i]=f[i-1]*i%mod;
}
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    init();
    cout<<f[m+n-1]*power(f[n-1],mod-2,mod)%mod*power(f[m],mod-2,mod)%mod;
    return 0;
}