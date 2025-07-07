#include <iostream>
#include <fstream>

using namespace std;
int t;
long long x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>y>>x;
        if(y<x)
            cout<<(x-1)*(x-1)+(x&1?2*x-y:y)<<'\n';
        else
            cout<<(y-1)*(y-1)+(y&1?x:2*y-x)<<'\n';
    }
    return 0;
}