#include <iostream>
#include <fstream>

using namespace std;
int n, d, m;
bool c[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;d!=n;i++)
    {
        if(c[i])
        {
            if(i==n)
                i=0;
            continue;
        }
        m++;
        if(m==2)
        {
            m=0;
            cout<<i<<' ';
            c[i]=true;
            d++;
        }
        if(i==n)
            i=0;
    }
    return 0;
}