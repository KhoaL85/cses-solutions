#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
#define f first
#define se second

using namespace std;
const int maxN=2e5+5;

int n, k, res;
pair<int,int>a[maxN];
multiset<int>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].f>>a[i].se;
    sort(a+1,a+n+1,[](auto x, auto y){
        return x.se<y.se||(x.se==y.se&&x.f<y.f);
    });
    for(int i=1;i<=k;i++)
        s.insert(0);
    for(int i=1;i<=n;i++)
    {
        auto it=s.upper_bound(a[i].f);
        if(it!=s.begin())
        {
            s.erase(--it);
            s.insert(a[i].se);
            res++;
        }
    }
    cout<<res;
    return 0;
}