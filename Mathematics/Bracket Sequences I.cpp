#include <iostream>
#include <fstream>

using namespace std;
const int mod=1e9+7;

int n;
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
long long f[2000002];
void init(int N)
{
    f[0]=1;
    for(int i=1;i<=N;i++)
        f[i]=f[i-1]*i%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n&1)
        return cout<<0,0;
    n>>=1;
    init(n*2);
    cout<<f[2*n] * power(f[n+1],mod-2,mod)%mod * power(f[n],mod-2,mod)%mod;
    return 0;
}