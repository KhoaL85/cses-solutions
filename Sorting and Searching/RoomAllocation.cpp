#define f first
#define se second
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;
int n, k=1, p=1, res[200002], l, r;
pair<int,int>a[200002];
set<pair<int,int>>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f>>a[i].se;
    sort(a+1,a+n+1);
    s.insert({a[1].se,1});
    res[k]=1;

    //     auto v=s.lower_bound({a[2].f,0});
    //     l=(*v).f;
    //     r=(*v).se;
    // cout<<l<<' '<<r<<'\n';
    // v--;
    // if(l==(*v).f&&r==(*v).se)
    //     cout<<"y\n";

    for(int i=2;i<=n;i++)
    {
        auto v=s.lower_bound({a[i].f,0});
        l=(*v).f;
        r=(*v).se;
        v--;
        if((*v).f>=a[i].f||(l==(*v).f&&r==(*v).se))
        {
            k++;
            res[++p]=k;
            s.insert({a[i].se,k});
            continue;
        }
        res[++p]=(*v).se;
        s.insert({a[i].se,(*v).se});
        s.erase(v);
    }
    cout<<k<<'\n';
    for(int i=1;i<=p;i++)
        cout<<res[i]<<' ';
    return 0;
}