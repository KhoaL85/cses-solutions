#include <iostream>
#include <fstream>

using namespace std;
int n, a, b, mod=1000000007;
long long power(long long a, long long b)
{
    if(b==0)
        return 1;
    long long t=power(a,b/2);
    t=t*t%mod;
    if(b&1)
        return t*a%mod;
    return t;
}
void solve()
{
    cin>>a>>b;
    if(a==0)
    {
        cout<<(b==0)<<'\n';
        return;
    }
    cout<<power(a,b)<<'\n';
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