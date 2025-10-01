#include <iostream>
#include <algorithm>
#include <fstream>
#define f first
#define se second

using namespace std;
const int maxN=2e5+5;

int n, p;
long long bit[maxN], tmp, res;
pair<pair<int,int>,int>a[maxN], e;
void update(int i, long long val)
{
    while(i<=n)
    {
        bit[i]=max(bit[i],val);
        i+=i&-i;
    }
}
long long get(int i)
{
    long long ss=0;
    while(i)
    {
        ss=max(ss,bit[i]);
        i-=i&-i;
    }
    return ss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f.se>>a[i].f.f>>a[i].se;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        e={{a[i].f.se,0},0};
        p=lower_bound(a+1,a+i+1,e)-a-1;
        tmp=get(p)+a[i].se;
        res=max(res,tmp);
        update(i,tmp);
    }
    cout<<res;
    return 0;
}