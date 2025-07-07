#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, M, c[100002], g=2, a[102];
vector<int> p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        M+=a[i];
    }
    for(int i=1;i<=n;i++,g++)
        for(int j=0;j+a[i]<=M;j++)
            if(c[j]>0&&c[j]<g&&c[j+a[i]]==0)
            {
                p.push_back(j+a[i]);
                c[j+a[i]]=g;
            }
    sort(p.begin(),p.end());
    cout<<p.size()<<'\n';
    for(int i=0;i<p.size();i++)
        cout<<p[i]<<' ';
    return 0;
}