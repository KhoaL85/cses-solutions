#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int N=2e5+5;

int n, child[N], in[N], u, v, comp[N], cnt, p, sz[N], d[N];
int cal(int u)
{
    if(d[u])
        return d[u];
    if(comp[u])
        return d[u]=sz[comp[u]];
    return d[u]=cal(child[u])+1;
}
vector<int>st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>child[i];
        in[child[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i])   
            st.push_back(i);
    while(!st.empty())
    {
        u=st.back();
        st.pop_back();
        if(!(--in[child[u]]))
            st.push_back(child[u]);
    }
    for(int i=1;i<=n;i++)
        if(in[i]&&!comp[i])
        {
            p++;
            cnt=0;
            u=i;
            do
            {
                comp[u]=p;
                u=child[u];
                cnt++;
            } while(u!=i);
            sz[p]=cnt;
        }
    for(int i=1;i<=n;i++)
        cout<<cal(i)<<' ';
    return 0;
}