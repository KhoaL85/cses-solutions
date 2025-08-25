#include <iostream>
#include <fstream>

using namespace std;
const int mod=1e9+7;

long long n;
struct matrix
{
    long long val[3][3];
};
matrix C, A, T, I;
inline matrix operator* (matrix A, matrix B)
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            C.val[i][j]=0;
            for(int k=1;k<=2;k++)
                C.val[i][j]=(C.val[i][j]+A.val[i][k]*1LL*B.val[k][j])%mod;
        }
    return C;
}
inline matrix power(matrix &A, long long b)
{
    if(b==0)
        return I;
    T=power(A,b/2);
    T=T*T;
    if(b&1)
        T=T*A;
    return T;
}
void solve()
{
    cin>>n;
    if(n<=1)
    {
        cout<<n;
        return;
    }
    A=power(A,n);
    cout<<A.val[2][1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=2;i++)
        I.val[i][i]=1;
    A.val[1][1]=A.val[1][2]=A.val[2][1]=1;
    solve();
    return 0;
}