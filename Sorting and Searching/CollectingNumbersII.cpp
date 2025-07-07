#include <iostream>
#include <fstream>

using namespace std;
int n, m, x, p[200002], a, b, res, v[200002];
bool c1, c2, c3, c4;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("CollectingNumbersII.inp", "r")) {
        freopen("CollectingNumbersII.inp", "r", stdin);
        freopen("CollectingNumbersII.out", "w", stdout); }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        p[v[i]]=i;
        res+=(!p[v[i]-1]);
    }
    cout<<res<<'\n';
    while(m--)
    {
        cin>>a>>b;

        c1=p[v[a]-1]<p[v[a]];
        c2=p[v[a]]<p[v[a]+1];
        c3=p[v[b]-1]<p[v[b]];
        c4=p[v[b]]<p[v[b]+1];

        p[v[a]]=b;
        p[v[b]]=a;
        swap(v[a],v[b]);

        if(abs(v[a]-v[b])==1)
        {
            if(v[a]<v[b])
            {
                res--;
            }
            else
            {
                res++;
            }
        }

        res=res
        +   (c3&&p[v[a]-1]>p[v[a]])
        +   (c4&&p[v[a]]>p[v[a]+1])
        +   (c1&&p[v[b]-1]>p[v[b]])
        +   (c2&&p[v[b]]>p[v[b]+1])
        -   (!c3&&p[v[a]-1]<p[v[a]])
        -   (!c4&&p[v[a]]<p[v[a]+1])
        -   (!c1&&p[v[b]-1]<p[v[b]])
        -   (!c2&&p[v[b]]<p[v[b]+1]);
        
        cout<<res<<'\n';
        cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<'\n';
    }
    return 0;
}