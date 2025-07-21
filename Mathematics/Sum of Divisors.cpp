#include <iostream>
#include <fstream>

using namespace std;
const int mod=1000000007;

long long n, tmp, i=1, res, sum, q;
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
    cin>>n;
    while(i<=n)
    {
        q=n/i;
        tmp=n/q;
        // sum = (tmp+i)*(tmp-i+1)/2%mod = (tmp+i)*(tmp-i+1)*2^(mod-2)%mod;
        sum = (((tmp+i)%mod) * ((tmp-i+1)%mod)) % mod * power(2,mod-2,mod)%mod;
        (res+=sum*(q%mod)%mod)%=mod;
        i=tmp+1;
    }
    cout<<res;
    return 0;
}