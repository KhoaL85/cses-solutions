#include <iostream>
#include <algorithm>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, x, l, r;
long long s;
pair<int,int>a[5002];
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
    for(int i=1;i<=n-2;i++)
    {
        l=i+1;
        r=n;
        while(l<r)
        {
            s=a[i].f+a[l].f+a[r].f;
            if(s==x)
            {
                cout<<a[i].se<<' '<<a[l].se<<' '<<a[r].se;
                return 0;
            }
            if(s>x)
                r--;
            else
                l++;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}