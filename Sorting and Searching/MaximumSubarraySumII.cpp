#include <iostream>
#include <climits>
#include <fstream>

using namespace std;
long long st[800002], a[200002], res=LLONG_MIN;
int n, l, r;
void build(int id, int l, int r)
{
    if(l==r)
    {
        st[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    st[id]=max(st[id*2],st[id*2+1]);
}
long long get(int id, int l, int r, int u, int v)
{
    if(l>v||u>r)
        return LLONG_MIN;
    if(u<=l&&r<=v)
        return st[id];
    int m=(l+r)/2;
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>l>>r;
    for(int i=1;i<=n;++i) 
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    build(1,1,n);
    r=min(r,n);
    for(int i=1;i<=n-l+1;i++)
        res=max(res,get(1,1,n,i+l-1,min(i+r-1,n))-a[i-1]);
    cout<<res;
    return 0;
}