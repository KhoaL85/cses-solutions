#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int n, k;
deque<int>val;
long long res, x, a, b, c, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>x>>a>>b>>c;
    val.push_back(x);
    sum=x;
    for(int i=2;i<=k;i++)
    {
        val.push_back((val.back()*a+b)%c);
        sum+=val.back();
    }
    res=sum;
    for(int i=k+1;i<=n;i++)
    {
        val.push_back((val.back()*a+b)%c);
        sum+=val.back();
        sum-=val.front();
        val.pop_front();
        res^=sum;
    }
    cout<<res;
    return 0;
}