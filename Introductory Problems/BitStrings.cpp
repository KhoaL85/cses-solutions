#include <iostream>
#include <fstream>

using namespace std;
int n, mod=1000000007;
long long binpow(long long a, long long n)
{
    if(n==1)
        return a;
    long long t=binpow(a,n/2);
    t%=mod;
    if(n&1)
        return (t*t%mod*a)%mod;
    return t*t%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cout<<binpow(2,n);
    return 0;
}