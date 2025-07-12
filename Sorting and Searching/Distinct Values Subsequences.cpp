#include <iostream>
#include <map>
#include <fstream>
#define f first
#define se second

using namespace std;
const int mod=1000000007;

int n, x;
long long res=1;
map<int,int>cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x]++;
    }
    for(auto x:cnt)
        (res*=x.se+1)%=mod;
    cout<<(res+mod-1)%mod;
    return 0;
}