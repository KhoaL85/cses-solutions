#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int n, a[200002], x;
long long res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    x=a[n/2+1];
    for(int i=1;i<=n;i++)
        res+=abs(x-a[i]);
    cout<<res;
    return 0;
}