#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;
int n, m, low[100002], num[100002], scc, cnt, u, v, t[100002], dem[100002];
bool c[100002], d1[100002], d2[100002];
vector<int>a[100002];
stack<int>st;
void tarzan(int u)
{
    low[u]=num[u]=++cnt;
    c[u]=1;
    st.push(u);
    for(auto v:a[u])
    {
        if(!num[v])
        {
            tarzan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(c[v])
            low[u]=min(low[u],num[v]);
    }
    int v;
    if(low[u]>=num[u])
    {
        scc++;
        do
        {
            v=st.top();
            st.pop();
            c[v]=0;
            t[v]=scc;
            dem[scc]=v;
        } while (u!=v);
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        a[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!num[i])
            tarzan(i);
    for(u=1;u<=n;u++)
        for(auto v:a[u])
            if(t[u]!=t[v])
            {
                d1[t[u]]=1;
                d2[t[v]]=1;
            }
    if(scc==1)
    {
        cout<<"YES";
        return 0;
    }
    for(int i=1;i<=scc;i++)
    {
        if(!d1[i])
        {
            cout<<"NO\n"<<dem[i]<<' '<<(i+1<=scc?dem[i+1]:dem[i-1]);
            return 0;
        }
        if(!d2[i])
        {
            cout<<"NO\n"<<(i+1<=scc?dem[i+1]:dem[i-1])<<' '<<dem[i];
            return 0;
        }
        
    }
    cout<<"YES";
    return 0;
}