#include <iostream>
#include <climits>
#include <fstream>

using namespace std;
int n;
long long f[200002], d[200002], res=LLONG_MIN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        f[i]+=f[i-1];
        d[i]=min(d[i-1],f[i]);
    }
    for(int i=n;i>0;i--)
        res=max(res,f[i]-d[i-1]);
    cout<<res;    
    return 0;
}