#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef vector<string> sus;
sus gen(int n)
{
    if(n==1)
        return {"0","1"};
    sus pre=gen(n-1);
    sus rev=pre;
    reverse(rev.begin(),rev.end());
    int z=pre.size();
    for(int i=0;i<z;i++)
    {
        string az="0"+pre[i];
        pre[i]="1"+rev[i];
        pre.push_back(az);
    }
    return pre;
}
sus res;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    res=gen(n);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<'\n';
    return 0;
}