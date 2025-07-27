#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
int l=1, r=1000000000, m, res;
string s;
int main()
{
    while(l<r)
    {
        m=(l+r)/2;
        cout<<'?'<<' '<<m<<'\n';
        cout.flush();
        cin>>s;
        if(s=="YES")
            l=m+1;
        else
            r=m;
    }
    cout<<'!'<<' '<<l<<'\n';
    cout.flush();
    return 0;
