#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int t;
long long x, n;
string s;
string conv(long long x)
{
    string st="";
    while(x)
    {
        st.push_back(char(x%10+48));
        x/=10;
    }
    reverse(st.begin(),st.end());
    return st;
}
void solve()
{
    cin>>n;
    s="";
    x=1;
    while(s.size()<n)
    {
        s+=conv(x);
        x++;
    }
    while(s.size()>n)
        s.pop_back();
    cout<<s<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("DigitQueries.inp", "r")) {
        freopen("DigitQueries.inp", "r", stdin);
        freopen("DigitQueries.ans", "w", stdout); }
    cin>>t;
    while(t--)
        solve();
    return 0;
}