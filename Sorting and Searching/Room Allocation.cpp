#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, cnt, res[200002], p;
pair<pair<int,int>,int>a[200002];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f.f>>a[i].f.se;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&q.top().f<a[i].f.f)
        {
            auto [dp,p]=q.top();
            q.pop();
            res[a[i].se]=p;
            q.push({a[i].f.se,p});
        }
        else
        {
            res[a[i].se]=++cnt;
            q.push({a[i].f.se,cnt});
        }
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++)
        cout<<res[i]<<' ';
    return 0;
}