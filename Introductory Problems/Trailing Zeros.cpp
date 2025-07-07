#include <iostream>
#include <fstream>

using namespace std;
long long n, res, five;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    five=5;
    while(five<=n)
    {
        res+=n/five;
        five*=5;
    }
    cout<<res;
    return 0;
}