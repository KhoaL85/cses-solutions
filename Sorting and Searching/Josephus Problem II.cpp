#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;
int n, k, pos=1, sz, a[200002], st[800002];
void build(int id, int l, int r)
{
    if(l==r)
    {
        st[id]=1;
        return;
    }
    int m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
int rm(int id, int l, int r, int x)
{
    st[id]--;
    if(l==r)
        return l;
    int m=(l+r)/2;
    if(x<=st[2*id])
        return rm(2*id,l,m,x);
    return rm(2*id+1,m+1,r,x-st[2*id]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    sz=n;
    build(1,1,n);
    while(sz)
    {
        (pos+=k)%=sz;
        if(!pos)
            pos=sz;
        cout<<rm(1,1,n,pos)<<' ';
        sz--;
    }
    return 0;
}