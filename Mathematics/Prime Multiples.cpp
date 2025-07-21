#include <iostream>
#include <fstream>
#include <numeric>

using namespace std;
int k;
long long n, a[22], res;
void gen(int i, long long LCM, int cnt)
{
    if(i>k)
    {
        res+=(cnt&1?1:-1)*n/LCM;
        return;
    }
    if(LCM<=n/a[i])
        gen(i+1,LCM*a[i],cnt+1);
    gen(i+1,LCM,cnt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cin>>a[i];
    res=n;
    gen(1,1,0);
    cout<<res;
    return 0;
}