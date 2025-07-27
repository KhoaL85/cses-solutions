#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
const int maxN=1e6+2;
 
string s, t;
int n, ans, pi[2*maxN], j, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t>>s;
    m=s.size();
    s=s+'#'+t;
    n=s.size();
    for(int i=1;i<n;i++)
    {
        int j = pi[i - 1];
        while(j>0&&s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
        ans+=(j==m);
    }
    cout<<ans;
    return 0;
}
