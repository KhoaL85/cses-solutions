#include <iostream>

using namespace std;
bool d[200002];
int res, x, n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        res+=(d[x-1]==false);
        d[x]=true;
    }
    cout<<res;
    return 0;
}