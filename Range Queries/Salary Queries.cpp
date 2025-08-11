#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>

using namespace std;
const int maxN=2e5+3;

int n, q, a[maxN], l, r, bit[4*maxN], val[4*maxN], m;
struct{
    char ch;
    int l, r;
} p[maxN];
void update(int i, int v)
{
    while(i<=m)
    {
        bit[i]+=v;
        i+=i&-i;
    }
}
void reCord()
{
    for(int i=1;i<=n;i++)
        val[i]=a[i];
    m=n;
    for(int i=1;i<=q;i++)
    {
        if(p[i].ch=='?')
            val[++m]=p[i].l;
        val[++m]=p[i].r;
    }
    sort(val+1,val+m+1);
}
int cord(int x)
{
    return lower_bound(val+1,val+m+1,x)-val;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=q;i++)
        cin>>p[i].ch>>p[i].l>>p[i].r;
    reCord();
    for(int i=1;i<=n;i++)
        update(cord(a[i]),1);
    for(int i=1;i<=q;i++)
    {
        l=p[i].l;
        r=p[i].r;
        if(p[i].ch=='!')
        {
            update(cord(a[l]),-1);
            a[l]=r;
            update(cord(a[l]),1);
        }
        else
            cout<<get(cord(r))-get(cord(l)-1)<<'\n';
    }
    return 0;
}