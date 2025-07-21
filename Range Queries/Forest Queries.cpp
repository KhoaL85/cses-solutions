#include <iostream>
#include <fstream>

using namespace std;
const int maxN=1000;

int n, q, a[maxN+2][maxN+2], x1, y1, x2, y2;
char ch;
int get(int x1, int y1, int x2, int y2)
{
    return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>ch;
            a[i][j]=(ch=='*');
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    while(q--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<get(x1,y1,x2,y2)<<'\n';
    }
    return 0;
}