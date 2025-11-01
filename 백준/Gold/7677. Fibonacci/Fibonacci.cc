#include <iostream>

#define MOD 10000

using namespace std;

long long N;
long long matrix[2][2]={{1,1},{1,0}};
long long ret[2][2]={{1,0},{0,1}};

void MatrixMul(long long a[2][2],long long b[2][2])
{
    long long c[2][2];

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++) c[i][j]+=a[i][k]*b[k][j];
            c[i][j]%=MOD;
        }
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=c[i][j];
}

bool input()
{
    matrix[0][0]=matrix[0][1]=matrix[1][0]=1; matrix[1][1]=0;
    ret[0][0]=ret[1][1]=1; ret[0][1]=ret[1][0]=0;

    cin>>N;
    if(N!=-1) return true;
    else return false;
}

void solve()
{
    while(N>0)
    {
        if(N%2==1) MatrixMul(ret,matrix);
        MatrixMul(matrix,matrix);
        N/=2;
    }
}

void printResult()
{
    cout<<ret[0][1]<<"\n";
}

int main()
{
    while(input())
    {
        solve();
        printResult();
    }

    return 0;
}