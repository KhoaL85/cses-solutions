#include <iostream>
#include <fstream>

using namespace std;
int n, x, d[1000002];
void sand(int N)
{
    for(int i=2;i*i<=N;i++)
    {
        d[i*i]++;
        for(int j=i*i+i;j<=N;j+=i)
            d[j]+=2;
    }
    for(int i=2;i<=N;i++)
        d[i]+=2;
    d[1]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    sand(1000000);
    cin>>n;
    while(n--)
    {
        cin>>x;
        cout<<d[x]<<'\n';
    }
    return 0;
}