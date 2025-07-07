#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
long long a[200002];
int x, n, res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)
        res+=(binary_search(a+i,a+n+1,a[i-1]+x));
    cout<<res;
    return 0;
}