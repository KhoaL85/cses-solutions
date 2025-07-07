#include <iostream>

using namespace std;
int n, x, j, m[1000002], Max, res=1, dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        m[x]++;
        Max=max(Max,x);
    }
    for(int i=2;i<=Max;i++)
    {
        dem=0;
        j=i;
        while(j<=Max)
        {
            dem+=m[j];
            j+=i;
        }
        if(dem>=2)
            res=max(res,i);
    }
    cout<<res;
    return 0;
}