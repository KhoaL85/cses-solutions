#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int n, s, p, l, r;
long long a[25], b[25], c[1100000], res;
void gen1(int i, long long sum)
{
    if(i>n/2)
    {
        c[++p]=sum;
        return;
    }
    gen1(i+1,sum+a[i]);
    gen1(i+1,sum);
}
void gen2(int i, long long sum)
{
    if(i>n/2+(n&1))
    {
        l=lower_bound(c+1,c+p+1,s-sum)-c;
        if(!(l>p||c[l]!=s-sum))
        {
            r=upper_bound(c+1,c+p+1,s-sum)-c;
            res+=r-l;
        }
        return;
    }
    
    gen2(i+1,sum+b[i]);
    gen2(i+1,sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n/2;i++)
        cin>>a[i];
    gen1(1,0);
    sort(c+1,c+p+1);
    for(int i=1;i<=n/2+(n&1);i++)
        cin>>b[i];
    gen2(1,0);
    cout<<res;
    return 0;
}