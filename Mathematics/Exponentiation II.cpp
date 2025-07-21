#include <iostream>
#include <fstream>

using namespace std;
const int mod=1000000007;
int n, a, b, c;
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
void solve()
{
    cin>>a>>b>>c;
    cout<<power(a,power(b,c,mod-1),mod)<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--)
        solve();
    return 0;
}