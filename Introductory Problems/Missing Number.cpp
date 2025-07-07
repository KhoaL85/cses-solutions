#include <iostream>
#include <fstream>

using namespace std;
int n, c[200002], a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        c[a]++;
    }
    for(int i=1;i<=n;i++)
        if(!c[i])
        {
            cout<<i;
            return 0;
        }
    return 0;
}