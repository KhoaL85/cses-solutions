#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#define f first
#define se second

using namespace std;
int n, t, BLOCK, a[200002], l, r, res[200002], ans, cnt[200002], val[200002];
pair<pair<int,int>,int>q[200002];
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
    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=t;i++)
    {
        cin>>q[i].f.f>>q[i].f.se;
        q[i].se=i;
    }
    reCord();
    BLOCK=sqrt(n);
    sort(q+1,q+t+1,[](auto x, auto y){
        if(x.f.f/BLOCK!=y.f.f/BLOCK)
            return x.f.f<y.f.f;
        return x.f.se<y.f.se;
    });
    l=r=ans=cnt[a[1]]=1;
    for(int i=1;i<=t;i++)
    {
        auto [L,R]=q[i].f;
        while(r<R)
            ans+=(++cnt[a[++r]]==1);
        while(l>L)
            ans+=(++cnt[a[--l]]==1);
        while(r>R)
            ans-=(--cnt[a[r--]]==0);
        while(l<L)
            ans-=(--cnt[a[l++]]==0);
        res[q[i].se]=ans;
    }
    for(int i=1;i<=t;i++)
        cout<<res[i]<<'\n';
    return 0;
}