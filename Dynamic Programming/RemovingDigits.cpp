#include <iostream>

using namespace std;
int big(int x)
{
    int ss=0;
    while(x>0)
    {
        ss=max(ss,x%10);
        x/=10;
    }
    return ss;
}
int n, dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    while(n!=0)
    {
        n-=big(n);
        dem++;
    }
    cout<<dem;
    return 0;
}
