#include <iostream>
#include <fstream>

using namespace std;
int n, a, b;
long long res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>a;
    for(int i=2;i<=n;i++)
    {
        cin>>b;
        if(a>b)
            res+=a-b;
        else
            a=b;
    }
    cout<<res;
    return 0;
}