#include <iostream>
#include <fstream>
#include <queue>
#define f first
#define se second

using namespace std;
const int maxN=100002, mod=1e9+7;

long long n, p, m, cnt, sum, product, cnt2;
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
    cnt=cnt2=sum=product=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p>>m;
        (cnt*=(m+1))%=mod;

        (
            sum = sum * ((power(p,m+1,mod)-1+mod)%mod) % mod * power(p-1,mod-2,mod)
        )%=mod;
        /// sum[i] = sum[i-1] * (p[i]^(m[i]+1)-1) / (p[i]-1)

        (
            product = power(product,m+1,mod) * power(power(p,m*(m+1)/2,mod),cnt2,mod)
        )%=mod;
        /// product[i] = product[i-1]^(m[i]+1) * ( p[i]^(m[i]*(m[i]+1)/2) )^cnt[i-1]

        (cnt2*=(m+1))%=mod-1; /// cnt2=cnt%(mod-1)
    }
    cout<<cnt<<' '<<sum<<' '<<product;
    return 0;
}