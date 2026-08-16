#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int N=1e6+6;

int n, x, tmp, ans, sz, p[N], cnt[N], f[N];
long long res;
vector<int>val;
void sand(int N)
{
    for(int i=2;i<=N;i++)
        if(!p[i])
            for(int j=i;j<=N;j+=i)
                if(!p[j])
                    p[j]=i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    sand(1000000);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        val.clear();
        while(x>1)
        {
            tmp=p[x];
            val.push_back(p[x]);
            while(x%tmp==0)
                x/=tmp;
        }
        sz=val.size();
        for(int mask=1;mask<(1<<sz);mask++)
        {
            ans=1;
            tmp=0;
            for(int j=0;j<sz;j++)
                if(mask>>j&1)
                {
                    ans*=val[j];
                    tmp++;
                }
            cnt[ans]++;
            f[ans]=tmp;
        }
    }
    for(int d=2;d<=1000000;d++)
    {
        if(!f[d])
            continue;
        if(f[d]&1)
            res+=cnt[d]*1LL*(cnt[d]-1)/2;
        else
            res-=cnt[d]*1LL*(cnt[d]-1)/2;
    }
    cout<<n*1LL*(n-1)/2-res;
    return 0;
}