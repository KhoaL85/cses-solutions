#include <iostream>
#include <fstream>
#define se second
#define f first
#include <algorithm>

using namespace std;
int n, res, t;
pair<int,int>a[200002];
bool cmp(pair<int,int> x, pair<int,int> y)
{
    return x.se<y.se;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f>>a[i].se;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        if(a[i].f>=t)
        {
            res++;
            t=a[i].se;
        }
    cout<<res;
    return 0;
}