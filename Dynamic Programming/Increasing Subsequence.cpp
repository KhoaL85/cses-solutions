#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int maxN=2e5;

int n, x, b[maxN+2], dp, res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        dp=lower_bound(b+1,b+res+1,x)-b;
        res=max(res,dp);
        b[dp]=x;
    }
    cout<<res;
    return 0;
}