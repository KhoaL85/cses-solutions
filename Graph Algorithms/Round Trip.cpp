#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<int>a[100002], N, ck;
int n, m, u, v, d, p, tr[100002];
bool c[100002], kt;
void dfs(int u, int z)
{
    for(auto v:a[u])
    {
        if(v==z&&d>1)
        {
            p=u;
            kt=1;
            return;
        }
        if(!c[v])
        {
            tr[v]=u;
            d++;
            c[v]=1;
            // ck.push_back(v);
            dfs(v,z);
            d--;
            if(kt)
                return;
        }
    }
}
void printout(int k)
{
    ck.clear();
    while(p)
    {
        ck.push_back(p);
        p=tr[p];
    }
    cout<<ck.size()+1<<'\n'<<k<<' ';
    for(auto x:ck)
        cout<<x<<' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        if(!c[u])
        {
            N.push_back(u);
            ck.push_back(u);
        }
        if(!c[v])
        {
            N.push_back(v);
            ck.push_back(v);
        }
        c[v]=c[u]=1;
    }
    for(auto x:N)
    {
        for(int j=1;j<=n;j++)
            c[j]=tr[j]=0;
        // ck.clear();
        d=kt=0;
        c[x]=1;
        // ck.push_back(x);
        dfs(x,x);
        if(kt)
        {
            printout(x);
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}