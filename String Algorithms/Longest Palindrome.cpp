#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int N=1e6+6;

int n, d1[N], d2[N], L=1, R;
string s;
void manacher_odd()
{
    for(int i=1,l=1,r=0;i<=n;i++)
    {
        if(i<=r)
            d1[i]=min(r-i,d1[l+r-i]);
        while(i-d1[i]-1>0&&i+d1[i]+1<=n&&s[i-d1[i]-1]==s[i+d1[i]+1])
            d1[i]++;
        if(i+d1[i]>r)
        {
            l=i-d1[i];
            r=i+d1[i];
        }
    }
}
void manacher_even()
{
    for(int i=1,j,l=1,r=0;i<n;i++)
    {
        j=i+1;
        if(j<=r)
            d2[i]=min(r-j+1,d2[l+r-j]);
        while(i-d2[i]>0&&j+d2[i]<=n&&s[i-d2[i]]==s[j+d2[i]])
            d2[i]++;
        if(i+d2[i]>r)
        {
            l=i-d2[i]+1;
            r=i+d2[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    s='?'+s;
    manacher_odd();
    manacher_even();
    for(int i=1;i<=n;i++)
        if(d1[i]*2+1>R-L+1)
        {
            L=i-d1[i];
            R=i+d1[i];
        }
    for(int i=1;i<n;i++)
        if(d2[i]*2>R-L+1)
        {
            L=i-d2[i]+1;
            R=i+d2[i];
        }
    cout<<s.substr(L,R-L+1);
    return 0;
}