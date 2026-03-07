#include <iostream>
#include <stack>
#include <algorithm>
#include <fstream>

using namespace std;
const int N=2e5+5;

int n, a[N], l[N], r[N], c[N], st[4*N], dp[N], res;
stack<int>s;
void update(int id, int l, int r, int i, int val)
{
    if(l==r)
    {
        st[id]=val;
        return;
    }
    int m=(l+r)/2;
    if(i<=m)
        update(2*id,l,m,i,val);
    else
        update(2*id+1,m+1,r,i,val);
    st[id]=max(st[2*id],st[2*id+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[id];
    int m=(l+r)/2;
    return max(get(2*id,l,m,u,v),get(2*id+1,m+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        c[i]=i;
    sort(c+1,c+n+1,[&](int &i, int &j){
        return a[i]<a[j];
    });
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[s.top()]<a[i])
            s.pop();
        l[i]=(s.empty()?0:s.top());
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for(int i=n;i;i--)
    {
        while(!s.empty()&&a[s.top()]<a[i])
            s.pop();
        r[i]=(s.empty()?n+1:s.top());
        s.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j<=n&&a[c[i]]==a[c[j]])
        {
            dp[c[j]]=get(1,1,n,l[c[j]]+1,r[c[j]]-1)+1;
            j++;
        }
        for(int k=i;k<j;k++)
            update(1,1,n,c[k],dp[c[k]]);
        i=j-1;
    }
    cout<<st[1];
    return 0;
}