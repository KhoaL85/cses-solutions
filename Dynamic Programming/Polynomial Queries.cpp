#include <iostream>
#include <fstream>

using namespace std;
const int maxN=2e5+5;

int n, q, l, r;
long long a[maxN], st[2][4*maxN], lazy[2][4*maxN];
void prop0(int id, int l, int r)
{
    int m=(l+r)/2;
    st[0][2*id]+=lazy[0][id]*(m-l+1);
    st[0][2*id+1]+=lazy[0][id]*(r-m);
    lazy[0][2*id]+=lazy[0][id];
    lazy[0][2*id+1]+=lazy[0][id];
    lazy[0][id]=0;
}
void update(int id, int l, int r, int u, int v, long long val)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        st[0][id]+=val*(r-l+1);
        lazy[0][id]+=val;
        return;
    }
    prop0(id,l,r);
    int m=(l+r)/2;
    update(2*id,l,m,u,v,val);
    update(2*id+1,m+1,r,u,v,val);
    st[0][id]=st[0][2*id]+st[0][2*id+1];
}
long long get(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[0][id];
    prop0(id,l,r);
    int m=(l+r)/2;
    return get(2*id,l,m,u,v)+get(2*id+1,m+1,r,u,v);
}
void prop1(int id, int l, int r)
{
    int m=(l+r)/2;
    st[1][2*id]+=lazy[1][id]*(l+m)*(m-l+1)/2;
    st[1][2*id+1]+=lazy[1][id]*(m+1+r)*(r-m)/2;
    lazy[1][2*id]+=lazy[1][id];
    lazy[1][2*id+1]+=lazy[1][id];
    lazy[1][id]=0;
}
void upd(int id, int l, int r, int u, int v, long long val)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        st[1][id]+=val*(l+r)*(r-l+1)/2;
        lazy[1][id]+=val;
        return;
    }
    prop1(id,l,r);
    int m=(l+r)/2;
    upd(2*id,l,m,u,v,val);
    upd(2*id+1,m+1,r,u,v,val);
    st[1][id]=st[1][2*id]+st[1][2*id+1];
}
long long GET(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[1][id];
    prop1(id,l,r);
    int m=(l+r)/2;
    return GET(2*id,l,m,u,v)+GET(2*id+1,m+1,r,u,v);
}
void update(int l, int r)
{
    update(1,1,n,l,r,1-l);
    upd(1,1,n,l,r,1);
}
long long get(int l, int r)
{
    return a[r]-a[l-1]+get(1,1,n,l,r)+GET(1,1,n,l,r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    while(q--)
    {
        cin>>l;
        if(l==1)
        {
            cin>>l>>r;
            update(l,r);
        }
        else
        {
            cin>>l>>r;
            cout<<get(l,r)<<'\n';
        }
    }
    return 0;
}