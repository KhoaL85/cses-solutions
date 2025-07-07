#include <iostream>
#include <fstream>
#include <algorithm>
#define f first
#define se second

using namespace std;
int n, x, p;
pair<int,int>a[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)    
    {
        cin>>x;
        while(p>0&&a[p].f>=x)
            p--;
        if(p==0)
            cout<<0;
        else
            cout<<a[p].se;
        cout<<' ';
        a[++p]={x,i};
    }
    return 0;
}
