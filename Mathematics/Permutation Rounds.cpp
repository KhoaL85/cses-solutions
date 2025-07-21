#include <iostream>
#include <fstream>
#include <numeric>

using namespace std;
const int mod=1e9+7;

int n, p[200002], cnt, u, a[200002], m[200002];
long long res=1;
bool c[200002];
void increase(int x)
{
    for(int i=1;i*i<=x;i++)
        m[i]=0;
    for(int i=2;i*i<=x;i++)
        while(x%i==0)
        {
            x/=i;
            a[i]=max(a[i],++m[i]);
        }
    if(x!=1)
        a[x]=max(a[x],1);
}
void dfs(int x)
{
    c[x]=1;
    cnt=1;
    u=p[x];
    while(u!=x)
    {
        cnt++;
        u=p[u];
        c[u]=1;
    }
    increase(cnt);
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
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        if(!c[p[i]])
            dfs(p[i]);
    for(int i=2;i<=n;i++)
        res=res*power(i,a[i],mod)%mod;
    cout<<res;
    return 0;
}