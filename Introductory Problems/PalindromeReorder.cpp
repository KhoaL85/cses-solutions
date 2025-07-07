#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;
string s;
int z, k=-1, c[26], odd;
char ch;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    z=s.size();
    for(int i=0;i<z;i++)
        c[s[i]-'A']++;
    for(int i=0;i<26;i++)
    {
        odd+=(c[i]&1);
        if(odd==2)
        {
            cout<<"NO SOLUTION";
            return 0;
        }
    }
    s="";
    for(int i=0;i<26;i++)
    {
        if(c[i]&1)
        {
            k=i;
            continue;
        }
        ch=char(i+65);
        c[i]>>=1;
        for(int j=1;j<=c[i];j++)
            s.push_back(ch);
    }
    cout<<s;
    reverse(s.begin(),s.end());
    if(k!=-1)
    {
        ch=char(k+65);
        for(int i=1;i<=c[k];i++)
            cout<<ch;
    }
    cout<<s;
    return 0;
}