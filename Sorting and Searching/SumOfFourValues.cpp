#include <iostream>
#define f first
#define se second
#include <fstream>
#include <algorithm>

using namespace std;
int n, x, l, r;
long long s, sum;
pair<long long,int>a[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-3&&a[i].f<=x-3;i++)
    {
        for(int j=i+1;j<=n-2;j++)
        {
            if(a[i].f+a[j].f>x-2)
                break;
            l=j+1;
            r=n;
            while(l<r)
            {
                s=a[i].f+a[j].f+a[l].f+a[r].f;
                if(s==x)
                {
                    cout<<a[i].se<<' '<<a[j].se<<' '<<a[l].se<<' '<<a[r].se;
                    return 0;
                }
                if(s>x)
                    r--;
                else
                    l++;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}