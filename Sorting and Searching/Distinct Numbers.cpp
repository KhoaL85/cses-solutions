#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int n, a[200002], res=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        res+=(a[i]!=a[i-1]);
    cout<<res;
    return 0;
}