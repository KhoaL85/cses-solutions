#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
const int maxN=2e5+5, mod=1e9+7;

int n, a[maxN];
long long bit[maxN], res, tmp;
void update(int i, long long val)
{
    while(i<=n)
    {
        (bit[i]+=val)%=mod;
        i+=i&-i;
    }
}
long long get(int i)
{
    long long ss=0;
    while(i)
    {
        (ss+=bit[i])%=mod;
        i-=i&-i;
    }
    return ss;
}
int val[maxN];
void reCord()
{
    for(int i=1;i<=n;i++)
        val[i]=a[i];
    sort(val+1,val+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(val+1,val+n+1,a[i])-val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    reCord();
    for(int i=n;i;i--)
    {
        tmp=get(n-a[i])+1;
        (res+=tmp)%=mod;
        update(n-a[i]+1,tmp);
    }
    cout<<res;
    return 0;
}