#include <iostream>
#include <fstream>

using namespace std;
int t;
long long n, d, num, c, x, y;
void solve()
{
    cin>>n;
    d=c=0;
    num=9;
    while(d<n)
    {
        c++;
        d+=num*c;
        num*=10;
    }
    if(d==n)
    {
        cout<<9<<'\n';
        return;
    }
    if(d>n)
    {
        num/=10;
        d-=num*c;
    }

    num/=9;
    x=(n-d)/c+((n-d)%c>0);
    y=num+x-1;
    x=(n-d)%c;
    if(x==0)
        x=c;
    // cout<<num<<' '<<c<<' '<<x<<' '<<y<<'\n';
    while(c>x)
    {
        c--;
        y/=10;
    }
    cout<<y%10<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("DigitQueries.inp", "r")) {
        freopen("DigitQueries.inp", "r", stdin);
        freopen("DigitQueries.out", "w", stdout); }
    cin>>t;
    while(t--)
        solve();
    return 0;
}