#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int n, x, a[200005], res, d=2, i, j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    i=1;
    j=n;
    while(i<=j)
    {
        if(a[i]+a[j]<=x)
        {
            res++;
            i++;
            j--;
        }
        else
        {
            res++;
            j--;
        }
    }
    cout<<res;
    return 0;
}