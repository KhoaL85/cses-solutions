#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int n, a[200002];
long long res=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>res)
        {
            cout<<res;
            return 0;
        }
        res+=a[i];
    }
    cout<<res;
    return 0;
}