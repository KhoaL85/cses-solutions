#include <iostream>
#include <fstream>
#include <algorithm>
#define f first
#define se second

using namespace std;
const int maxN=2e5+2;

struct {
    int l, r, pos;
} range[maxN];
int a[maxN], n, bit[2*maxN], ans[maxN], val[2*maxN];
void update(int i)
{
    while(i<=2*n)
    {
        bit[i]++;
        i+=i&(-i);
    }
}
int get(int i)
{
    int ss=0;
    while(i)
    {
        ss+=bit[i];
        i-=i&(-i);
    }
    return ss;
}
void reCord()
{
    for(int i=1;i<=n;i++)
    {
        val[i]=range[i].l;
        val[i+n]=range[i].r;
    }
    sort(val+1,val+2*n+1);
    for(int i=1;i<=n;i++)
    {
        range[i].l=lower_bound(val+1,val+2*n+1,range[i].l)-val;
        range[i].r=lower_bound(val+1,val+2*n+1,range[i].r)-val;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>range[i].l>>range[i].r;
        range[i].pos=i;
    }
    reCord();
    sort(range+1,range+n+1,[](auto x, auto y){
        return x.l>y.l||(x.l==y.l&&x.r<y.r);
    });
    for(int i=1;i<=n;i++)
    {
        ans[range[i].pos]=get(range[i].r);
        update(range[i].r);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
        bit[i]=bit[i+n]=0;
    }
    cout<<'\n';
    for(int i=n;i;i--)
    {
        ans[range[i].pos]=get(2*n)-get(range[i].r-1);
        update(range[i].r);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}