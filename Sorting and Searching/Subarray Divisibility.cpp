#include <iostream>
#include <map>
#include <fstream>

using namespace std;
map<int,int>m;
int n;
long long a, pr, res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    m[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        a+=pr;
        while(a<0)
            a+=n;
        a%=n;
        res+=m[a];
        m[a]++;
        pr=a;
    }
    cout<<res;
    return 0;
}