#include <iostream>
#include <algorithm>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, x, l, r, m, v;
pair<int,int> a[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        if(x<=a[i].f)
            continue;
        l=i+1;
        r=n;
        v=0;
        while(l<=r)
        {
            m=(l+r)/2;
            if(a[m].f==x-a[i].f)
            {
                v=m;
                break;
            }
            if(a[m].f<=x-a[i].f)
                l=m+1;
            else
                r=m-1;
        }
        if(v!=0)
        {
            cout<<a[i].se<<' '<<a[v].se;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}