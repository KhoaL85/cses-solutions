#include <iostream>
#include <fstream>

using namespace std;
int n, q, a[200002], u, k;
long long st[800002];
void build(int id, int l, int r)
{
    if(l==r)
    {
        st[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    st[id]=st[2*id]^st[2*id+1];
}
long long get(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[id];
    int m=(l+r)/2;
    return get(2*id,l,m,u,v)^get(2*id+1,m+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        cin>>k>>u;
        cout<<get(1,1,n,k,u)<<'\n';
    }
    return 0;
}