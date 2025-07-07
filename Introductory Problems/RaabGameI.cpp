#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int t, a, n, b, i1, i2;
vector<int>p1, p2;
void solve()
{
    cin>>n>>a>>b;
    if(!(a+b))
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<i<<' ';
        cout<<'\n';
        for(int i=1;i<=n;i++)
            cout<<i<<' ';
        cout<<'\n';
        return;
    }
    if(a+b>n||!a||!b)
    {
        cout<<"NO\n";
        return;
    }
    p1.clear();
    p2.clear();
    for(i2=a+1,i1=1;i2<=a+b;i2++,i1++)
    {
        p1.push_back(i1);
        p2.push_back(i2);
    }
    for(i1=b+1,i2=1;i1<=b+a;i1++,i2++)
    {
        p1.push_back(i1);
        p2.push_back(i2);
    }
    for(int i=a+b+1;i<=n;i++)
    {
        p1.push_back(i);
        p2.push_back(i);w
    }
    cout<<"YES\n";
    for(auto x:p1)
        cout<<x<<' ';
    cout<<'\n';
    for(auto x:p2)
        cout<<x<<' ';
    cout<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
        solve();
    return 0;
}