#include <iostream>

using namespace std;
int n, a[200005], t[200005], l, m, r, p, z;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t[i]=1e9;
    }
    for(int i=1;i<=n;i++)
    {
        l=1;r=p;z=-1;
        while(l<=r)
        {
            m=(l+r)/2;
            if(t[m]>a[i])
            {
                if(z==-1||t[m]<t[z])
                    z=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        if(z==-1)
            t[++p]=a[i];
        else
            t[z]=a[i];
    }
    cout<<p;
    return 0;
}