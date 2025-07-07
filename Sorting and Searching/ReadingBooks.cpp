#include <iostream>
#include <fstream>

using namespace std;
int n, a[200002], m;
long long s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
        m=max(m,a[i]);
    }
    if(s-m<=m)
        cout<<m*2;
    else
        cout<<s;
    return 0;
}