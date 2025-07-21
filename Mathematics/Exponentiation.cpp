#include <iostream>
#include <fstream>

using namespace std;
const int mod=1e9+7;

int n, a, b;
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
    cin>>a>>b;
    cout<<power(a,b,mod)<<'\n';
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