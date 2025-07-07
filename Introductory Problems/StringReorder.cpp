#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int c[26], n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    for(auto ch:s)
        c[ch-'A']++;
    s="";
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
            if(c[j]&&(i==1||j!=(s.back()-'A')))
            {
                c[j]--;
                s.push_back(char(j+'A'));
                break;
            }
        cout<<s<<'\n';
        if(s.size()!=i)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<s;
    return 0;
}