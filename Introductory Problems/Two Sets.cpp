#include <iostream>
#include <fstream>
#define f first
#define se second

using namespace std;
int n, p1, p2;
long long sum, s1;
pair<int,int> a[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    sum=1LL*(n+1)*n/2;
    if(sum&1)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    sum>>=1;
    for(int i=n;i>0;i--)
    {
        if(s1+i<=sum)
        {
            s1+=i;
            a[++p1].f=i;
        }
        else
            a[++p2].se=i;
    }
    cout<<p1<<'\n';
    for(int i=p1;i>0;i--)
        cout<<a[i].f<<' ';
    cout<<'\n'<<p2<<'\n';
    for(int i=p2;i>0;i--)
        cout<<a[i].se<<' ';
    return 0;
}