#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int n, k;
vector<pair<int,int>>a;
void solve(int n, int l, int m, int r)
{
    if(n==1)
    {
        a.push_back({l,r});
        return;
    }
    solve(n-1,l,r,m);
    a.push_back({l,r});
    solve(n-1,m,l,r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    solve(n,1,2,3);
    k=a.size();
    cout<<k<<' ';
    for(int i=0;i<k;i++)
        cout<<a[i].first<<' '<<a[i].second<<'\n';
    return 0;
}