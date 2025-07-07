#include <iostream>
#include <vector>
#include <fstream>
#define f first
#define se second
#define NAME "cses1735"

using namespace std;
int n, q, a[200005], k, x, y, z;
long long st[1000005];
pair<long long,long long> lazy[1000005];
void build(int id, int l, int r)
{
    if(l==r)
    {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void prop(int id, int l, int r)
{
    int m=(l+r)/2;
    if(lazy[id].f&&lazy[id].se)
    {
        st[2*id]=(m-l+1)*(lazy[id].f+lazy[id].se);
        st[2*id+1]=(r-m)*(lazy[id].f+lazy[id].se);
        lazy[2*id]=lazy[2*id+1]=lazy[id];
        lazy[id]={0,0};
        return;
    }
    if(lazy[id].se)
    {
        st[2*id]=(m-l+1)*lazy[id].se;
        st[2*id+1]=(r-m)*lazy[id].se;
        lazy[2*id]=lazy[2*id+1]={0,lazy[id].se};
        lazy[id]={0,0};
        return;
    }
    if(lazy[id].f)
    {
        st[2*id]+=(m-l+1)*lazy[id].f;
        st[2*id+1]+=(r-m)*lazy[id].f;
        lazy[2*id].f+=lazy[id].f;
        lazy[2*id+1].f+=lazy[id].f;
        lazy[id]={0,0};
    }
}
void update1(int id, int l, int r, int u, int v, int val)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        st[id]+=val*1LL*(r-l+1);
        lazy[id].f+=val;
        return;
    }
    int m=(l+r)/2;
    prop(id,l,r);
    update1(id*2,l,m,u,v,val);
    update1(id*2+1,m+1,r,u,v,val);
    st[id]=st[id*2]+st[id*2+1];
}
void update2(int id, int l, int r, int u, int v, int val)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        st[id]=val*1LL*(r-l+1);
        lazy[id].f=0;
        lazy[id].se=val;
        return;
    }
    int m=(l+r)/2;
    prop(id,l,r);
    update2(id*2,l,m,u,v,val);
    update2(id*2+1,m+1,r,u,v,val);
    st[id]=st[id*2]+st[id*2+1];
}
long long get(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[id];
    prop(id,l,r);
    int m=(l+r)/2;
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout); }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        cin>>k>>x>>y;
        if(k==1||k==2)
        {
            cin>>z;
            if(k==1)
                update1(1,1,n,x,y,z);
            else
                update2(1,1,n,x,y,z);
        }
        else
            cout<<get(1,1,n,x,y)<<'\n';
    }
    return 0;
}