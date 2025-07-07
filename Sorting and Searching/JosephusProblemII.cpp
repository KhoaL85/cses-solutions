#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int n, d, k, p=1;
vector<int>a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        a.push_back(i);
    while(d!=n)
    {
        p+=k;
        p=p%a.size();
        if(p==0)
            p=a.size();
        cout<<a[p-1]<<' ';
        a.erase(a.begin()+p-1);
        d++;
    }
    return 0;
}