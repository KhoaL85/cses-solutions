#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
char dir[]={'U', 'L', 'D', 'R'};
int type(char ch)
{
    for(int i=0;i<4;i++)
        if(dir[i]==ch)
            return i;
}
string s;
int n, k, res;
void gen(int x, int y, int i)
{
    if(i>n)
    {
        res++;
        return ;
    }
    if(s[i]!='?')
    {
        k=type(s[i]);
        int u=x+dx[k];
        int v=y+dy[k];
        if(1<=u&&u<=7&&1<=v&&v<=7)
            gen(u,v,i+1);
        return;
    }
    for(int d=0;d<4;d++)
    {
        int u=x+dx[d];
        int v=y+dy[d];
        if(1<=u&&u<=7&&1<=v&&v<=7)
            gen(u,v,i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    s='?'+s;
    gen(1,1,1);
    cout<<res;
    return 0;
}