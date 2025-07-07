#include <iostream>
#include <fstream>
#include <map>

using namespace std;
int n, l=1, x, res;
map<int,int>m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(l<=m[x])
            l=m[x]+1;
        m[x]=i;
        res=max(res,i-l+1);
    }
    cout<<res;
    return 0;
}