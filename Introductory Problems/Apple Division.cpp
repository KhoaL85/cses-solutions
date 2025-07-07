#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;
int n;
long long a[23];
long long solve(int pos, long long s1, long long s2)
{
    if(pos>n)
        return abs(s1-s2);
    long long gr1=solve(pos+1,s1+a[pos],s2);
    long long gr2=solve(pos+1,s1,s2+a[pos]);
    return min(gr1,gr2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<solve(1,0,0);
    return 0;
}