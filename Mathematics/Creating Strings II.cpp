#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int mod=1e9+7;

string s;
int cnt[26];
long long res, m1[1000002], m2[1000002];
long long power(long long a, long long b, long long mod)
{
    a%=mod;
    long long t=1;
    while(b)
    {
        if(b&1)
            (t*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return t;
}
void init()
{
    m1[0]=1;
    for(int i=1;i<=1000000;i++)
        (m1[i]=m1[i-1]*i)%=mod;
    m2[1000000]=power(m1[1000000],mod-2,mod);
    for(int i=999999;i>=0;i--)
        m2[i]=m2[i+1]*(i+1)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    cin>>s;
    for(auto ch:s)
        cnt[ch-'a']++;
    res=m1[s.size()];
    for(int i=0;i<26;i++)
        (res*=m2[cnt[i]])%=mod;
    cout<<res;
    return 0;
}