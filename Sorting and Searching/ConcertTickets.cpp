#include <algorithm>
#include <iostream>
#include <fstream>
#define f first
#define se second
#include <vector>
#include <map>

using namespace std;
int n, m, b, x;
map<int,int>a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x]+=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b;
        auto v=a.upper_bound(b);
        if(v==a.begin())
            cout<<"-1\n";
        else
        {
            v--;
            cout<<(*v).f<<'\n';
            (*v).se-=1;
            if((*v).se==0)
                a.erase(v);
        }
    }
    return 0;
}