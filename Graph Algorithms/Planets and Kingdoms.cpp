#include <queue>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
const int maxN=1e5+2;

int n, m, u, v, low[maxN], num[maxN], cnt, scc, t[maxN];
bool c[maxN];
queue<int>q;
stack<int>st;
vector<int>g[maxN];
void tarzan(int u)
{
    num[u]=low[u]=++cnt;
    c[u]=1;
    st.push(u);
    for(auto v:g[u])
    {
        if(!num[v])
        {
            tarzan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(c[v])
            low[u]=min(low[u],num[v]);
    }
    if(low[u]>=num[u])
    {
        scc++;
        do
        {
            v=st.top();
            c[v]=0;
            t[v]=scc;
            st.pop();
        } while(u!=v);
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
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!num[i])
            tarzan(i);
    cout<<scc<<'\n';
    for(int i=1;i<=n;i++)
        cout<<t[i]<<' ';
    return 0;
}