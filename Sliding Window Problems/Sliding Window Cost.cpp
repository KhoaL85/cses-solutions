#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;
const int maxN=2e5+5;

int n, k, a[maxN], val[maxN], l, r, m, x, bit[maxN];
long long sum[maxN];
void reCord()
{
    for(int i=1;i<=n;i++)
        val[i]=a[i];
    sort(val+1,val+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(val+1,val+n+1,a[i])-val;
}
void update(int i, int value)
{
    while(i<=n)
    {
        bit[i]+=value;
        i+=i&-i;
    }
}
void upd(int i, int value)
{
    while(i<=n)
    {
        sum[i]+=value;
        i+=i&-i;
    }
}
int get(int i)
{
    int ss=0;
    while(i)
    {
        ss+=bit[i];
        i-=i&-i;
    }
    return ss;
}
long long getSum(int i)
{
    long long ss=0;
    while(i)
    {
        ss+=sum[i];
        i-=i&-i;
    }
    return ss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    reCord();
    for(int i=1;i<=n;i++)
    {
        update(a[i],1);
        upd(a[i],val[a[i]]);
        if(i>=k)
        {
            l=1;
            r=n;
            while(l<=r)
            {
                m=(l+r)/2;
                if((k+1)/2<=get(m))
                {
                    x=m;
                    r=m-1;
                }
                else
                    l=m+1;
            }
            cout<<val[x]*1LL*get(x)-getSum(x)+getSum(n)-getSum(x)-val[x]*1LL*(get(n)-get(x))<<' ';
            update(a[i-k+1],-1);
            upd(a[i-k+1],-val[a[i-k+1]]);
        }
    }
    return 0;
}