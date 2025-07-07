#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, dem, M, g=2, a[102], s;
bool  c[100002];
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
    for(int i=1;i<=n;i++)
    {
        if(!c[a[i]])
        {
            p.push_back(a[i]);
            c[a[i]]=true;
            continue;
        }
        for(int j=0;j<p.size();j++)
        {
            s=a[i]+p[j];
            if(!c[s])
                p.push_back(s);
        }
    }
    sort(p.begin(),p.end());
    n=p.size();
    cout<<n<<'\n';
    for(int i=0;i<n;i++)
        cout<<p[i]<<' ';
    return 0;
}