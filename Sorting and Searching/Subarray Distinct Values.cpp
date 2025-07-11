#include <iostream>
#include <fstream>
#include <map>

using namespace std;
int n, k, a[200002], dem;
long long res, p=1, x, y, l, r;
map<int,int>m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    l=1;
    r=0;
    while(r<=n)
    {
        while(r<=n&&dem<=k)
        {
            r++;
            if(r<=n)
            {
                m[a[r]]++;
                if(m[a[r]]==1)
                    dem++;
            }
        }
        x=(r-l)*(r-l+1)/2;
        y=(p-l)*(p-l+1)/2;
        res+=x-y;
        p=r;
        while(dem>k)
        {
            m[a[l]]--;
            if(m[a[l]]==0)
                dem--;
            l++;
        }
        if(r>n)
            break;
    }
    cout<<res;
    return 0;
}