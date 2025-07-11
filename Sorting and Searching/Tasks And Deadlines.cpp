#include <algorithm>
#include <iostream>
#include <fstream>
#define f first
#define se second

using namespace std;
int n;
long long t, res;
pair<int,int>a[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f>>a[i].se;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        t+=a[i].f;
        res+=a[i].se-t;
    }
    cout<<res;
    return 0;
}