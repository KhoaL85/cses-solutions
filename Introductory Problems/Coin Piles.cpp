#include <iostream>
#include <fstream>

using namespace std;
int a, b, t, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        y=2*a-b;
        x=2*b-a;
        cout<<((x<0||y<0||x%3||y%3)?"NO\n":"YES\n");
    }
    return 0;
}