#include <iostream>
#include <fstream>

using namespace std;
int const maxN=2e5;

int n, q, l, r, x;
long long st[4*maxN+10], a[maxN+12];
void update(int id, int l, int r, int i, int v)
{
    if(l==r)
    {
        st[id]+=v;
        return;
    }
    int m=(l+r)/2;
    if(i<=m)
        update(2*id,l,m,i,v);
    else
        update(2*id+1,m+1,r,i,v);
    st[id]=st[2*id]+st[2*id+1];
}
long long get(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[id];
    int m=(l+r)/2;
    return get(2*id,l,m,u,v)+get(2*id+1,m+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>l>>r>>x;
            update(1,1,n,l,x);
            if(r<n)
                update(1,1,n,r+1,-x);
        }
        else
        {
            cin>>x;
            cout<<a[x]+get(1,1,n,1,x)<<'\n';
        }
    }
    return 0;
}