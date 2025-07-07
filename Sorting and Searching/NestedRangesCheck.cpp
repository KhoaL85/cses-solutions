#include <iostream>
#include <climits>
#include <fstream>
#include <algorithm>
#define f first
#define se second

using namespace std;
int n, d;
bool res[200002];
pair<pair<int,int>,int>a[200002];
bool cmp(pair<pair<int,int>,int> x, pair<pair<int,int>,int> y)
{
    if(x.f.f==y.f.f)
        return x.f.se>y.f.se;
    return x.f.f<y.f.f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f.f>>a[i].f.se;
        a[i].se=i;
    }
    sort(a+1,a+n+1,cmp);
    d=INT_MAX;
    for(int i=n;i>0;i--)
    {
        res[a[i].se]=(a[i].f.se>=d);
        d=min(d,a[i].f.se);
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<' ';
    cout<<'\n';
    d=0;
    for(int i=1;i<=n;i++)
    {
        res[a[i].se]=(a[i].f.se<=d);
        d=max(d,a[i].f.se);
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<' ';
    return 0;
}