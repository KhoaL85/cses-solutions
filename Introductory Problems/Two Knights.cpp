#include <iostream>
#include <fstream>

using namespace std;
long long n, z;
long long solve(long long k)
{
    z=k*k;
    return z*(z-1)/2-(k-1)*(k-2)*4;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<solve(i)<<'\n';
    return 0;
}
