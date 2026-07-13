#include <iostream>
#include <vector>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, k;
vector<pair<int,int>>a;
void solve(int n, int l, int r, int m)
{
    if(n==1)
    {
        a.push_back({l,r});
        return;
    }
    solve(n-1,l,m,r);
    a.push_back({l,r});
    solve(n-1,m,r,l);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    solve(n,1,3,2);
    cout<<a.size();
    for(auto &x:a)
        cout<<'\n'<<x.f<<' '<<x.se;
    return 0;
}