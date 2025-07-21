#include <iostream>
#include <fstream>

using namespace std;
const int mod=1000000007;

int n;
long long d[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    d[0]=1;
    d[1]=0;
    for(int i=2;i<=n;i++)
        d[i]=(d[i-1]+d[i-2])*(i-1)%mod;
    cout<<d[n];
    return 0;
}