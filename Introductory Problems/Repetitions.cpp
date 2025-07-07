#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string s;
int z, res=1, dem=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    s.push_back('?');
    z=s.size();
    for(int i=1;i<z;i++)
    {
        if(s[i]==s[i-1])
            dem++;
        else
        {
            res=max(res,dem);
            dem=1;
        }
    }
    cout<<res;
    return 0;
}