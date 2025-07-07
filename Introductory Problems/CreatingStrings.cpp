#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
string s, st[50000];
int z, p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    z=s.size();
    sort(s.begin(),s.end());
    do
    {
        st[++p]=s;
    } while (next_permutation(s.begin(),s.end()));
    {
        st[++p]=s;
    }
    p--;
    cout<<p<<'\n';
    // for(int i=1;i<=p;i++)
    //     cout<<st[i]<<'\n';
    return 0;
}