#include <iostream>
#include <fstream>
#include <algorithm>
#define f first
#define se second

using namespace std;
int n, x, y, res, dem;
pair<int,bool>a[400002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=2*n;i+=2)
    {
        cin>>x>>y;
        a[i].f=x;
        a[i+1].f=y;
        a[i+1].se=true;
    }
    sort(a+1,a+2*n+1);
    for(int i=1;i<=2*n;i++)
    {
        if(!a[i].se)
        {
            dem++;
            res=max(res,dem);
        }
        else
            dem--;
    }
    cout<<res;
    return 0;
}