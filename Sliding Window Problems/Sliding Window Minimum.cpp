#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int n, k, val[10000002];
deque<int>p;
long long res, x, a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>x>>a>>b>>c;
    val[1]=x;
    for(int i=2;i<=n;i++)
        val[i]=(a*val[i-1]+b)%c;
    for(int i=1;i<=n;i++)
    {
        while(!p.empty()&&val[p.back()]>=val[i])
            p.pop_back();
        p.push_back(i);
        if(p.back()-p.front()>=k)
            p.pop_front();
        if(i>=k)
            res^=val[p.front()];
    }
    cout<<res;
    return 0;
}