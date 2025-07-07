#include <iostream>
#include <map>
#include <fstream>

using namespace std;
map<long long,int>m;
int n, x;
long long a[200002], res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    m[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
        res+=m[a[i]-x];
        m[a[i]]++;
    }
    cout<<res;
    return 0;
}