#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
const int maxN=2e5+2;

int n, k, a[maxN], val[maxN], bit[2][maxN];
long long res;
void reCord()
{
    for(int i=1;i<=n;i++)
        val[i]=a[i];
    sort(val+1,val+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(val+1,val+n+1,a[i])-val;
}
void update(int id, int i, int val)
{
    while(i<=n)
    {
        bit[id][i]+=val;
        i+=i&-i;
    }
}
int get(int id, int i)
{
    int ss=0;
    while(i)
    {
        ss+=bit[id][i];
        i-=i&-i;
    }
    return ss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    reCord();
    for(int i=1;i<=n;i++)
    {
        res+=get(1,n-a[i]);
        update(0,a[i],1);
        update(1,n-a[i]+1,1);
        if(i>=k)
        {
            cout<<res<<' ';
            res-=get(0,a[i-k+1]-1);
            update(0,a[i-k+1],-1);
            update(1,n-a[i-k+1]+1,-1);
        }
    }
    return 0;
}