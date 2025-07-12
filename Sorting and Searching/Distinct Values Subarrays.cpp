#include <iostream>
#include <map>
#include <fstream>

using namespace std;
int n, a[200002], l, r, pre_r;
long long res;
map<int,int>cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cnt[a[1]]++;
    l=r=1;
    while(r<=n)
    {
        r++;
        while(r<=n&&!cnt[a[r]])
            cnt[a[r++]]++;
        res+=(r-l)*1LL*(r-l+1)/2;

        if(pre_r)
            res-=(pre_r-l)*1LL*(pre_r-l+1)/2;
        pre_r=r;

        cnt[a[r]]++;
        while(l<r&&cnt[a[r]]>1)
            cnt[a[l++]]--;
    }
    cout<<res;
    return 0;
}