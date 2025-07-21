#include <iostream>
#include <fstream>

using namespace std;
int n, q, l, r;
long long a[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    while(q--)
    {
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<'\n';
    }
    return 0;
}