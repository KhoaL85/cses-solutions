#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
typedef vector<bool> hehe;
hehe oc(12, false), o1(25, false), o2(25, false);
string s[10];
int res;
void solve(int row)
{
    if(row==8)
    {
        res++;
        return;
    }
    for(int col=0;col<8;col++)
    {
        if(s[row][col]=='*'||oc[col]||o1[row+col]||o2[row-col+8])
            continue;
        oc[col]=true;
        o1[row+col]=true;
        o2[row-col+8]=true;
        solve(row+1);
        oc[col]=false;
        o1[row+col]=false;
        o2[row-col+8]=false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<8;i++)
        cin>>s[i];
    solve(0);
    cout<<res;
    return 0;
}