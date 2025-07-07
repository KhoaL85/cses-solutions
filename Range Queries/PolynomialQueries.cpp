#include <iostream>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, q, a[200002], k, x, y;
long long st[800002];
pair<pair<long long,long long>,long long>lazy[800002];
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
    st[id]=st[id*2]+st[id*2+1];
}
void prop(int id, int l, int r)
{
    if(lazy[id].se==0)
        return;
    int m=(l+r)/2;
    long long p1=lazy[id].f.f, p2=p1+(m-l)*lazy[id].se, p3=p2+lazy[id].se, p4=lazy[id].f.se;
    cout<<l<<' '<<r<<' '<<lazy[id].f.f<<' '<<lazy[id].f.se<<' '<<lazy[id].se<<'\n';

    st[2*id]+=(p2+p1)*((p2-p1)/lazy[id].se+1)/2;
    st[2*id+1]+=(p4+p3)*((p4-p3)/lazy[id].se+1)/2;
    
    lazy[2*id].f.f+=lazy[id].f.f;
    lazy[2*id].f.se+=lazy[id].f.se;
    lazy[2*id].se+=lazy[id].se;

    lazy[2*id+1].f.f+=lazy[id].f.f;
    lazy[2*id+1].f.se+=lazy[id].f.se;
    lazy[2*id+1].se+=lazy[id].se;

    lazy[id]={{0,0},0};
}
void update(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        int p1=l-u+1;
        int p2=r-u+1;
        st[id]+=(p2+p1)*1LL*(p2-p1+1)/2;
        lazy[id].f.f+=p1;
        lazy[id].f.se+=p2;
        lazy[id].se++;
        return;
    }
    prop(id,l,r);
    int m=(l+r)/2;
    update(id*2,l,m,u,v);
    update(id*2+1,m+1,r,u,v);
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
    if(fopen("cses1736.inp", "r")) {
        freopen("cses1736.inp", "r", stdin);
        freopen("cses1736.out", "w", stdout); }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        cin>>k>>x>>y;
        if(k==1)
            cout<<"---\n", update(1,1,n,x,y);
        else
            cout<<get(1,1,n,x,y)<<'\n';
    }
    return 0;
}