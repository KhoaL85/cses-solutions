#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
int n, a[200002], l[200002], r[200002];
long long res;
stack<int>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        l[i]=0;
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(!s.empty())
            l[i]=s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for(int i=n;i;i--)
    {
        r[i]=n+1;
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(!s.empty())
            r[i]=s.top();
        s.push(i);
    }
    for(int i=1;i<=n;i++)
        res=max(res,a[i]*1LL*(r[i]-l[i]-1));
    cout<<res;
    return 0;
}